#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//�ж�str2�ǲ�����str1��,�ж��ڲ���,���ڷ���nullptr,��,���ص�һ�γ��ֵĵ�ַ
char* my_strstr(const char* str1, const char* str2);
void test_strstr()
{
	char str1[] = "yuanwei";
	char str2[] = "wei";
	char* ret1 = my_strstr(str1,str2);
	char* ret2 = strstr(str1,str2);
	if (ret1)
		printf("%s\n",ret1);
}
char* my_strstr( const char* str1, const  char* str2)
{
	assert(str1 &&str2);

	const char* s1 = str1, * s2 = str2;   //����const ���ⲻ��ʱ�Ͳ����б�constchar* Ȩ�޷Ŵ������
	char* cur = str1;
	while (*cur)//��ÿһ���ַ�����Ϊ��ʼ�ַ������ܲ���ƥ��str2
	{
		while (*s1 && *s2 && *s1 == *s2)//*s!='\0'
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0') return cur;
		//else˵���Դ�ʱ��cur��ͷû��ƥ��ɹ�
		cur++;//����һ���ַ���ʼ��ƥ��
		//����ָ���ٻ�ָ�������ַ�������ʼλ��
		s1 = cur;
		s2 = str2;
	}
	return NULL;
}
//int main()
//{
//	test_strstr();
//	return 0;
//}