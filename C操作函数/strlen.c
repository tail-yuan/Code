#include<stdio.h>
#include<string.h>
#include<assert.h>
//�÷�:����\0��ֹ,�����ַ�������
void test_strlen1()
{
	//str1 ��βĬ����\0
	char str1[] = "yuanwei";
	printf("%d\n",strlen(str1));//7
	//str2��β��û��\0,strlen��һֱ�����,ֱ������\0,��������ʲô�Ƿ�λ�þͲ�֪����
	char str2[] = {'a','b','c','d'};
	printf("%d\n", strlen(str2));//122,���ֵ,ÿ�ض����ܲ�һ��

	//str3,Ԫ���а���һ��'\0',��������ֹ
	char str3[] = { 'a','b','c','d','\0'};
	printf("%d\n", strlen(str3));//4

	//str5,'\0'����Ԫ���Ƕ�������
	char str5[] = { 'a','b','c','d','\0','a','c'};
	printf("%d\n", strlen(str5));//4

	//str4 ��10���ֽڴ�С�ռ�,���ǳ�ʼ��ʱֻ��4��,��ôĬ��ʣ�µ�6���ط���������\0
	char str4[10] = {'a','b','c','d'};
	printf("%d\n", strlen(str4));//4
}
//����ֵ��size_t ����
void test_strlen2()
{
	//error use case1: ����ֵ��size_t ����,�޷�������,���֮���Ǹ�������һ���ܴ������ 
	if (strlen("abcd") - strlen("bcdefg") > 0)
		printf(">\n");//��ӡ����>
	else 
		printf("<=\n");
	//correct use case2:
	if (strlen("abcd") > strlen("bcdefg"))
		printf(">\n");
	else
		printf("<=\n");//��ӡ����<=

	//correct use case3:
	if ((int)strlen("abcd") - (int)strlen("bcdefg") >0)
		printf(">\n");
	else
		printf("<=\n");//��ӡ����<=
}
size_t my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
//int main()
//{
//	test_strlen2();
//	return 0;
//}