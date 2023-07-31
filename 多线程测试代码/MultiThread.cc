// 在C++中使用pthread库实现多线程处理多个文件中的数据并求和
//在C++中，while (file >> num) 是一个常见的用法，用于从文件流中读取数据并检查读取是否成功。
// 在这个语句中，file 是一个 std::ifstream 类型的对象，代表一个输入文件流。num 是一个整数变量，用于存储从文件中读取的值。
// file >> num 是一个输入操作符重载，它会尝试从文件中读取下一个值，并将其存储到 num 变量中。该操作符返回一个 std::ifstream 类型的对象，用于表示读取操作的状态。
// 在 while 循环中，file >> num 表达式的值被用作条件。如果读取成功，则条件为真，循环继续执行。如果读取失败（例如，到达文件末尾或遇到格式错误），则条件为假，循环结束。
// 因此，while (file >> num) 循环将一直执行，直到无法从文件中读取更多数据为止。这样，可以逐行读取文件中的数字并进行相应的处理。

#include <iostream>
#include <pthread.h>
#include <vector>
#include <fstream>
using namespace std;

pthread_mutex_t mtx;
vector<int> fileSum;
void *SumFileData(void *args)
{
    // 根据文件名字创建ifstream对象
    string filename = *static_cast<string *>(args);
    std::ifstream file(filename);
    int sum = 0;
    int num = 0;
    while (file >> num)
    {
        sum += num;
    }
    pthread_mutex_lock(&mtx);
    fileSum.push_back(sum);
    pthread_mutex_unlock(&mtx);
    pthread_exit(nullptr);
}
int main()
{
    pthread_mutex_init(&mtx, nullptr);

    vector<string> filenames = {"file1.txt", "file2.txt", "file3.txt"};
    pthread_t tid[filenames.size()];
    for (int i = 0; i < filenames.size(); i++)
        pthread_create(&tid[i], nullptr, SumFileData, &filenames[i]);

    for (int i = 0; i < filenames.size(); i++)
        pthread_join(tid[i], nullptr);
    int totalSum=0;
    for(auto e:fileSum)
        totalSum+=e;
    cout<<"totalSum="<<totalSum<<endl;

    pthread_mutex_destroy(&mtx);
}