#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//1. ԭ�ַ���������\0��β
void test1()
{
	char src1[] = "yuanwei";
	char dest1[20] = {0};
	strcpy(dest1,src1);
	printf("%s\n", dest1); //yuanwei


	char src2[] = { 'a','b','c' };
	char dest2[20] = { 0 };
	strcpy(dest2, src1);
	printf("%s\n", dest2); //fatal

	char src3[10] = { 'a','b','c' };
	char dest3[20] = { 0 };
	strcpy(dest3, src1);
	printf("%s\n", dest2); //abc
}

//2. �Ὣԭ�ַ����е�\0Ҳ������ȥ(���Ӵ��ڲ鿴)
void test2()
{
	char dest[20] = "XXXXXXXX";
	char src1[] = "abcd";
	strcpy(dest, src1);

}
//3. Ŀ���ַ��������������㹻��,�������.��Ŀ�껺�����ռ��ƻ�
void test3()
{
	char src1[] = "yuanwei";
	char dest1[4] = { 0 };
	strcpy(dest1, src1);
	printf("%s\n", dest1); //fatal
}
//4. Ŀ��ռ����ɱ�
void test4()
{
	char src1[] = "yuanwei";
	char dest1[20] = "zhendenoiuno";//�����ַ����ǲ����޸ĵ�
	strcpy(dest1, src1);
	printf("%s\n", dest1); //fatal
}
//strcpy����ֵ��Ŀ��ռ����ʼ��ַ
//�з���ֵ��Ϊ��ʵ����ʽ���� printf("%s",strcpy(dest,src));
char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char*  ret = dest;
	while(*dest ++ =*src++)//while�жϵ���ÿһ��*dest,�����һ�α���ֵΪ0ʱ,�˳�ѭ��
	{
		;
	}
	//while (*src != '\0')
	//{
	//	*dest++ = *src++;
	//}	
	//*dest = *src;//������\0����
	return ret;
}
//int main()
//{
//	test1();
//	return 0;
//}