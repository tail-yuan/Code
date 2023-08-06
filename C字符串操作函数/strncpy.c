#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

void test_strncpy()
{
	char dest[20] = "yuanwei";
	char src[] = "qwerty";
	strncpy(dest,src,sizeof(src));
	printf("%s\n",dest);//qwerty

	//src<numʱ,�����Ĳ��ֻ�Ĭ����\0���,��ؽǶ�С��������
	strncpy(dest, src, sizeof(src)+10);
	printf("%s\n", dest);//qwerty
}
//����Ŀ��ռ����ʼ��ַ
char* my_strncpy(char* dest, const char* src, size_t n)
{
	assert(dest && src);
	char* ret = dest;
	while (n > 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return ret;
}
//int main()
//{
//	test_strncpy();
//	return 0;
//}