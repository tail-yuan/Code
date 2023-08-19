#include"BlockQueue.hpp"
#include"Task.hpp"
#include<ctime>
#include<cstdlib>
#include<unistd.h>
using namespace ns_BlockQueue;
using namespace ns_task;
using namespace std;
void* Consumer(void* args)
{
    BlockQueue<Task>* bq=(BlockQueue<Task>*)args;
    while(1)
    {
        Task t;
        bq->Pop(&t);
        t.Run();
    }
}
void* Producter(void* args)
{
    BlockQueue<Task>* bq=(BlockQueue<Task>*)args;
    string opt="+-*/%";
    while(1)
    {
        int x=rand()%100;
        int y=rand()%100;
        char op = opt[rand()%5];
        Task t(x,y,op);
        bq->Push(t);
        cout<<"生产者派发了一个任务："<<x<<op<<y<<"= ? "<<endl;
        sleep(1);
    }
}

int main()
{
    srand(time(nullptr));
    BlockQueue<Task>* bq=new BlockQueue<Task>();
    pthread_t p;
    pthread_t c[5];
    pthread_create(&p,nullptr,Producter,(void*)bq);
    for(int i=0;i<5;i++)
    {
        pthread_create(&c[i],nullptr,Consumer,(void*)bq);
    }

    pthread_join(p,nullptr);
    for(int i=0;i<5;i++)
    {
        pthread_join(c[i],nullptr);
    }  
    return 0;
}