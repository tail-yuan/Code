#include<iostream>
using namespace std;
//���ݶ���������ҹ���
//��������ΪO(1)���Ӷ�
class Solution
{
public:
	int minBags(int apples)
	{
		int ans = func(apples);
		return ans == INT_MAX ? -1 : ans;
	}
	//����restʣ����ٸ�ƻ��,ʹ��6,8���ӱ���װ��,������Ҫ���ٸ�����
	int func(int rest)
	{
		//������Ч��,����һ��rest-8�õ���,���<0,˵��������8�Ĵ���װ��
		if (rest < 0)
			return INT_MAX;
		if (rest == 0)//�Ѿ�û��ƻ����,��Ȼ����Ҫ������
			return 0;
		int p1 = func(rest - 8);
		int p2 = func(rest - 6);
		if (p1 != INT_MAX)
			p1 += 1;
		if (p2 != INT_MAX)
			p2 += 1;
		return min(p1, p2);
	}
public:
	int minBages2(int n)
	{
		if (n % 2 != 0)return -1;
		if (n < 18)
		{
			if (n == 6 || n == 8)
				return 1;
			else if (n == 12 || n == 14 || n == 16)
				return 2;
			else
				return -1;
		}
		return (n - 18) / 8 + 3;
	}
};
//int main()
//{
//	Solution s;
//	for (int i = 1; i <= 50; i++)
//	{
//		cout << i << ": " << s.minBags(i) <<"<->"<<s.minBages2(i) << endl;
//	}
//	return 0;
//}