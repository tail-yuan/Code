#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;
#define NUM 5 //指明半连接队列的个数 + 1 =NUM
class Sock
{
public:
    static int Socket()
    {
        int listen_sock = socket(AF_INET, SOCK_STREAM, 0); // 协议家族:0就是sin_family,创建套接字时设置为0
        if (listen_sock < 0)
        {
            perror("socket error\n");
            exit(2);
        }
        return listen_sock;
    }
    static void Bind(int sock, uint16_t port)
    {
        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_addr.s_addr = INADDR_ANY; // 1.
        local.sin_family = AF_INET;   // 套接字类型
        local.sin_port = htons(port); // 主机序列转网络序列
        if (bind(sock, (struct sockaddr *)&local, sizeof(local)) < 0)//==0代表绑定成功
        {
            perror("bind error\n");
            exit(3);
        }
    }
    static void Listen(int sock,int n =NUM)
    {
        if(listen(sock,NUM)<0)
        {
            perror("listen error\n");
            exit(4);
        }
    }
    static int Accept(int sock)
    {
        struct sockaddr_in peer;//顾客
        socklen_t len=sizeof(peer);
        int new_sock = accept(sock,(struct sockaddr*)&peer,&len);
        if(new_sock<0)
        {
            perror("accept error\n");
            exit(5);
        }
        else
            return new_sock;
    }
    static void Connect(int sock,string ip,uint16_t port)
    {
        struct sockaddr_in server;
        memset(&server,0,sizeof(server));
        server.sin_addr.s_addr = inet_addr(ip.c_str());//顾客连接服务器就需要指明你要连接那个IP
        server.sin_family=AF_INET;
        server.sin_port= htons(port);
        if(connect(sock,(struct sockaddr*)&server,sizeof(server)) == 0)
        {
            cout<<"connect success!"<<endl;
            return ;
        }
        else
        {
            perror("connect error\n");
            exit(6);
        }
    }
};
// 1.
// local.sin_addr.s_addr=inet_addr("192.168.2.3")
// 将点分十进制转化为4字节IP,并且转化为大端网络序列
// 显示bind的一定是server端,INADDR_ANY代表接收所有IP的连接,默认是0
// 不指明服务器某一主机IP,服务端是多台主机之间协作,只要是发送到port的,都接收.