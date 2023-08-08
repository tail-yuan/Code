#include <iostream>
#include <pthread.h>
#include <thread>
#include<vector>
#include <mutex>
// 读写锁是一把锁分为两部分：读锁和写锁，其中读锁允许多个线程同时获得，而写锁则是互斥锁。
// 它的完整规则是：读读不互斥、读写互斥、写写互斥。
// 它适用于多读的业务场景，使用它可以有效的提高程序的执行性能，也能避免读取到操作了一半的临时数据

// 使用两把互斥锁
// 当读写锁中的读锁被某个线程加上时，先加上读互斥锁，这样保证了其他线程不能再读了；
// 接着，再加上写互斥锁，同时计数加上 1，这样保证了其他线程不能再写了。
// 接着，把读互斥锁释放掉，因为要允许其他线程也能读这个共享变量。
// 也就是说，多次读时，只需要加一把写锁，表明其他线程暂时不能执行写操作。
// 当读写锁中的读锁被某个线程释放时，也是加上了读互斥锁，
// 这样保证多个线程同时释放读写锁中的读锁时没有问题。当没有线程读操作时，释放写互斥锁。
// 表明其他线程可以执行写操作了
class readwrite_lock
{
public:
    readwrite_lock()
        : read_cnt(0)
    {}

    void readLock()
    {
        read_mtx.lock();
        if (++read_cnt == 1) //存在线程读时
            write_mtx.lock();//写加锁,只加一次

        read_mtx.unlock();
    }

    void readUnlock()
    {
        read_mtx.lock();
        if (--read_cnt == 0)    //没有线程读时
            write_mtx.unlock();//写释放锁

        read_mtx.unlock();
    }

    void writeLock()
    {
        write_mtx.lock();
    }

    void writeUnlock()
    {
        write_mtx.unlock();
    }

private:
    std::mutex read_mtx;
    std::mutex write_mtx;
    int read_cnt; // 已加读锁个数
};
volatile int var = 10; // 保持变量 var 对内存可见性，防止编译器过度优化
readwrite_lock rwLock; // 定义全局的读写锁变量

void Write() {
    rwLock.writeLock();
    var += 10;
    std::cout << "write var : " << var << std::endl;
    rwLock.writeUnlock();
}

void Read() {
    rwLock.readLock();
    std::cout << "read var : " << var << std::endl;
    rwLock.readUnlock();
}

int main() {
    std::vector<std::thread> writers;
    std::vector<std::thread> readers;
    for (int i = 0; i < 10; i++) {  // 10 个写线程
        writers.push_back(std::thread(Write));  // std::thread t 的写法报错
    }
    for (int i = 0; i < 100; i++) {   // 100 个读线程
        readers.push_back(std::thread(Read));
    }
    for (auto& t : writers) {   // 写线程启动
        t.join();
    }
    for (auto& t : readers) {   // 读线程启动
        t.join();
    }
    std::cin.get();
}
// 2. 使用pthread库中的rwlock接口实现
class ReadWriteLock
{
public:
    ReadWriteLock()
    {
        pthread_rwlock_init(&rwlock, nullptr);
    }

    ~ReadWriteLock()
    {
        pthread_rwlock_destroy(&rwlock);
    }

    void readLock()
    {
        pthread_rwlock_rdlock(&rwlock);
    }

    void readUnlock()
    {
        pthread_rwlock_unlock(&rwlock);
    }

    void writeLock()
    {
        pthread_rwlock_wrlock(&rwlock);
    }

    void writeUnlock()
    {
        pthread_rwlock_unlock(&rwlock);
    }

private:
    pthread_rwlock_t rwlock;
};

int sharedResource = 0;
ReadWriteLock rwLock;

void readerFunction(int id)
{
    rwLock.readLock();
    std::cout << "Reader " << id << " reads: " << sharedResource << std::endl;
    rwLock.readUnlock();
}

void writerFunction(int id)
{
    rwLock.writeLock();
    sharedResource = id;
    std::cout << "Writer " << id << " writes: " << sharedResource << std::endl;
    rwLock.writeUnlock();
}

int main()
{
    std::thread readers[5];
    std::thread writers[2];

    for (int i = 0; i < 5; ++i)
    {
        readers[i] = std::thread(readerFunction, i);
    }

    for (int i = 0; i < 2; ++i)
    {
        writers[i] = std::thread(writerFunction, i + 1);
    }

    for (int i = 0; i < 5; ++i)
    {
        readers[i].join();
    }

    for (int i = 0; i < 2; ++i)
    {
        writers[i].join();
    }

    return 0;
}
