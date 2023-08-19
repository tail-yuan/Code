#pragma once
#include<iostream>
#include<vector>
#include<semaphore.h>
//环形队列-使用信号量实现CP模型
namespace ns_ring_queue
{
    #define NUM 10
    template<class T>
    class RingQueue
    {
    private:
        std::vector<T> ringQueue;
        int cap;
        //信号量标识环形队列中可用资源个数
        sem_t blank_sem;    //空位资源-生产者关注
        sem_t data_sem;     //数据资源-消费者关注

        int c_step;
        int p_step;
    public:
        RingQueue(int n=NUM)
            :cap(n)
            ,ringQueue(n)
        {
            sem_init(&blank_sem,0,cap);
            sem_init(&data_sem,0,cap);
            c_step=0;
            p_step=0;
        }
        ~RingQueue()
        {
            sem_destroy(&blank_sem);
            sem_destroy(&data_sem);
        }
    public:
        void Push(const T& in)
        {
            sem_wait(&blank_sem);//1.
            ringQueue[p_step]=in;
            sem_post(&data_sem);//2.
            p_step++;
            p_step%=cap;//因为是环形,维护下标重启
        }
        void Pop(T* out)
        {
            sem_wait(&data_sem);
            *out=ringQueue[c_step];
            sem_post(&blank_sem);
            c_step++;
            c_step%=cap;
        }
    };
}
//1.
//P操作申请信号量,由于是生产者,关注的是blank_sem,申请走一个,P操作执行的就是blank_sem--
//V操作: 因为生产者将blank->data,blank资源--,对应data资源++,V操作就是++信号量的