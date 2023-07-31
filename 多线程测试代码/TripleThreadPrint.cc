#include<iostream>
#include<pthread.h>
#include<mutex>
#include<unistd.h>
using namespace std;

int count=1;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
void* Print(void* args)
{
  int thread_id=*(int*)args;
  while(1)
  {
    pthread_mutex_lock(&mtx);
    if(count<100)
    {
      cout<<"thread["<<thread_id<<"] "<<"- [thread_number is "<<pthread_self()<<"] is adding to"<<count<<endl;
      count++;
    }
    else{
      pthread_mutex_unlock(&mtx);
      pthread_exit(NULL);
    }
    pthread_mutex_unlock(&mtx);
      sleep(1);
  }

}
int main()
{
  pthread_t tid[3];
  for(int i=0;i<3;i++)
  {
    pthread_create(&tid[i],nullptr,Print,(void*)&i);
  }
  for(int i=0;i<3;i++)
  {
    pthread_join(tid[i],nullptr);
  }

  //pthread_t tid1=1,tid2=2,tid3=3;
  //pthread_create(&tid1,nullptr,Print,(void*)(&tid1));
  //pthread_create(&tid2,nullptr,Print,(void*)(&tid2));
  //pthread_create(&tid3,nullptr,Print,(void*)(&tid3));
  //  
  //pthread_join(tid1,nullptr);
  //pthread_join(tid2,nullptr);
  //pthread_join(tid3,nullptr);
  //return 0;
}
