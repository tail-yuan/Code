// 生产者消费者所能通信的,共同看到的一份资源,阻塞队列
#include <iostream>
#include <queue>
#include <pthread.h>
using namespace std;

namespace ns_BlockQueue
{
#define NUM 10
    template <class T>
    class BlockQueue
    {
    private:
        std::queue<T> bq;
        int cap;
        pthread_mutex_t mtx;
        pthread_cond_t is_full;  // 消费者关心-Consumer
        pthread_cond_t is_empty; // 生产者关心-Producter
    public:
        BlockQueue(int n = NUM)
            : cap(n)
        {
            pthread_cond_init(&is_full, nullptr);
            pthread_cond_init(&is_empty, nullptr);
            pthread_mutex_init(&mtx, nullptr);
        }
        ~BlockQueue()
        {
            pthread_cond_destroy(&is_full);
            pthread_cond_destroy(&is_empty);
            pthread_mutex_destroy(&mtx);
        }

    public:
        void Push(const T &in) // Producter-生产者
        {
            LockQueue();
            while (isFull())
            {
                ProducterWait();
            }
            bq.push(in);
            // 插入之后别忘了通知消费者来取
            if (bq.size() > cap / 2)
            {
                WakeUpConsumer();
            }
            UnLockQueue();
        }
        void Pop(T *out) // Consumer-消费者
        {
            LockQueue();
            while (isEmpty())
            {
                ConsumerWait();
            }
            *out = bq.front();
            bq.pop();
            if (bq.size() < cap / 3)
            {
                WakeUpProducter();
            }
            UnLockQueue();
        }

    public:
        bool isFull()
        {
            return bq.size() == cap;
        }
        bool isEmpty()
        {
            return bq.size() == 0;
        }
        void LockQueue()
        {
            pthread_mutex_lock(&mtx);
        }
        void UnLockQueue()
        {
            pthread_mutex_unlock(&mtx);
        }
        void ConsumerWait()
        {
            pthread_cond_wait(&is_full, &mtx);
        }
        void ProducterWait()
        {
            pthread_cond_wait(&is_empty, &mtx);
        }

    public:
        void WakeUpConsumer()//什么时候唤醒消费者?阻塞队列中物品满了,所以是is_full
        {
            pthread_cond_signal(&is_full);
        }
        void WakeUpProducter()//什么时候唤醒生产者?阻塞队列中物品没了,所以是is_empty
        {
            pthread_cond_signal(&is_empty);
        }
    };
}