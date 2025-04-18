#include <iostream>
#include <vector>
#include <chrono>
#include <future>
#include <thread>
#include <queue>
#include <mutex>

//#include "ThreadPool.h"



//// 尝试复现线程池逻辑 | 单一任务队列 + 维持线程数量 + 互斥锁以及条件变量来保证互斥以及同步 + 任务队列的返回值是什么
//
class threadPool
{
private:
    std::vector<std::thread> workers;
    std::deque<std::function<void()>> tasks;
    std::mutex m_mutex;
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
                        std::unique_lock<std::mutex> lock(this->m_mutex);
                        // 等待唤醒 —— 析构时会将线程池如果当前任务队列为空, 就手动调用stop来让每一个线程执行到return部分
                        m_cv.wait(lock,[this](){
                                return this->stop || !this->tasks.empty();
                            });

                        // 任务队列个人为空不会退出
                        if(tasks.empty() && this->stop)
                            return;

                        // 如何获取tasks数据并进行执行
                        std::function<void()> task;
                        task = this->tasks.front();
                        tasks.pop_front();
                        task();
                    }
                }
            );
        }
    }

    // 放入数据 —— 其会直接将数据导入到tasks()队列中, 放入的应该是一个函数, 并且其返回值以及其对应的参数列表应该是任意的
    template<typename Func, typename ...Args>
    auto commit(Func&& f, Args&&...args)
    {
//        auto task = std::forward<Func>(f)(std::forward<Args>(args)...);
        tasks.
    }

    inline void commit_task()
    {
        // note std::deque<std::function<void()>> tasks; 由于这里直接给定的是 function<void()> 说明其对应的是一种无参数的函数
            // 但是考虑到通用性, 给任务队列输入的参数应该是任意类型的, 这主要是利用lambda()表达式 直接通过捕获列表的方式来进行参数传递 类似于tasks.emplace([](){/* 这里调用的应该使用的函数 */});

    }

};



//int slow_add(int a, int b)
//{
//    this_thread::sleep_for(chrono::seconds(2));
//    return a+b;
//}




int main()
{
//    future<int> tmp = async(slow_add, 1, 2);
//    cout << tmp.get() << endl;
    system("pause");
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