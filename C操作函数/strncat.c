#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
void test_strncat()
{
	//1. ��dest��\0��ʼ׷��,\0�Ǳ����ǵ�
	char dest[40] = "yuanwei\0XXXXXXXX";
	char src[] = "qwert";
	strncat(dest, src, sizeof(src));
	printf("%s\n", dest);
	//2. ��src.size() < numʱ,��������strncpyһ������num��
	strncat(dest, src, sizeof(src) + 5);
	printf("%s\n",dest);
}
char* strncat(char* dest,const char*src,size_t n)
{
	assert(dest && src);
	char* ret = dest;
	//���ҵ���һ��\0
	while (*dest != '\0') *dest++;
	//׷��
	while (n > 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return ret;
}
//int main()
//{
//	return 0;
//}