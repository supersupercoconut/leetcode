#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
    ThreadPool(size_t);

    // template<class F, class... Args> 对应的是一种函数类型的表示方式, F实际上可以接受一些 lambda/函数指针, 后续的class... Args对应函数需要的参数(这里是省略表示)
    // 后续即可以使用 enqueue调用一个lambda函数了，其返回值就自动推导出来(auto) | auto -> 的结合使用对应着 尾置返回类型
    // 这个 enqueue 函数最终返回一个 std::future<T>，而这个 T 是 F(args...) 的返回值类型
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

    ~ThreadPool();
private:
    // need to keep track of threads so we can join them
    std::vector< std::thread > workers;
    // the task queue
    std::queue< std::function<void()> > tasks;

    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
        :   stop(false)
{
    // 这里应该是对于每一个线程都在执行循环，不断地读取tasks来执行(更像是一个生产者-消费者模型, 但是有多个消费者，只有一个生产者, 所以需要利用互斥锁+条件变量 实现互斥+同步)
    for(size_t i = 0;i<threads;++i)
        workers.emplace_back(
                [this]
                {
                    // note 这里是一个死循环, 等待enqueue中将数据放入tasks中等待处理数据
                    for(;;)
                    {
                        std::function<void()> task;

                        {
                            std::unique_lock<std::mutex> lock(this->queue_mutex);
                            this->condition.wait(lock,
                                                 [this]{ return this->stop || !this->tasks.empty(); });
                            if(this->stop && this->tasks.empty())
                                return;

                            // 将task()读取出来后执行
                            task = std::move(this->tasks.front());
                            this->tasks.pop();
                        }

                        task();
                    }
                }
        );
}

// add new work item to the pool
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
-> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    // res可以在后续使用res.get()来获取到这个线程最后的执行结果
    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        // don't allow enqueueing after stopping the pool
        if(stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        // 给tasks队列补充任务(应该是直接使用类似的操作)
        tasks.emplace([task](){ (*task)(); });
    }
    condition.notify_one();
    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for(std::thread &worker: workers)
        worker.join();
}

#endif