#include<stdio.h>
#include<assert.h>
#include<string.h>
//����Ŀ��ռ����ʼ��ַ
//ǿתΪchar*��Ҫ��Ϊ��һ���ֽ�һ���ֽڵĴ�src������dest�ռ���
void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest && src);
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;	//dest�޷�++,ֻ�ܲ���(char*)dest+1�ķ�ʽ
		src = (char*)src + 1;
	}
	return ret;
}
void test_memcpy1()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
				//   1 2 1 2 3 4 5 8 9 0------Ŀ��Ч��
				//   1 2 1 2 1 2 1 8 9 0------ʵ��Ч��,��Ϊmemcpy�޷������ڴ��ص������
	my_memcpy(arr1+2,arr1,sizeof(arr1[0])*5);
}
void test_memcpy2()
{
	int arr1[10] = {1,2,3,4,5,6,7,8,9,0};
	int arr2[5] = {0};
	my_memcpy(arr2,arr1,sizeof(arr1[0])* 5);//count ������ٸ��ֽ�
}
//int main()
//{
//	test_memcpy1();
//	return 0;
//}