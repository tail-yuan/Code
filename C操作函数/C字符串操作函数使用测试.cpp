#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//strcpy vs strncpy
void test1()
{
	const char* source = "hello world!";//����Ĭ��Я��\0
	char dest[20];						//��\0Ҳ����˽�ȥ
	strcpy(dest,source);	//strcpyֻ�Ὣsource������dest��,��\0��β.
	char dest3[5];
	//strcpy(dest3,source);	//dest3�ռ䲻����,���ֱ���
	cout << "Copied string :" << dest << endl;

	char dest2[30];
	strncpy(dest2,dest,sizeof(source)); //source.size()< dest[20],��source.size���ַ��ŵ�dest2��,����Ĭ�����\0,��ɱ���
	//�����������strcnpy֮��,�ֶ��ڽ�β�����\0��Ϊ�ս��־.ע:��Сλ��size,�±��0��ʼ�Ļ�����size-1
	dest2[sizeof(source)-1]='\0';
	strncpy(dest2,dest,sizeof(dest)); //source.size()< dest[20],���Բ���20�Ĳ���,strnpy��\0��ΪĬ������ַ�,������˵�õ�20���Ŀ�ȱλ��
	cout << "Copied string :" << dest2 << endl;
}
//memcpy vs memmove 
void test2()
{
	const char* source = "hello,world";
	char buffer[20];
	std::memcpy(buffer, source, std::strlen(source)+1);//strlen����\0��ֹ,���Ҳ����¼\0����,����Ҫ+1��\0����,���������ַ���
	cout << "memcpy string :" << buffer << endl;//memcpy string : hello, world
	

	char dest[20] = "hello,world";
	char* dest1 = buffer + 4;
	std::memmove(dest1,dest,strlen(dest)+1);
	cout << "memcnpy/memmove string :" << buffer << endl;//memcnpy / memmove string : hellhello, world
		
}
//split����ʵ��,ʹ��strtok()����
vector<string>mySplit(string& str,string& pattern)
{
	char* tmp = new char[str.size()+1];
	strcpy(tmp,str.c_str());
	vector<string>res;
	char* retStr = strtok(tmp,pattern.c_str());
	while (retStr != nullptr)
	{
		res.push_back(retStr);
		retStr = strtok(nullptr,pattern.c_str());
	}
	delete[] tmp;
	return res;
}
//int main()
//{
//	test2();
//}