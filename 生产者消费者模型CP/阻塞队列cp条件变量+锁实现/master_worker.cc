#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;
//master-worker模型实现master线程定时通知所有的worker线程开始工作!
pthread_cond_t cond;
pthread_mutex_t mtx;
void* ctrl(void* args)
{
    while(1)
    {
        cout<<"begin work"<<endl;
        // pthread_cond_signal(&cond);
        pthread_cond_broadcast(&cond);
        sleep(1);
    }
    return nullptr;
}
void* work(void* args)
{
    int * number =(int*)args;
    delete (int*)args;

    while(1)
    {
        pthread_cond_wait(&cond,&mtx);//条件变量未就绪时,就释放锁之后阻塞等待.这个场景mutex是没有后序意义的.
        cout<<"worker id "<<number <<" is running"<<endl;
    }
}
int main()
{
#define NUM 5
    pthread_mutex_init(&mtx,nullptr);
    pthread_cond_init(&cond,nullptr);

    pthread_t master;
    pthread_t worker[NUM];

    pthread_create(&master,nullptr,ctrl,(void*)"master");
    for(int i=0;i<NUM;i++)
    {
        int *id =new int(i);
        pthread_create(&worker[i],nullptr,work,(void*)id);
    }

    for(int i=0;i<NUM;i++)
    {
        pthread_join(worker[i],NULL);
    }
    pthread_join(master,NULL);

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cond);
    return 0;
}