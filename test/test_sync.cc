//测试进程同步时的事件机制 pthread库使用的是pthread_cond_t pthread_mutex_t

#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
bool eventOccurred = false;

void* WaitEvent(void* args)
{
    int id=*(int*)args;
    pthread_mutex_lock(&mtx);
    while(!eventOccurred)//事件不就绪
    {
        cout<<"thread["<<id<<"]is waiting!"<<endl;
        pthread_cond_wait(&cond,&mtx);//先将锁释放,等到条件就绪再第一时间获取到锁
    }
    //被唤醒之后继续执行之后的代码
    std::cout << "Event occurred! Thread " << id << " is continuing." << std::endl;
    pthread_mutex_unlock(&mtx);
    pthread_exit(nullptr);
    return nullptr;
}
int main()
{
#define NUM 2
    pthread_t tid[NUM];
    for(int i=0;i<NUM;i++)
    {
        pthread_create(&tid[i],nullptr,WaitEvent,(void*)(&tid[i]));
    }

    sleep(2);//模拟时间就绪等待
    pthread_mutex_lock(&mtx);
    eventOccurred=true;
    //cond通知
    pthread_cond_broadcast(&cond);//通知所有等待的线程当线程收到通知后，会从条件变量的等待中返回，并继续执行。
    cout<<"I had broadcast all thread!"<<endl;
    // pthread_cond_signal(&cond);    
    pthread_mutex_unlock(&mtx);
    //确保在子线程完成后，再继续执行主线程或其他线程的操作。
    for(int i=0;i<NUM;i++)
    {
        pthread_join(tid[i],nullptr);
    }
    return 0;
}