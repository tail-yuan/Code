#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
void test_strcmp()
{
	char arr1[] = "yuanwei";
	char arr2[] = "xiaowei";
	if (arr1 < arr2) { ; }//�����ڱȽ������ַ����ĵ�ַ
	if ("yuanwei" < "xiaowei") { ; } //���ڱȽ������ַ����ĵ�ַ
}
//�Ƚϵ��������ַ���,��Ӧλ���ϵ��ַ��Ĵ�С,ASCII��ֵ.
//������ͬ����\0��ֹ
//����ֵ��int,ret==0,������ͬ,ret<0,ǰС�ں�;
int my_strcmp(char* str1, char* str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
	//return *str1 - *str2;
}