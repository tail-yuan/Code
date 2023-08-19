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
        std::queue<T> task_queue; // 任务队列
        pthread_cond_t cond;
        pthread_mutex_t mtx;

        static ThreadPool<T> *ins;

    public:
        ThreadPool(int n = NUM)
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
        // add
        ThreadPool(const ThreadPool<T> &t) = delete;
        ThreadPool<T> operator=(ThreadPool<T> &t) = delete;

    public:
        static ThreadPool<T> *GetInstance()
        {
            static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

            if (ins == nullptr) // 第2次之后的线程来提升效率,不用再耗费时间竞争锁
            {
                pthread_mutex_lock(&lock);
                if (ins == nullptr) // 第1次线程来保证安全
                {
                    ins = new ThreadPool<T>();
                    ins->InitThreadPool();
                    std::cout << "首次加载对象" << std::endl;
                }
                pthread_mutex_unlock(&lock);
            }
            return ins;
        }

    public:
        void InitThreadPool()
        {
            pthread_t tid[NUM];
            for (int i = 0; i < NUM; i++)
            {
                pthread_create(&tid[i], nullptr, Rountine, (void *)this);
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
                while (tp->Empty()) // 如果任务队列为空,没有任务
                {
                    tp->Wait(); // 就将线程挂起
                }
                T t;
                tp->PopTask(&t); // 获取到任务->t &t->T*  输出型参数
                tp->UnLock();
                t(); // 执行T默认动作
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
            pthread_cond_wait(&cond, &mtx);
        }
        void WakeUp()
        {
            pthread_cond_signal(&cond);
        }

    public:
        void Push(const T &in)
        {
            Lock();
            task_queue.push(in);
            UnLock();
            WakeUp(); // 将挂起的线程唤醒,有任务了
        }
        void PopTask(T *out)
        {
            *out = task_queue.front();
            task_queue.pop();
        }
    };
    // template<class T>
    // //饿汉模式
    // ThreadPool<T>* ThreadPool<T>::ins =new ThreadPool();
    // 懒汉模式
    template <class T>
    ThreadPool<T> *ThreadPool<T>::ins = nullptr;
}