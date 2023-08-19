//实现异步编程简单逻辑

#include<iostream>
#include<future>
using namespace std;

int performTask(int n)//新起一个线程作为异步函数,模拟耗时操作
{
    cout<<"Performing task..."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return n*2;
}
int main()
{
    std::future<int> future_result=async(std::launch::async,performTask,10);
    
    cout<<"Performing other task..."<<endl;

    int ret=future_result.get();
    cout<<"输出结果是:"<<ret<<endl;

}