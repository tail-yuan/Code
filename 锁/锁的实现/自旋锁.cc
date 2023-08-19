#include <iostream>
#include <pthread.h>
#include <thread>
//使用pthread库中的pthread_spin_lock()接口封装一个自旋锁类
class SpinLock
{
private:
    pthread_spinlock_t _lock;

public:
    SpinLock()
    {
        pthread_spin_init(&_lock, 0);
    }
    ~SpinLock()
    {
        pthread_spin_destroy(&_lock);
    }

public:
    void lock()
    {
        pthread_spin_lock(&_lock);//尝试获取锁，如果锁已经被占用，则会一直自旋等待
    }
    void unlock()
    {
        pthread_spin_unlock(&_lock);
    }
};
int main()
{
    SpinLock sl;
    std::thread t1([&]()
                   {
                       sl.lock();
                       //do things!!
                       std::cout<<"thread 1 acquired the lock!"<<std::endl;
                       sl.unlock(); });
    std::thread t2([&]() {
        sl.lock();
        //do thing!
        std::cout<<"thread 2 acquired the lock!"<<std::endl;
        sl.unlock();
    });
    t1.join();
    t2.join();
    return 0;
}