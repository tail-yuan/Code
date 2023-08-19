#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "RingQueue.hpp"
#include "Task.hpp"
using namespace std;
using namespace ns_ring_queue;
using namespace ns_task;
void *Consumer(void *args)
{
    RingQueue<Task> *bq = (RingQueue<Task> *)args;
    while (1)
    {
        Task t;
        bq->Pop(&t);
        t.Run();
        sleep(1);
    }
}
void *Producter(void *args)
{
    RingQueue<Task> *bq = (RingQueue<Task> *)args;
    string opt = "+-*/%";
    while (1)
    {
        int x = rand() % 100;
        int y = rand() % 100;
        char op = opt[rand() % 5];
        Task t(x, y, op);
        cout << "生产者派发了一个任务：" << x <<" "<< op <<" "<< y << "= ? " << endl;
        bq->Push(t);
        sleep(1);
    }
}
int main()
{
    srand(time(nullptr));
    RingQueue<Task> *rq = new RingQueue<Task>();
    pthread_t c,p;
    pthread_create(&p,NULL,Producter,(void*)rq);
    pthread_create(&c,NULL,Consumer,(void*)rq);
    pthread_join(c,NULL);
    pthread_join(p,NULL);
    return 0;
}
