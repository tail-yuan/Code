#include<stdio.h>
#include<assert.h>
#include<string.h>
//���ֽڽ��бȽ�
void test_mermcpy()
{
	int arr1[10] = {1,2,3,4,5,6};
	int arr2[10] = { 1,2,3,4,5,0x11223306 };
	printf("%d\n",memcmp(arr1, arr2, sizeof(arr1[0]) * 5));//0
	printf("%d\n",memcmp(arr1, arr2, sizeof(arr1[0]) * 6));//-1
	printf("%d\n",memcmp(arr1, arr2, sizeof(arr1[0]) * 5 + 1));//0,С�˴洢��ʽ,06 ��6��һ�ֽ�����ȵ�
	printf("%d\n",memcmp(arr1, arr2, sizeof(arr1[0]) * 5 + 2));//-1
}
//int main()
//{
//	test_mermcpy();
//	return 0;
//}