

#include<stdio.h>
#include<stdarg.h>
int FindMax(int num, ...)
{
	va_list arg;
	va_start(arg, num);
	int max = va_arg(arg,int);
	for (int i = 0; i < num - 1; i++)
	{
		int cur = va_arg(arg,int);
		if (max < cur)
			max = cur;
	}
	va_end(arg);
	return max;
}
//int main()
//{
//	int ret = FindMax(5,0x11,0x22,0x33,0x44,0x55);
//	printf("%d\n",ret);
//}