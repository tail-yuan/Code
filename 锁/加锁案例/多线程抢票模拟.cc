#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <vector>
using namespace std;

vector<int> coupons;

const int numOfTheads = 100;//100个线程去抢票
const int N = 10000;//一共有多少张票

pthread_mutex_t mtx;
sem_t sem;

void* Rountine(void* args)
{
    int threadIndex=*(int*)args;
    // pthread_t threadIndex=pthread_self();
    sem_wait(&sem);//2.

    pthread_mutex_lock(&mtx);
    //临界区
    //抢到锁之后就可以抢票了,在数组中随机产生一个下标位置删除,代表抢到票了
    if(!coupons.empty())
    {
        //抢票
        int index=rand() % coupons.size();
        int coupon=coupons[index];
        coupons.erase(coupons.begin()+index);
        pthread_mutex_unlock(&mtx);
        cout<<"Thread "<<threadIndex<<" get a coupon ,which is "<<coupon<<endl;
    }
    else
    {
        //没票了,别忘了把锁释放掉
        pthread_mutex_unlock(&mtx);
        std::cout << "Thread " << threadIndex << " - No more coupons available." << std::endl;
    }
    sem_post(&sem);
    return nullptr;
}
int main()
{
    for (int i = 1; i <= N; i++)
        coupons.push_back(i);
    sem_init(&sem, 0, 10); // 1
    pthread_mutex_init(&mtx, nullptr);

    pthread_t arr[numOfTheads];
    for (int i = 0; i < numOfTheads; i++)
    {
        pthread_create(&arr[i], nullptr, Rountine, (void*)&i);//3.
    }
    for (int i = 0; i < numOfTheads; i++)
    {
        pthread_join(arr[i],nullptr);
    }
    pthread_mutex_destroy(&mtx);
    sem_destroy(&sem);
    return 0;
}
// 1.
// 表示最初有10个"许可证"可以被线程获取。当线程调用 sem_wait() 时，信号量的值将递减，当值为0时，线程将被阻塞直到有其他线程调用 sem_post() 增加信号量的值。
// 这样，在一个并发场景中，最多有10个线程可以同时获取信号量，之后其他线程需要等待。
// 这是一种有效的限制并发资源访问的方式，特别是当你希望控制一定数量的线程访问共享资源时。
//2. 
//当调用 sem_wait() 时，它会检查信号量的值，如果值大于零，就会将信号量的值减一，并立即返回。
// 如果值等于零，它会阻塞当前线程，直到信号量的值大于零为止。
// 这是一种阻塞操作，用于控制线程的执行流程，以避免过多的线程同时访问共享资源。
// 一般来说，sem_wait() 配合着 sem_post() 使用，sem_post() 用于增加信号量的值，
// 从而允许等待的线程继续执行。
//3. 
//3.1 在函数void* Rountine(void* args)中，你使用了int threadIndex=pthread_self();来获取线程的ID。
//然而，pthread_self()返回的是pthread_t类型的线程ID，而你将其赋值给了int类型的threadIndex。
//这样可能会导致类型转换问题。正确的做法是将线程ID传递作为参数。
//3.2 在创建线程时，你将"thread"传递给了线程函数，这可能导致线程函数内引用已经失效的字符串。
// 修改方式：
// 在传递线程ID时，使用正确的变量类型（整数）
