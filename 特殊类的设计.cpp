#include<iostream>
using namespace std;
//һ.ֻ���ڶ�����ƶ���
//1. ���캯���϶�˽�л�,��������Ҳɾ��
//2. ��̬��Ա�������ض���,��ʹ��newʵ���ڶ���.�������ں����͵��ж���,�ж����ǰ�����й��캯��,
//Ϊ�˱�������ʹ�þ�̬��Ա��������������,ʹ����������
class HeapOnly
{
public:
	static HeapOnly* get()
	{
		return new HeapOnly();
	}
	void print()
	{
		cout << _a << endl;
	}
private:
	HeapOnly():_a(0) {}
	HeapOnly(const HeapOnly& hp) = delete;
private:
	int _a;
};
int main1()
{
	HeapOnly* ins = HeapOnly::get();
	ins->print();
	return 0;
}
//��. ֻ����ջ�ϴ�������.����new,�ײ���õ���operator new
//1. Ϊ��Ҫ�����캯��˽�л���?
//		ȷ������Ĺ��캯��������������ִ���κζ�̬�ڴ���䣨����ʹ��new����������Ҫ�ֶ��ͷŵ���Դ��
//		��Ϊnew���ǵ�����Ĺ��캯��+��ʼ��
//2. ������ĳ�Ա�����ͷ������Ϊ�������� ��̬�ڴ���� �����ͺͲ�����
//3. �����ڶ���Ĺ��캯�������������е����������ܵ��¶�̬�ڴ����ĺ�����
//4. ����Ҫ����������������У�ֱ����������ı��������磬�����ں����ڲ���������ľֲ�������
class StackOnly
{
public:
	static StackOnly get()
	{
		return StackOnly();
	}
	void print()
	{
		cout << _a << endl;
	}
private:
	StackOnly() :_a(0) {};
	void* operator new(size_t x) = delete;//���亯����һ������������size_t ����
	void operator delete(void *p) = delete;
private:
	int _a;
};
int main2()
{
	StackOnly obj = StackOnly::get();
	obj.print();
	system("pause");
}
//��.���಻�ܷ�������
//����ģʽ����ģʽ:����ʼ��ʱ���Ԥ������.ʹ�ö���ģʽ�ĵ���ģʽ���Ա�֤�ڳ�������ʱ�ʹ���ʵ����
// ������̰߳�ȫ�ġ�
//Ȼ���������ܻᵼ�³�������ʱ�����ܿ�������Ϊʵ�����ڳ���ʼʱ�ͱ������������Ƿ���Ҫʹ�ø�ʵ����
class NoCopy
{
public:
	NoCopy* getInstance()
	{
		return ins;
	}
private:
	NoCopy() {};//����Ϊ˽��,�����޷�ʹ��new
	NoCopy(const NoCopy& np) = delete;
	NoCopy operator=(const NoCopy& np) = delete;
private:
	int _a;
	static NoCopy* ins;
};
NoCopy* NoCopy::ins = new NoCopy();
//����ģʽ����ģʽ:�ȵ�����õ�ʱ���ٴ���,�漰���̰߳�ȫ����
class Single
{
public:
	Single* getIns()
	{
		ins = new Single();
		return ins;
	}
private:
	Single() {};//����Ϊ˽�б�delete,�����޷�ʹ��new
	Single(const Single& np) = delete;
	Single operator=(const Single& np) = delete;
private:
	int _a;
	static Single* ins;
};
 Single* Single::ins=nullptr;

//��.����಻�ܱ��̳�
//��ֹ������Ӹ������� C++11ʹ��final C++98�����캯������Ϊ˽��,�����޷��������޷�ʵ�ֳ�ʼ���޷�����
 class NoInherit final
 {
 public:

 };
 class A
 {
 public:
	 static A* get()
	 {}
 private:
	 A() {}
 };