#include <iostream>
#include <queue>
#include <pthread.h>
#include <mutex>
namespace yuanwei1
{
#define NUM 5
    template <class T>
    class ThreadPool
    {
    private:
        int num;
        std::queue<T> task_queue;//任务队列
        pthread_cond_t cond;
        pthread_mutex_t mtx;

    public:
        ThreadPool(int n=NUM)
            : num(n)
        {
            pthread_cond_init(&cond, nullptr);
            pthread_mutex_init(&mtx, nullptr);
        }
        ~ThreadPool()
        {
            pthread_cond_destroy(&cond);
            pthread_mutex_destroy(&mtx);
        }

    public:
        void InitThreadPool()
        {
            pthread_t tid[NUM];
            for (int i = 0; i < NUM; i++)
            {
                pthread_create(&tid[i], nullptr, Rountine, (void*)this);
                // 访问线程池这个类里面的所有方法，就要采用对象的方式进行访问，传this指针
            }
        }
        static void *Rountine(void *args)
        {
            pthread_detach(pthread_self());
            ThreadPool<T> *tp = (ThreadPool<T> *)args;
            while (1)
            {
                tp->Lock();
                while (tp->Empty())//如果任务队列为空,没有任务
                {
                    tp->Wait(); // 就将线程挂起
                }
                T t;
                tp->PopTask(&t);//获取到任务->t &t->T*  输出型参数
                tp->UnLock();
                t();        //执行T默认动作
            }
        }
    private:
        void Lock()
        {
            pthread_mutex_lock(&mtx);
        }
        void UnLock()
        {
            pthread_mutex_unlock(&mtx);
        }
        bool Empty()
        {
            return task_queue.empty();
        }
        void Wait()
        {
            pthread_cond_wait(&cond,&mtx);
        }
        void WakeUp()
        {
            pthread_cond_signal(&cond);
        }
    public:
        void Push(const T& in)
        {
            Lock();
            task_queue.push(in);
            UnLock();
            WakeUp();   //将挂起的线程唤醒,有任务了
        }
        void PopTask(T* out)
        {
            *out = task_queue.front();
            task_queue.pop();
        }
    };
}