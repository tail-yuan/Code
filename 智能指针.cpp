#include<iostream>
using namespace std;
//����ʽ: ����auto_ptr����ʱ,��T*ָ���ÿ�,��������Դ����Ȩת��
//Ǳ������:1. ��T*sp=nullptr֮��,�������沢��֪��,��������֮�����Ұָ������
//		   2. û�н�������auto_ptr����ָ��ͬһ��ռ�ʱ�ĵ�������
template<class T>
class my_auto_ptr
{
public:
	//��֧����ʿ����ת���� auto_ptr<string> ptr=new string("yuanwei");error
	//						 auto_ptr<string> ptr(string("yuanwei"));success
	explicit my_auto_ptr(T* p)
		_ptr(p)
	{}
	//��������
	my_auto_ptr(auto_ptr<T>& sp)
		:_ptr(sp._ptr)
	{
		sp._ptr = nullptr;
	}
	~my_auto_ptr()()
	{
		delete _ptr;
		_ptr = nullptr;
	}
public:
	T* operator->()const
	{
		return _ptr;
	}
	T& operator*()const 
	{
		return *_ptr;
	}
private:
	T* _ptr;
};

//����ʽ: 1. Ϊ�˴���������ָ��ͳһ�ռ�,���ò���������󼴽��������캯����ֵ���캯����delete�ﵽ��������Ч��
//			2. ������ԭ��ָ���ÿ�,����Ұָ��
//����: ��Ȼ���ڶ������ָ��ͳһ�ռ�,�����Ҿ���T*p����������,��ô��ν�������ĵ���������?
template<typename T>
class my_unique_ptr
{
public:
	my_unique_ptr(T* p)
		:_ptr(p)
	{}
	~my_unique_ptr() { delete _ptr; _ptr = nullptr; }

	my_unique_ptr(my_unique_ptr<T>& sp) = delete;
	my_unique_ptr<T>& operator=(my_unique_ptr<T>& sp) = delete;

public:
	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
private:
	T* _ptr;
};

//����: ʹ�ü���ָ�뱣֤һ��������shared_ptr<T>����һ����Դ�������ü���,
//      Ϊʲô����static������?static���͵���������shared_ptr��,Ҳ����˵��ͬT���͵�,����ʵ��������string int ��������һ��,������.
template<typename T>
class my_shared_ptr
{
//private:
	T* _ptr;
	int* _pRefCount;//ָ�����ü����ǿ���Դ��ָ��,һ��shared_ptr<int>�ౣֻ֤��һ�����ü���.���ǲ�ͬT�����ж�����ü�����¼
public:
	my_shared_ptr(T* p)
		:_ptr(p)
		,pRefCount(1)
	{}
	~my_shared_ptr() { delete _ptr;_ptr=nullptr }

	my_shared_ptr(my_shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		,_pRefCount(sp._pRefCount)
	{
		++(*pRefCount);
	}
	my_shared_ptr<T>& operator=(my_shared_ptr<T>& sp)
	{
		if (this != &sp)//����ͬһ������ֵ
		{
			//��Ȼ����shared_ptr��,����T�Ĳ�ͬ����ʵ�������Ķ�����һ��,����share_ptr<int> = share_ptr<string>
			//����Ҫ����ԭ����share_ptr<int>ָ��Ŀռ��Ƿ��ͷŵ�����.
			//���Զ���һ��
			*_pRefCount--;
			if (*_pRefCount == 0)
			{
				delete _ptr;
				delete _pRefCount;
			}
			//��ֵ
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			(_pRefCount)++;
		}
		return *this;
	}
public:
	T* operator->()
	{
		return _ptr;
	}
	T& operatpr* ()
	{
		return *_ptr;
	}
	int GetRefCount()
	{
		return *_pRefCount;
	}
};
//����: ѭ������:node1�ڵ���һ��ptr1ָ��,����ptr2�ڵ��nextָ��ָ��,��ʱ���ü���Ϊ2
//		         node2�ڵ���һ��ptr2ָ��,����ptr1�ڵ��nextָ��ָ��,��ʱ���ü���Ϊ2
//���Ҫɾ��node1�ڵ�,������ptr1=nullptr,count--,����count=1,!=0,��Դ�޷�delete�ͷ�
//ͬ��node2�ڵ�,Ҳ�޷��ͷ�,ֻ��һ�����ͷ���һ�������ͷ�.
class Node
{
public:
	std::shared_ptr<Node> next;
	~Node()
	{
		cout << "��������" << endl;
	}
};
int main()
{
	std::shared_ptr<Node> ptr1 = std::make_shared<Node>();
	std::shared_ptr<Node> ptr2 = std::make_shared<Node>();

	ptr1->next = ptr1;
	ptr2->next = ptr1;
	system("pause");
	return 0;
}
//`std::weak_ptr` �����ڽ��ѭ����������Ĺ��ߣ������Դ��� `std::shared_ptr` �γɵ�ǿ���û���`std::weak_ptr` ����۲죨����ӵ�У��� `std::shared_ptr` ����Ķ��󣬶��������Ӷ�������ü�����
//
//`std::weak_ptr` ��Ҫ���ڽ��ѭ�����õ��µ��ڴ�й©���⡣
// ������ѭ������ʱ�������� `std::shared_ptr` ���ü����޷����㣬���¶����޷�����ȷ�����٣�
// �Ӷ�����ڴ�й©��ͨ��ʹ�� `std::weak_ptr`�����Խ�����һ�������������������Ϊ�����ã�
// �������ǲ����������ü�����Ҳ������ֹ��������١�
//`std::weak_ptr` �����������Ժ��÷���
//1. ���� `std::weak_ptr`������ͨ���� `std::weak_ptr` ��ʼ��Ϊ `std::shared_ptr` 
// ��ͨ�� `std::shared_ptr` �� `weak_ptr` ��Ա����������
// 
//2. ʹ�� `std::weak_ptr`������ʹ�� `std::weak_ptr` �� `lock` ��Ա������ȡһ����Ч�� `std::shared_ptr` ����
// ���Ա����������Ķ���`lock` ���� `std::shared_ptr` �Ƿ���Ȼ��Ч��
// �����Ч�򷵻�һ�����ж���� `std::shared_ptr`�����򷵻�һ���յ� `std::shared_ptr`��
//
//3. �ж� `std::weak_ptr` �Ƿ����(��,���߼���Ϊ0)������ʹ�� `expired` ��Ա������� `std::weak_ptr` �Ƿ����
// ����������Ķ����Ƿ��ѱ����٣������ `expired` ���� `true`����ʾ `std::shared_ptr` �Ѿ������٣�
// �����ٿ��ã�������� `false`����������Ч�� `std::shared_ptr` ������Է��ʡ�
//
//ͨ��ʹ�� `std::weak_ptr`�����Դ���ѭ�����õ�ǿ���û�����������ڲ��ٱ�ʹ��ʱ���������٣������ڴ�й©��
template <typename T>
class my_weak_ptr
{
private:
	T* _ptr;
	int* _pRefC;
public:
	//����RAIIָ��,���Բ��ᵥ����������ֻ��,���Բ���T*p.ֻ�����shared_ptrʹ��
	my_weak_ptr()
		:_ptr(nullptr)
		, _pRefC(nullptr)
	{}
	~my_weak_ptr() {}

	my_weak_ptr(my_shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		, _pRefC(sp._pRefCount)
	{}
	my_weak_ptr<T>& operator=(my_shared_ptr<T>& sp)
	{
		_ptr = sp.ptr;
		_pRefC = sp._pRefCount;
		return *this;
	}
public:
	my_shared_ptr<T> lock() const {
		if (expired()) {
			return my_shared_ptr<T>();
		}
		else {
			return my_shared_ptr<T>(*this);
		}
	}
	bool expired() const {
		return _pRefC == nullptr || *_pRefC == 0;
	}
public:
	T* operator->() { return _ptr; }
	T& operator*() { return *_ptr; }
};

class Node1
{
public:
	std::weak_ptr<Node1> next;
	~Node1()
	{
		cout << "��������" << endl;
	}
};
int main()
{
	std::shared_ptr<Node1> ptr1 = std::make_shared<Node1>();
	std::shared_ptr<Node1> ptr2 = std::make_shared<Node1>();

	ptr1->next = ptr1;
	ptr2->next = ptr1;
	system("pause");
	return 0;
}