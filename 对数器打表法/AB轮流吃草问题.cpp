#include<iostream>
using namespace std;
//AB�����Բ�,һ��n�ݲ�,ÿ�γԵ�ʱ����ѡ��4^x�ݲ�,x>=0
//˭��������޲ݿɳԵĳ���,˭��.
//�ʳ���ʱ˭��Ӯ?����AB���������Լ�Ӯ
class Solution
{
public:
	string win(int n)
	{
		return func(n, "A");
	}
	//��ʣ��rest�ݲ�ʱ,ѡ����cur,��������˭��Ӯ
	//<4ʱֻ��һ��һ�ݳ�,=4ʱֱ�ӳ��˾�Ӯ��
	//rest: 0  1   2   3   4  
	//win:    cur     cur  cur
	string func(int rest, string cur)
	{
		string enemy = cur == "A" ? "B" : "A";
		if (rest < 5)
		{
			if (rest == 0 || rest == 2)
				return enemy;
			else return cur;
		}
		//cur��ʼ����,�ֱ���1,4,16,64,...ʱ���������Լ��ܲ���Ӯ
		int pick = 1;
		while (pick <= rest)
		{
			if (func(rest-pick, enemy) == cur)
				return cur;
			pick *= 4;
		}
		//������һ��,�����Լ���Ӯ����
		return enemy;
	}
public:
	string win2(int n)
	{
		if (n % 5 == 0 || n % 2 == 0)
			return "B";
		else
			return "A";
	}
};
//int main()
//{
//	Solution s;
//	for (int i = 1; i <= 50; i++)
//	{
//		cout << i << ":" << s.win(i) << endl;
//	}
//	return 0;
//}