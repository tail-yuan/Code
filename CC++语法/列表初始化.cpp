#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

class A
{
public:
	A(int a)
		:data(a)
	{
	}
private:
	int data;
};
class Point
{
public:
	Point(int a, int b)
		:x(a)
		, y(b)
	{}
private:
	int x;
	int y;
};
struct B
{
	int x;
	int y;
};
//int main()
//{
//	//1. �ں��������Ĺ��캯��,֧����ʿ����ת��
//	A a(1);
//	A a1 = 1;//int ->A
//	string str1 = "yuanwei";//const char* ->string
//	//2. �����֧����ʿ����ת��
//	Point p1{1,2};
//	//3. ����C����
//	B b{1,2};
//	//4. ��̬�����ʼ��(C++98��֧��)
//	int* ptr1 = new int[5] {1,2,3,4,5};
//	Point* ptr2 = new Point[2]{ { 1,2 }, { 3,4 } };
//	vector<int>v1{1,2,3,5};
//
//	map<int, int> my_map{{1, 2}, {3,4}};
//
//	//5. ���������б��ʼ��
//	int x1 = 10;
//	int x2{20};
//	int x3{1+2};
//	int arr1[5]{1};
//	int arr2[]{1,2,3,4,5};
//
//}