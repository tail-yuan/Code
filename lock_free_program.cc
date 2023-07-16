//展示了无锁编程的概念。
//该示例使用原子操作来实现一个简单的计数器，多个线程可以同时对计数器进行递增操作。

//所谓的无锁编程就是想问你有哪些方式可以实现并发场景下的原子操作,不让用锁,
//就用Linux系统提供的原子类型atomic_t C++标准库提供了一些原子操作的类型和函数，如std::atomic，可以用于对静态变量进行原子操作。
//使用线程安全的数据结构：考虑使用线程安全的数据结构来替代直接操作静态变量。
//例如，可以使用std::mutex或std::atomic提供的容器或数据结构
//自旋锁,信号量,
#include<iostream>
#include<pthread.h>
#include<atomic>
using namespace std;
#define NUM 5
std::atomic<int>counter(0);

void* incrementCounter(void* args)
{
    int tid= *(int*)args;
    for(int i=0;i<10000;i++)
    {
        counter.fetch_add(1,std::memory_order_relaxed);
    }
    return nullptr;
}
int main()
{
    pthread_t tid[NUM];
    for(int i=0;i<NUM;i++)
        pthread_create(&tid[i],nullptr,incrementCounter,(void*)&tid[i]);
    for(int i=0;i<NUM;i++)
        pthread_join(tid[i],nullptr);
    cout<<"Counter Value:"<<counter<<endl;
    return 0;
}