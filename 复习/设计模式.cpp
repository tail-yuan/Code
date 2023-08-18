#include<iostream>
#include<vector>
using namespace std;
//����ģʽ
//ʵ�ֹ�����������Ϳͻ��˴������.��֮����������ͼ��ʱ,ֻ��Ҫ�޸Ĺ����Ĵ���,�ͻ���ֱ�Ӵ����þ���
class Shape
{
public:
	virtual void draw() = 0;
};
class Circle :public Shape
{
public:
	void draw()
	{}
};
class Rectangle :public Shape
{
public:
	void draw()
	{}
};
class ShapeFactory
{
public:
	static Shape* getShape(const string& s)
	{
		if (s == "Circle")
			return new Circle();
		else if (s == "Rectangle")
			return new Rectangle();
		else
			return nullptr;
	}
};
void test_Factory()
{
	Shape* circle = ShapeFactory::getShape("Cirlce");
}
//�۲���ģʽ: 
//ʵ�ֶ���֮��һ�Զ��������ϵ,��һ���������仯ʱ,��������Ҫ����״̬����
//1. ֻ��Ҫ��ע���۲��ߵ�״̬
//2. ���۲����й۲��ߵ�ע���,�������Ӻ�ɾ���۲��ߺ͹㲥�۲��߸���״̬
//3. ���ֻ��ƿ��Գ���Ϊ����ģ��,���۲��߸����¼��ķ���,�۲�����Ϊ������ͨ��ע�ᶩ�Ĺ�ϵ�����¼���������Ӧ
class Observer
{
public:
	virtual void update() = 0;
};
class Subject
{
public:
	void add(Observer* ob)
	{
		observers.push_back(ob);
	}
	void erase(Observer* ob)
	{
		auto it = find(observers.begin(), observers.end(),ob);
		if (it != observers.end())
			observers.erase(it);
	}
	virtual int getState()const = 0;
public:
	void notify()//�㲥����
	{
		for (auto e : observers)
		{
			e->update();
		}
	}
private:
	vector<Observer*> observers;
};
class CncrectSub : public Subject
{
public:
	int state;
	void set()
	{}
	void reset()
	{}
	int getState() const override
	{}
};
class ConcrectObs : public Observer
{
public:
	CncrectSub* cb;
	ConcrectObs(CncrectSub* sb)
		:cb(sb)
	{}
public:
	virtual void update() override
	{
		int s = cb->getState();
		std::cout << "Observer: Received state update. New state is " << s << std::endl;
	}
};
//����ģʽ
//����ģʽ
class Single
{
public:
	static Single* getInstance()
	{
		return ins;
	}
private:
	Single()
	{}
	Single(Single& sp) = delete;
	Single operator=(Single& sp) = delete;
private:
	int a;
	static Single* ins;
};
Single* Single::ins = new Single();
//����ģʽ:
class Single
{
public:
	static Single* getInstance()
	{
		return new Single();
	}
private:
	Single()
	{}
	Single(Single& sp) = delete;
	Single operator=(Single& sp) = delete;
private:
	int a;
	static Single* ins;
};
Single* Single::ins = nullptr;

//����������
//1. ֻ���ڶ�������ռ�
template<class T>
class HeapOnly
{
public:
	HeapOnly<T>* get()
	{
		return new HeapOnly<T>();
	}
private:
	HeapOnly()
	{}
	HeapOnly(const HeapOnly<T>& sp) = delete;
private:
	T a;
};
//2. ֻ����ջ������ռ�
//����operator new operator delete��ͬʱ,�����캯��Ҳ����Ϊ˽��
//new = operator new+���캯��
//���캯��˽�в���ʵ����������,�͵ø��˼�һ�����Բ�ͨ������Ϳ��Ե��õĺ���,������һ������static��Ա����
class StackOnly
{
public:
	static StackOnly get()
	{
		return StackOnly();
	}
private:
	StackOnly()
		:a(1)
	{}
	void* operator new(size_t x) = delete;
	void operator delete(void* p) = delete;
private:
	int a;
};
//3. ���ܱ��̳е���
//C++11ʹ��final C++98�����캯������Ϊ˽��
class B final
{};
class A
{
public:
	static A getA()
	{
		return A();
	}
private:
	A()
	{}
};
