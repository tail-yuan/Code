#include<iostream>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
// #include"ThreadPool.hpp"
#include"ThreadPoolSingle.hpp"
#include"Task.hpp"
using namespace yuanwei1;
using namespace yuanwei2;
int main()
{
    // ThreadPool<Task>* tp= new ThreadPool<Task>();
    // tp->InitThreadPool();
    
    // srand((long long)time(nullptr));
    // while(1)
    // {
    //     sleep(1);
    //     Task t(rand()%20+1,rand()%10+1,"+-*/%"[rand()%5]);
    //     tp->Push(t);
    // }

//单例模式
     srand((long long)time(nullptr));
    while(1)
    {
        sleep(1);
        Task t(rand()%20+1,rand()%10+1,"+-*/%"[rand()%5]);
        ThreadPool<Task>::GetInstance()->Push(t);
    }
    return 0;
}