#include<stdio.h>
#include<assert.h>
#include<string.h>
//ר�Ŵ����ڴ��ص�������
// dest < src, Ϊ�˱���ֵ�ĸ���,src��Ҫ��ǰ�������ο�����dest��
// dest > src && (char*)dest< (char*)src + count, Ϊ�˱���ֵ�ĸ���,src��Ҫ�Ӻ���ǰ���ο�����dest��
// (char*)dest >(char*)src + count,�����ڴ�û�н���,��ô��������
void* my_memmemove(void* dest, const void* src, size_t count)
{
	assert(dest && src);
	void* ret = dest;
	//src��ǰ����
	if (dest < src)
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	//�Ӻ���ǰ,ʹ��ָ���ƫ�����ķ�ʽ ptr+ count 
	else
	{
		while (count--) // ����count--,��ָ���λ��Ҳ����ǰ�ƶ�
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
void test_memmove1()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
	//   1 2 1 2 5 6 7 8 9 0------Ŀ��Ч��,���󿽱�
	my_memmemove(arr1 + 2, arr1, sizeof(arr1[0]) * 2);
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,0 };
	//   5 6 7 8 5 6 7 8 9 0------Ŀ��Ч��,��ǰ����
	my_memmemove(arr2, arr2+4, sizeof(arr2[0]) * 4);
}
//int main()
//{
//	test_memmove1();
//	system("pause");
//	return 0;
//}