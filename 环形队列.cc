#include<iostream>
#include<vector>
#include<pthread.h>
using namespace std;

#define NUM 5
vector<int> buffer(NUM);
pthread_mutex_t mtx;
pthread_cond_t cvProducter,cvConsumer;
int count=0;
int in=0;
int out=0;
void* Product(void* args)
{
    for(int i=1;i<=10;i++)
    {
        pthread_mutex_lock(&mtx);
        while(count == NUM)
            pthread_cond_wait(&cvProducter,&mtx);
        buffer[in]=i;
        in= (in+1)%NUM;
        count++;
        std::cout<<"Producter produces "<<i<<std::endl;
        pthread_cond_signal(&cvConsumer);
        pthread_mutex_unlock(&mtx);
    }
    pthread_exit(nullptr);
}
void * Consume(void* args)
{
    for(int i=1;i<=10;i++)
    {
        pthread_mutex_lock(&mtx);
        while(count ==0)
            pthread_cond_wait(&cvConsumer,&mtx);
        int data=buffer[out];
        out=(out+1)%NUM;
        count--;
        std::cout<<"Consumer takes "<<data<<std::endl;
        pthread_cond_signal(&cvProducter);
        pthread_mutex_unlock(&mtx);
    }
    pthread_exit(nullptr);
}
int main()
{
    pthread_t producter,consumer;
    pthread_mutex_init(&mtx,NULL);
    pthread_cond_init(&cvConsumer,nullptr);
    pthread_cond_init(&cvProducter,nullptr);

    pthread_create(&producter,nullptr,Product,nullptr);
    pthread_create(&consumer,nullptr,Consume,nullptr);

    pthread_join(producter,nullptr);
    pthread_join(consumer,nullptr);

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cvProducter);
    pthread_cond_destroy(&cvConsumer);
}