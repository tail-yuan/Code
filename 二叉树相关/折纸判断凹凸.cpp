#include<iostream>
using namespace std;

//����n��,�����������ɶ������ṹ,���ڵ���ڵ㶼Ϊ��,�ҽڵ㶼Ϊ͹
void printProcess(int i, int n, bool down)
{
	if (i > n)return;
	printProcess(i+1,n,true);
	cout << down ? "��" : "͹";
	printProcess(i+1,n,false);
}
void print(int n)
{
	printProcess(i, n, true);
}