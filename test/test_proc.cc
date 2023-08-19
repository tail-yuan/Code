
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;
// 设置(非)阻塞等待形式 waitpid(..,..,x)
//child[26177] is running
//father process[26176] is doing things
//...
//father wait child[26177] successfully,status code:11,status exit signal:0
int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // child process
        int cnt = 5;
        while (cnt--)
        {
            printf("child[%d] is running\n", getpid());
            sleep(1);
        }
        exit(11); // test 1 设置退出码
        // int a=10;
        // a/=0;//test 2自己设置bug,让系统发送信号中止进程
    }
    printf("father wait begin\n");
    int status=0;
    //子进程设置为非阻塞,但是得轮询检测,时不时问一问,一旦退出立马回收子进程
    while(1)
    {
        pid_t ret=waitpid(pid,&status,WNOHANG);
        if(ret>0)
        {
            //子进程退出了,获取退出信息并回收
            printf("father wait child[%d] successfully,status code:%d,status exit signal:%d\n",ret,(status>>8)&0xFF,status&0x7F);
            break;
        }
        else if(ret==0)//子进程还没有退出
        {
            //do father things!
            printf("father process[%d] is doing things\n",getpid());
        }
        else
        {
            printf("wait error\n");
            break;
        }
        sleep(1);
    }
}
// 获取子进程退出信息
// 2. 使用宏查询子进程退出信息 WIFEXITED(status)
int main4()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // child process
        int cnt = 5;
        while (cnt--)
        {
            printf("child[%d] is running\n", getpid());
            sleep(1);
        }
        exit(11); // test 1 设置退出码
        // int a=10;
        // a/=0;//test 2自己设置bug,让系统发送信号中止进程
    }
    printf("father wait begin\n");
    int status = 0;
    pid_t ret = waitpid(pid, &status, 0);
    if (ret > 0)
    {
        if (WIFEXITED(status))
        {
            printf("exit code:%d\n", WEXITSTATUS(status));
            // exit code:11
        }
        else
        {
            printf("error get a signal\n");
            // 除零错误时打印 get a signal
        }
    }
    return 0;
}
// 1. by status
// status [15...8]是退出信息,[6...0]是进程中止的信号,[7]是core dump标志位
int main3()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // child process
        int cnt = 5;
        while (cnt--)
        {
            printf("child[%d] is running\n", getpid());
            sleep(1);
        }
        exit(11); // test 1 设置退出码
        // int a=10;
        // a/=0;//test 2自己设置bug,让系统发送信号中止进程
    }
    printf("father wait begin\n");
    int status = 0;
    int ret = waitpid(pid, &status, 0);
    if (ret > 0)
    {
        printf("father wait :%d success,status code:%d,status exit signal :%d\n", ret, (status >> 8) & 0xFF, status & 0x7F);
        // father wait :25747 success,status code:11,status exit signal :0 test 1
        // father wait :25826 success,status code:0,status exit signal :8  test 2
    }
    else
    {
        printf("father wait failed\n");
    }
    return 0;
}

// 进程等待-wait函数获取子进程退出信息
// ps axj|grep test 查看运行时子进程状态                stat
// 僵尸进程显示:25157 25158 25157 24811 pts/2    25157  Z+       0   0:00 [test] <defunct>
int main2()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // 子进程
        int cnt = 5;
        while (cnt--)
        {
            printf("child[%d] is running \n", getpid());
            sleep(1);
        }
        // 子进程先退出
        exit(0);
    }
    // 父进程先不及时回收子进程,子进程此时处于不确定死活的僵尸状态
    sleep(10);

    printf("father wait begin\n");
    // pid_t wait(int *status); 退出信息设置为空,不关心的意思
    // pid_t id=wait(NULL);
    // pid_t id=waitpid(-1,NULL,0);//-1代表任意子进程
    pid_t id = waitpid(id, NULL, 0); // id代表指定子进程
    if (id > 0)
    {
        cout << "father wait" << id << "successfully!" << endl;
    }
    else
    {
    }
    return 0;
}

// 进程替换
int main1()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("I am child proc,pid:%d\n", getpid());

        execl("/usr/bin/ls", "ls", "-a", "-l", NULL);

        cout << "carry on fighting\n"
             << endl; // 进程替换后,原来进程的代码和数据都直接在物理空间中替换,所以没有实现打印
    }
    else
    {
    }
    return 0;
}