#include <iostream>
#include <pthread.h>
#include<unistd.h>
using namespace std;

#define NUM 1000
class Ticket
{
private:
    int num;
    pthread_mutex_t mtx;
public:
    Ticket(int n = NUM)
        : num(n)
    {
        pthread_mutex_init(&mtx,nullptr);
    }
    ~Ticket()
    {
        pthread_mutex_destroy(&mtx);
    }
public:
    bool GetTickets()
    {
        bool res=true;

        pthread_mutex_lock(&mtx);
        if(num>0)
        {
            usleep(1000);
            cout<<"我是"<<pthread_self()<<",我抢票的编号是"<<num<<endl;
            num--;
            printf("");//故意调用，增加用户态的切换
        }
        else
        {
            res=false;
        }
        pthread_mutex_unlock(&mtx);
        return res;
    }
};
void* thread_run(void* args)
{
    Ticket* t=(Ticket*)args;
    while(1)
    {
        if(!t->GetTickets())
        {
            cout<<"票被抢完了"<<endl;
            break;
        }
    }
    return nullptr;
}
int main()
{
    Ticket* t =new Ticket();

    pthread_t tid[5];
    for(int i=0;i<5;i++)
    {
        pthread_create(&tid[i],nullptr,thread_run,(void*)t);//参数不是瞎传的
    }
    for(int i=0;i<5;i++)
    {
        pthread_join(tid[i],nullptr);//进行阻塞等待
    }
    return 0;
}