#include <iostream>
#include <vector>
#include <chrono>
#include <future>
#include <thread>
#include <queue>
#include <mutex>
#include <functional>

class threadPool
{
private:
    std::vector<std::thread> workers;
    std::deque<std::function<void()>> tasks;
    std::mutex m_mutex;
    // note 条件变量的作用在于可以避免轮询查询, 对于不满足条件的线程可以让其进入阻塞阶段 | 不使用条件变量, worker线程都需要抢占锁之后, 判断tasks是否为空即成为一种轮询等待的操作，耗费资源
    std::condition_variable m_cv;
    bool stop;

public:
    // 只提供接口方便给任务队列放数据
    inline threadPool(int n) : stop(false)
    {
        // lambda表达式默认不会捕获this指针, 必须要进行显式捕获 —— 捕获得到的this指针(后续函数如果改变类的数据, 利用该this指针可以很快进行改变数据)
        for(int i = 0; i < n; ++i)
        {
            workers.emplace_back(
                [this](){
                    while(true)
                    {
                        std::function<void()> task;
                        {
                            // note 1. 首先在该工作线程中就需要抢占锁, 获取不到就需要阻塞等待锁的获取
                            std::unique_lock<std::mutex> lock(this->m_mutex);
                            // note 2. 对于互斥锁而言, 当一个锁被一个线程占用的时候, 其余需要这个锁的线程都会等待这个锁的释放 (与条件变量无关, 这个估计是锁的实现方式中会保留这些需要使用锁的线程, 上一个释放之后, 其余线程会竞争这个锁)
                            // note 3. wait在被notify()之后要先抢占锁，如果拿不到锁就一直等待获取锁, 如果抢占到锁之后判断谓词部分是否成立(即后面的条件) (1) 不成立, 进入阻塞，并释放锁资源 —— 后续需要等待其他线程的notify_all()或者notify_one()唤醒后，再获取锁再判断条件是否成立，成立则恢复锁的使用并且继续执行 (2) 成立, 不阻塞直接执行后续逻辑
                            // 等待唤醒 —— 析构时会将线程池如果当前任务队列为空, 就手动调用stop来让每一个线程执行到return部分
                            m_cv.wait(lock,[this](){
                                    return this->stop || !this->tasks.empty();
                                });

                            // 任务队列为空但线程不停止工作会继续循环
                            if(tasks.empty() && this->stop)
                                return;

                            task = this->tasks.front();
                            tasks.pop_front();
                        }
                        task();
                    }
                }
            );
        }
    }

    // note 该函数接受一个函数对象以及其对应的参数，并且将其打包给线程池使用 | tasks工作队列中指定类型为function<void()>类型，说明放入tasks的应该是无参数函数(这里是使用lambda表示)
    template<typename Func, typename ...Args>
    auto commit(Func&& f, Args&&...args) -> std::future<typename std::result_of<Func(Args...)>::type>
    {
        using  result_type = typename std::result_of<Func(Args...)>::type;

        // 创建一个task对象 | std::packaged_task 把一个可调用对象包装起来，以便可以异步执行(给定的参数类型是一个function对象), get_future也只是一个占位符(表示这个函数的返回值, 但是未知其什么时候会被执行完毕)，其实际执行是work线程调用task()的时候 | 可以使用get()让其必须执行完毕获取到结果之后才能执行后续内容
        auto task = std::make_shared< std::packaged_task<result_type()> > (
            std::bind(std::forward<Func>(f) , std::forward<Args>(args)...)  // 后续可以无参数执行函数, bind打包函数以及行惨
        );

        // note 为什么要返回res: 因为get_future()是生成一个future<result_type()>的结果, 目前只是一个占位符, 当函数执行完之后(在工作队列中执行), 结果就给到了这个对象中, 那么commit函数就可以返回被调用函数的结果
        auto res = task->get_future();
        // 限制锁作用域
        {
            std::unique_lock<std::mutex> lock(m_mutex);

            // 停止后禁止向线程池中补充内容
            if(stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");

            // 任务队列中直接保留task，方便后续直接按无参数类型直接调用
            tasks.emplace_back( [task](){(*task)();} );
        }
        m_cv.notify_one();
        return res;
    }

    inline ~threadPool()
    {
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            stop = true;
        }

        // note 这里所有在wait的所有阻塞线程都会被唤醒, 目前不在wait的线程结束完任务执行之后也不会在wait出阻塞
        m_cv.notify_all();
        for(auto& t : workers)
            t.join();
    }
};


int main()
{
    threadPool pool(4);
    // 简单使用: 生成一个调用对象然后放入线程池, 最后使用get()读取线程池对象
    // auto result = pool.commit([](int answer) { return answer; }, 42);
    // get result from future
    // std::cout << result.get();

    std::vector< std::future<int> > results;
    for(int i = 0; i < 10; ++i)
    {
        results.emplace_back(pool.commit(
            [i]()
            {
                std::cout << i << ": completed" << std::endl;
                return i;
            }));
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << results[i].get() << std::endl;
    }

    return 0;
}










//int main()
//{
//
////    ThreadPool pool(4);
////    std::vector< std::future<int> > results;
////
////    for(int i = 0; i < 8; ++i) {
////        results.emplace_back(
////                pool.enqueue([i] {
////                    std::cout << "hello " << i << std::endl;
////                    std::this_thread::sleep_for(std::chrono::seconds(1));
////                    std::cout << "world " << i << std::endl;
////                    return i*i;
////                })
////        );
////    }
////
////    for(auto && result: results)
////        std::cout << result.get() << ' ';
////    std::cout << std::endl;
//
//    system("pause");
//    return 0;
//}