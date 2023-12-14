### socket设置为非阻塞

将一个套接字（socket）设置为非阻塞模式可以让操作不再阻塞等待，而是立即返回并报告套接字是否可以进行读取、写入或连接等操作。在网络编程中，这对于实现高效的异步通信非常重要。以下是在 C/C++ 中将套接字设置为非阻塞模式的方法：

`fcntl` 函数是一个用于控制文件描述符属性的系统调用，在网络编程中常用于设置套接字的属性，包括非阻塞模式、文件状态标志等。该函数的各个参数可以通过位操作进行组合，以达到不同的目的。以下是 `fcntl` 函数的常用参数和其含义：

```c
int fcntl(int fd, int cmd, ... /* arg */ );
```

- `fd`：需要操作的文件描述符。

- `cmd`：指定要进行的操作类型。以下是常用的几种 `cmd` 参数：

  - `F_GETFL`：获取文件描述符的状态标志。

  - `F_SETFL`：设置文件描述符的状态标志。

  - `F_DUPFD`：复制文件描述符。

- `arg`：根据操作类型的不同，此参数可能是一个整数值（用于设置状态标志）或一个指向结构体的指针（用于其他操作）。

**设置文件描述符状态标志示例：**

```c
int flags = fcntl(sockfd, F_GETFL, 0);  // 获取当前标志
fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);  // 设置为非阻塞模式
```

在上面的示例中，`flags` 变量存储了套接字的当前状态标志，然后使用位操作将 `O_NONBLOCK` 标志添加到其中，将套接字设置为非阻塞模式。

请注意，`fcntl` 函数的使用可能因操作系统和具体的场景而有所不同。在使用时，最好查阅操作系统的文档和相关资源，以了解更多详细的参数说明和用法示例。

**C语言示例：**

```c
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // 将套接字设置为非阻塞模式
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    
    // 现在 sockfd 已经设置为非阻塞模式
    // 可以进行非阻塞的读取、写入、连接等操作
    
    return 0;
}
```

**C++语言示例：**

```cpp
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // 将套接字设置为非阻塞模式
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    
    // 现在 sockfd 已经设置为非阻塞模式
    // 可以进行非阻塞的读取、写入、连接等操作
    
    return 0;
}
```

在这两个示例中，`fcntl` 函数用于获取和设置套接字的文件描述符标志。通过将 `O_NONBLOCK` 标志添加到当前标志中，套接字将被设置为非阻塞模式。

请注意，设置套接字为非阻塞模式后，在读取、写入、连接等操作中，**如果没有立即准备好数据或连接，系统会立即返回并返回适当的错误代码,并不会一直等待数据就绪**。因此，在非阻塞模式下，你可能需要使用循环和适当的处理来处理非阻塞 I/O。