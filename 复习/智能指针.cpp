#include<iostream>
using namespace std;
template<class T>
class my_weak_ptr
{
private:
	T* ptr;
	int* pRefCount;
public:
	my_weak_ptr()
		:ptr(nullptr)
		, pRefCount(nullptr)
	{}
	my_weak_ptr(my_shared_ptr<T*>& sp)
		:ptr(sp.ptr)
		, pRefCount(sp.pRefCount)
	{}//����������ѭ�����ü���
	my_weak_ptr<T*> operator=(my_shared_ptr<T*>& sp)
	{
		_ptr = sp.ptr;
		pRefCount = sp.pRefCount;
	}
public:
	my_shared_ptr<T*> lock()//`lock` ��Ա������ȡһ����Ч�� `std::shared_ptr` ����
	{
		if (expired())
		{
			return my_shared_ptr<T*>(*this);
		}
		else
			return nullptr;
	}
	bool expired()//������Ķ����Ƿ��ѱ�����
	{
		return ptr == nullptr || *pRefCount == 0;
	}
};
template<class T>
class my_shared_ptr
{
public:
	T* ptr;
	int* pRefCount;
public:
	my_shared_ptr(T* p)
		:ptr(p)
		, pRefCount(new int(1))
	{}
	my_shared_ptr(my_shared_ptr<T*>& sp)
		:ptr(sp.ptr)
		, pRefCount(sp.pRefCount)
	{
		++(*pRefCount);
	}
	my_shared_ptr<T*> operator= (my_shared_ptr<T*>& sp)
	{
		if (this != &sp)
		{
			--(*pRefCount);
			if (*pRefCount == 0)
			{
				delete ptr;
				delete pRefCount;
			}
			ptr = sp.ptr;
			pRefCount = sp.pRefCount;
			++(*pRefCount);
		}
	}
};
//�̰߳�ȫ��shared_ptr
#include<atomic>
template<typename T>
class mySharedPtr
{
private:
	T* ptr;
	std::atomic<int>refCount;
public:
	//��ֹ����������ʿ����ת��֮����
	explicit mySharedPtr(T* p)
				:ptr(p)
				,refCount(1)
	{}
	mySharedPtr(mySharedPtr<T*>& sp)
		:ptr(sp.ptr)
	{
		refCount.store(sp.refCount.load());
		refCount.fetch_add(1);
	}
	mySharedPtr<T*> operator=(mySharedPtr<T*>& sp)
	{
		if (this != sp)
		{
			release();
			ptr = sp.ptr;
			refCount = sp.refCount;
			refCount.fetch_add(1);
			return *this;
		}
	}
private:
	void release()
	{
		if (refCount.fetch_sub(1) == 0)
		{
			delete ptr;
		}
	}
};
#include<mutex>
template<class T>
class ThreadSafe
{
public:
	ThreadSafe(T* p)
		:ptr(p)
		, pRef(new int(1))
	{}
	ThreadSafe(ThreadSafe<T*>& sp)
	{
		std::lock_guard<std::mutex> lock(sp.mtx);//��ΪҪ�޸�sp�����ü���,����ȷ�������̰߳�ȫ
		ptr = sp.ptr;
		pRef = sp.pRef;
		++(*pRef);
	}
	ThreadSafe<T*> operator=(ThreadSafe<T*>& sp)
	{
		if (this != sp)
		{
			ThreadSafe tmp(sp);
			my_swap(sp);
			return *this;
		}
	}
	~ThreadSafe()
	{
		release();
	}
private:
	void release()
	{
		std::lock_guard<std::mutex>lock(mtx);
		if (--(*pRef) == 0)
		{
			delete ptr;
			delete pRef;
		}
	}
	my_swap(ThreadSafe<T*>& sp)
	{
		std::lock_guard<mutex>lock1(mtx);//��������ʱ�ҵ���Դ��ȫ
		std::lock_guard<mutex>lock2(sp.mtx);//�ҷ�����ʱ������Դ��ȫ

		std::swap(ptr, sp.ptr);
		std::swap(pRef, sp.pRef);
	}
private:
	T* ptr;
	int* pRef;
	std::mutex mtx;
};