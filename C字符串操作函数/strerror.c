#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
#include<limits.h>
//���ݴ����뷵�ش�����Ϣ,char* strerror(errno);
void test_strerror()
{
	printf("%s\n",strerror(0));
	printf("%s\n",strerror(1));
	printf("%s\n",strerror(2));
	printf("%s\n",strerror(3));
	//����ϵͳ���ú���ʱ,������Ϣ���Զ��ŵ�errnoȫ�ֱ�����
	int* p1 = (int*)malloc(40);
	int* p = (int*)malloc(INT_MAX);
	if (p == NULL)
	{
		printf("%s\n",strerror(errno));//not enough space
		perror("malloc"); //"malloc: not enough space"
		return 1;
	}
}
//int main()
//{
//	test_strerror();
//	return 0;
//}