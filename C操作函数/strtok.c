#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//�и��ַ���
//���ָ���λ�ø�Ϊ\0,���������ʼλ��ָ�뷵��,�õ��зֳ����Ĳ����ַ���
//ͬʱ��¼���зֵ�λ�ü����滻Ϊ\0��λ��,Ȼ����һ���ٴ����λ�ÿ�ʼ�����������һ�����
//�϶�ʹ���˾�̬�������м�¼ָ����,
void test_strtok()
{
	char arr[] = "yuanwei@yeah.net@12306.666";
	//��Ϊ�зֵĹ��̻ὫԴ���ݸ���,����һ�㶼��������һ�ݿ������в���
	char buffer[30] = { 0 };
	strcpy(buffer, arr);
	const char* sep = "@.";//�ָ����ǿո�Ҳ��֧�ֵ�
	//����һ�ε���,�����Ǿ���strָ��
	char* str = strtok(buffer,sep);
	for (; str != NULL; str = strtok(NULL, sep))
	{
		printf("%s ",str);//yuanwei yeah net 12306 666
	}
}
//int main()
//{
//	test_strtok();
//	return 0;
//}