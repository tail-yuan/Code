#include<iostream>
using namespace std;
//12 =3+4+5 true
//��ÿһ����㿪ʼ������������,��һ�������ܹ����ɾͷ���true
class Solution
{
public:
	bool isTrue(int n)
	{
		for (int start = 1, sum = 0; start <= n; start++)
		{
			sum = start;
			for (int j = start + 1; j <= n; j++)
			{
				if (sum + j > n)
					break;
				else if (sum + j == n)
					return true;
				else
					sum += j;
			}
		}
		return false;
	}
public:
	//���������2^x�Ͳ��ܱ�ʾ,���������Ա�ʾ
	bool isTrue2(int n)
	{
		return (n & (n - 1)) != 0;
	}
};
//int main()
//{
//	Solution s;
//	for (int i = 1; i <= 50; i++)
//	{
//		cout << i << ":" << s.isTrue(i) << endl;
//	}
//	return 0;
//}