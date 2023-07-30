// 实现线程安全版本的shared_ptr
// std::shared_ptr使用的是原子操作引用计数,保证shared_ptr自身的线程安全,
// 如果想要保证,在并发状态下资源的访问也是线程安全的,需要加互斥锁比如lock_guard,或者其他同步机制

#include <iostream>
#include <atomic>
#include <mutex>
// 增加lock_guard互斥锁保护指针指向的资源
//你想要访问那个资源涉及到对自身资源的修改,你就需要保证那个资源受保护线程安全的,不让别的线程对他的值修改
template <typename T>
class ThreadSafeSharedPtr
{
private:
    T *_ptr;
    int *ref_count_ptr;
    mutable std::mutex mtx;

public:
    ThreadSafeSharedPtr(T *ptr)
        : _ptr(ptr), ref_count_ptr(new int(1))
    {
    }
    //在拷贝构造函数中，只有一个对象的资源涉及到修改，所以只需要用一个 std::lock_guard 来保护该对象的互斥锁。
    //保证对于另一个对象的访问是安全的,所以锁定sp的锁.
    ThreadSafeSharedPtr(ThreadSafeSharedPtr<T> &sp)
    {
        std::lock_guard<std::mutex> lock(sp.mtx);//保护另一个对象的资源,所以锁定他的锁
        _ptr = sp._ptr;// 获取另一个对象的资源指针
        ref_count_ptr = sp.ref_count_ptr;
        if (ref_count_ptr)
            *ref_count_ptr++;// 增加另一个对象的引用计数
    }
    ThreadSafeSharedPtr<T> operator=(ThreadSafeSharedPtr<T> &sp)
    {
        if (this != &sp)
        {
            ThreadSafeSharedPtr tmp(sp);
            my_swap(sp);
            return *this;
        }
    }
    ~ThreadSafeSharedPtr()
    {
        release();
    }

private:
    //release 函数只涉及一个 shared_ptr 实例的资源释放。
    void release()
    {
        std::lock_guard<std::mutex> lock(mutex);
        if(ref_count_ptr)
        {
            (*ref_count_ptr)--;
            if(*ref_count_ptr==0)
            {
                delete _ptr;
                delete ref_count_ptr;
            }
            _ptr=nullptr;
            ref_count_ptr=nullptr;
        }
    }
    //swap 函数涉及两个 shared_ptr 实例之间的资源交换，
    //所以需要使用两个 std::lock_guard 对象来分别锁定两个 shared_ptr 的互斥锁,保证两次访问都是线程安全
    void my_swap(ThreadSafeSharedPtr<T> &sp)
    {
        std::lock_guard<mutex>lock1(mtx);//它访问我时我的资源安全
        std::lock_guard<mutex>lock2(sp.mtx);//我访问它时他的资源安全

        std::swap(_ptr,sp._ptr);
        std::swap(ref_count_ptr,sp.ref_count_ptr);
    }
};
// 使用std::atomic<int>保护引用计数
template <typename T>
class my_shared_ptr
{
private:
    T *_ptr;
    std::atomic<int> refCount;

public:
    explicit my_shared_ptr(T *ptr)
        : _ptr(ptr), refCount(1)
    {
    }
    my_shared_ptr(const my_shared_ptr<T> &sp)
        : _ptr(sp._ptr)
    {
        refCount.store(sp.refCount.load()); // 将sp拷贝构造给自己,需要将他的引用计数给我并加1
        refCount.fetch_add(1);
        // sp.refCount.load(): 这部分代码是获取另一个 shared_ptr 对象 sp 的引用计数值。
        // load() 是 std::atomic 类模板的成员函数，用于获取原子类型的值。
        // 因为 sp.refCount 是一个 std::atomic 类型的成员，所以可以使用 load() 来获取其原子值。
        //  refCount.store(...): 这部分代码是将获取到的引用计数值存储到当前 shared_ptr 对象的引用计数中。
        // store() 是 std::atomic 类模板的成员函数，用于将原子类型的值存储到 std::atomic 对象中。
        //  因为 refCount 是一个 std::atomic 类型的成员，所以可以使用 store() 来将值存储到该原子对象中。
    }
    my_shared_ptr<T> operator=(my_shared_ptr<T> &sp)
    {
        if (this != &sp)
        {
            release();
            _ptr = sp._ptr;
            refCount.store(sp.refCount.load());
            refCount.fetch_add(1);
            return *this;
        }
    }
    T *get() const
    {
        return _ptr;
    }
    int getUseCount()
    {
        return refCount.load();
    }
    ~my_shared_ptr()
    {
        release();
    }

public:
    void release()
    {
        if (refCount.fetch_sub(1) == 0)
        {
            delete _ptr;
        }
    }
};