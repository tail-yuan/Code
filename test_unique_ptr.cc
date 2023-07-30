#include <iostream>
#include <memory>
#include <pthread.h>

void* recursiveFunction(void* arg);

struct ThreadData {
    int depth;
};

int main() {
    const int numThreads = 4;
    pthread_t threads[numThreads];
    ThreadData threadData[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        threadData[i].depth = 0;
        pthread_create(&threads[i], nullptr, recursiveFunction, &threadData[i]);
    }

    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], nullptr);
    }

    return 0;
}

void* recursiveFunction(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    int depth = data->depth;

    if (depth >= 5) {
        return nullptr;
    }

    // 模拟动态分配资源
    std::unique_ptr<int> dynamicResource(new int[11]);
    std::cout << "Thread " << pthread_self() << " at depth " << depth << std::endl;

    // 递归调用
    ThreadData nextData = *data;
    nextData.depth++;
    recursiveFunction(&nextData);

    // 此处无需手动释放资源，因为 unique_ptr 会在函数返回时自动释放内存
    std::cout << "Thread " << pthread_self() << " returning from depth " << depth << std::endl;

    return nullptr;
}
