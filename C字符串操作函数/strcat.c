#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//�ַ���׷�Ӻ���,��dest��\0λ�ÿ�ʼ�滻,�Ὣsrc��\0Ҳ������ȥ
//destĿ��ռ��㹻��,�����γ��ڴ�Խ�����
void test_strcat()
{
	char arr1[20] = "yuanwei";
	char arr2[40] = "yuanwei\0yuanwei";
	char src[] = "hello";
	strcat(arr1, src);
	strcat(arr2, src);
	printf("%s\n",arr1); //yuanweihello
	printf("%s\n",arr2);//yuanweihello
}
//����destĿ��ռ����ʼ��ַ
char* my_strat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	//�ҵ���һ��\0
	while (*dest != '\0')
	{
		dest++;
	}
	//����
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
//�Լ����Լ���ֵ�������ѭ������,��Ϊsrc�ҵ��Ǹ�\0�Ѿ���dest�޸�Ϊ����ֵ��
//int main()
//{
//	test_strcat();
//	return 0;
//}