#pragma once
#include <iostream>
namespace ns_task
{
    class Task
    {
        private:
        int x_;
        int y_;
        char opr_;
    public:
        Task()
        {}
        Task(int a,int b,char op)
            :x_(a)
            ,y_(b)
            ,opr_(op)
        {}
        ~Task()
        {}
    public:
        int operator()()
        {
            return Run();
        }
    public:
        std::string Show()
        {
            std::string message=std::to_string(x_);
            message+= opr_;
            message+=std::to_string(y_);
            message+="=?";
            return message;
        }
        int Run()
        {
            int res=0;
            switch(opr_)
            {
                case '+':
                res=x_+y_; 
                break;
                case '-':
                res=x_-y_;
                break;
                case '*':
                res=x_*y_;
                break;
                case '/':
                res=x_/y_;
                break;
                case '%':
                res=x_%y_;
                break;
                default:
                break;
            }
            std::cout<<"当前任务正在被："<<pthread_self()<<"处理->"\
            <<x_<<opr_<<y_<<"="<<res<<std::endl;
            return res;
        }
    };
}