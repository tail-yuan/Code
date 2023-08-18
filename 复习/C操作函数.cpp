#include<iostream>
#include<string.h>
#include<assert.h>
void test_memcmp()
{
	//���ڴ��а��ֽڽ��бȽ�,����С�˴洢�й�ϵ
	int arr1[10] = { 1,2,3,4,5,6 };
	int arr2[10] = { 1,2,3,4,5,0x11223306 };
	printf("%d\n", memcmp(arr1, arr2, sizeof(arr1[0]) * 5));//0
	printf("%d\n", memcmp(arr1, arr2, sizeof(arr1[0]) * 6));//-1
	printf("%d\n", memcmp(arr1, arr2, sizeof(arr1[0]) * 5 + 1));//0,С�˴洢��ʽ,06 ��6��һ�ֽ�����ȵ�
	printf("%d\n", memcmp(arr1, arr2, sizeof(arr1[0]) * 5 + 2));//-1
}
void test_memcpy()
{
	int arr1[10] = { 1,2,3,4 };
	int arr2[5] = { 0 };
	memcpy(arr2, arr1, sizeof(int) * 5);
}
void test_memmove()
{
	//ר�Ŵ����ڴ��ص������
}
void test_memset()
{
	//���ֽ�Ϊ��λ,�����ж���ʼ��Ϊ0
	int arr[10] = { 1,2,3,4,54 };
	memset(arr, 0, sizeof(arr));
}
/// <summary>
/// �������ַ���ϵ��
/// </summary>
void test_strcat()
{
	//�ַ���׷�Ӳ�������: ��dest�ĵ�һ��\0��ʼ�滻
	char arr1[20] = "yuanwei";
	char arr2[40] = "yuanwei\0yuanwei";
	char src[] = "hello";
	strcat(arr1, src);
	strcat(arr2, src);
	printf("%s\n", arr1); //yuanweihello
	printf("%s\n", arr2);//yuanweihello
}
void test_strcmp()
{
	char arr1[] = "yuanwei";
	char arr2[] = "xiaowei";
	//�ַ�������������Ԫ�ص�ַ
	if (arr1 < arr2) { ; }//�����ڱȽ������ַ����ĵ�ַ
	if ("yuanwei" < "xiaowei") { ; } //���ڱȽ������ַ����ĵ�ַ
	int ret = strcmp("yuanwei", "xiaoawei");
}
void test_strcpy()
{
	//1. dest��������\0Ϊ��β��,����ע���ַ�����,��dest��\0��ʼ
	char dest1[] = "yuawnei";
	char dest2[10] = {'a','b','c'};//�����Ŀռ���Զ���\0
	char dest3[] = { 'a','b','c' };//error
	char dest4[] = { 'a','b','c','\0'};
	//2. src�Ὣ�Լ���\0����ȥ
	//3. dest�ռ�Ԥ������
	//4. dest�����ǿɱ���ַ���,������const char* 
	char dest1[20] = "zhendenoiuno";//�����ַ����ǲ����޸ĵ�
}
void test_strerror()
{
	//���ݴ�����,��ӡ������������Ϣ
	//�Ż�֮���perror("diy")�Զ����ӡ��Ϣ
}
void test_strlen()
{
	//1. ��ȡ��\0����ֹ,����
	//2. ����ֵ��size_t����,���֮������Ϊ�Ǹ���,��ʼ��ת��Ϊһ���ܴ������,ע��ʹ��
}
void test_strncat()
{
	//׷�Ӷ��ٸ�������: ע��Ŀ��ռ�һ��Ҫ����
	//ʵ��ʱ,��ΪԼ���˸���,����src��\0��û�����뵽dest��,��͵��ֶ�����һ��\0
}
void test_strstr()
{
	//����s2��s1�е���ʼλ��,����ʹ��KMP�㷨
}
void test_strtok()
{
	//�и��ַ���
	//���ָ���λ�ø�Ϊ\0,���������ʼλ��ָ�뷵��,�õ��зֳ����Ĳ����ַ���
	//ͬʱ��¼���зֵ�λ�ü����滻Ϊ\0��λ��,Ȼ����һ���ٴ����λ�ÿ�ʼ�����������һ�����
	char arr[] = "yuanwei@yeah.net@12306.666";
	//��Ϊ�зֵĹ��̻ὫԴ���ݸ���,����һ�㶼��������һ�ݿ������в���
	char buffer[30] = { 0 };
	strcpy(buffer, arr);
	const char* sep = "@.";//�ָ����ǿո�Ҳ��֧�ֵ�
	//����һ�ε���,�����Ǿ���strָ��
	char* str = strtok(buffer, sep);
	for (; str != NULL; str = strtok(NULL, sep))
	{
		//printf();
	}
	for (; str != NULL; str = strtok(NULL, sep))
	{
		printf("%s ", str);//yuanwei yeah net 12306 666
	}
}
int main()
{
	test_memcpy();
	system("pause");
	return 0;
}

namespace yuanwei
{
	char* my_strstr(char* str1, char* str2)
	{
		assert(str1 && str2);
		char* s1 = str1, * s2 = str2;
		char* cur = s1;
		while (*cur)
		{
			while (*s1 == *s2)
			{
				s1++;
				s2++;
			}
			if (*s2 == '\0')//����Ѿ���ȵ��˽�β
				return cur;
			cur++;		//�������һ��λ�����¿�ʼƥ��
			s1 = cur;
			s2 = str2;
		}
	}
	char* my_strnpy(char* dest, char* src, int count)
	{
		assert(dest && src);
		char* ret = dest;
		while (count-- && (*dest++ = *src++))
		{
			;
		}
		//src������,���ǻ�û��count���ͻ��ֶ���0
		while (count-- > 0)
			*dest++ = '\0';
		return ret;
	}
	int strncmp(const char* s1, const char* s2,int count)
	{
		assert(s1 && s2);
		while (*s1 == *s2 && count--)
		{
			if (*s1 == '\0')
				return 0;
			s1++; s2++;
		}
		if (count == 0)return 0;
		else
			return *s1 - *s2;
	}
	char* my_strncat(char* dest,char* src,int count)
	{
		assert(dest && src);
		char* ret = dest;
		//Ѱ�ҵ�һ��\0
		while (*dest++) { ; }
		while (count-- && *src!='\0')
		{
			*dest = *src;
			dest++, src++;
		}
		*dest = '\0';
		return ret;
	}
	size_t my_strlen(char* s)
	{
		assert(s);
		int count = 0;
		while (*s)
		{
			count++;
			s++;
		}
	}
	char* my_strcpy(char* dest, char* src)
	{
		assert(dest && src);
		char* ret = dest;
		while (*dest++ = *src++)
		{
			;
		}
		return ret;
	}
	int my_strcmp(const char* s1, const char* s2)
	{
		while (*s1 == *s2)
		{
			if (*s1 == '\0')//һֱ��ͬ����β�����,�������,�����ﷵ��
				return 0;
			s1++;
			s2++;
		}
		//������ζ�Ų�����ͬ
		return *s1 - *s2;
	}
	char* my_strcat(char* dest, char* src)
	{
		assert(dest && src);
		char* ret = dest;
		while (*dest != '\0')
		{
			dest++;
		}
		//while (*src != '\0')
		while(*dest++ = *src++)
		{
			//*dest++ = *src++;
			;
		}
		return ret;
	}
	void* my_memcpy(void* dest,void* src,size_t n)
	{
		assert(dest && src && n > 0);
		void* ret = dest;
		while (n--)
		{
			*(char*)dest = *(char*)src;//�����ֽڽ��п���;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
		return ret;
	}
	void* my_memmove(void* dest, void* src, size_t count)
	{
		assert(dest && src);
		if (dest < src)//��ǰ�������src
		{
			int index = 0;
			while (index < count)
			{
				*((char*)dest + index) = *((char*)src + index);
				index++;
			}
		}
		else
		{
			while (count--)
			{
				*((char*)dest + count) = *((char*)src + count);
			}
		}
		return dest;
	}
}