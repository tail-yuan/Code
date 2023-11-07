//https://leetcode.cn/problems/scramble-string/
#include<iostream>
#include<vector>
using namespace std;
//https://www.bilibili.com/video/BV1gM41197rM?t=5540.6
//����dp���ۣ�
//��Ϊ���֣������ǲ�������Ȼ�����Ҵ������Գ��ȶ�Ӧ������ͬ��
//1. ������ģ� isTrue(s1[0,i],s2[0,i]) && isTrue(s1[i+1,n-1],s2[i+1,n-1])
//2. ����ģ� isTrue(s1[0,i],s2[n-i,n]) && isTrue(s1[i+1,n],s2[0,n-i-1])
class Solution
{
public:
	bool isScramble(string s1, string s2)
	{
		int n = s1.size();
		return func1(s1, s2, 0, n - 1, 0, n - 1);
	}
	// �ǲ������Ҵ��Ĺ�ϵ
	bool func1(string& s1, string& s2, int l1, int r1, int l2, int r2)
	{
		//ֻʣ�����һ���ַ���ֻ��Ҫ�ж��Ƿ���ȼ���
		if (l1 == r1)
			return s1[l1] == s2[l2];
		//������
		// s1[l1..i][i+1....r1]
		// s2[l2..j][j+1....r2]
		for (int i = l1, j = l2; i < r1; ++i, j++)
		{
			if (func1(s1, s2, l1, i, l2, j) && func1(s1, s2, i + 1, r1, j + 1, r2))
				return true;
		}
		//����
		// s1[l1..........i][i+1...r1]
		// s2[l2...j-1][j..........r2]
		for (int i = l1, j = r2; i < r1; j--, i++)
		{
			if (func1(s1, s2, l1, i, j, r2) && func1(s1, s2, i + 1, r1, l2, j - 1))
				return true;
		}
		return false;
	}
};
//�ĸ��ɱ���������볤����ͬlen,����ֻҪl1,l2,len�Ϳ�
//0 ��ʾûչ����
//1 true
//-1 false
class Solution21
{
	vector<vector<vector<int>>> memo;
public:
	bool isScramble(string s1, string s2)
	{
		int n = s1.size();
		memo = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n+1)));
		return func(s1, s2, 0, 0, n);
	}
	bool func(string& s1, string& s2, int l1, int l2, int len)
	{
		if (len == 1)
			return s1[l1] == s2[l2];
		if (memo[l1][l2][len] != 0)
			return memo[l1][l2][len]==1;
		bool ans = false;
		//s1���k��ƥ��s2���k��-��������
		for (int k = 1; k < len; k++)
		{
			if (func(s1, s2, l1, l2, k) && func(s1, s2, l1 + k, l2 + k, len - k))
			{
				ans = true;
				break;
			}
		}
		//����
		if (ans == false)
		{
			for (int i = l1 + 1, j = l2 + len - 1, k = 1; k < len; i++, j--, k++)
			{
				if (func(s1, s2, l1, j, k) && func(s1, s2, i, l2, len - k))
				{
					ans = true;
					break;
				}
			}
		}
		memo[l1][l2][len] = ans?1:-1;
		return ans;
	}
	bool _func(string& s1, string& s2, int l1, int l2, int len)
	{
		if (len == 1)
			return s1[l1] == s2[l2];

		//s1���k��ƥ��s2���k��-��������
		for (int k = 1; k < len; k++)
		{
			if (_func(s1, s2, l1, l2, k) && _func(s1, s2, l1 + k, l2 + k, len - k))
				return true;
		}
		//����
		for (int i = l1 + 1, j = l2 + len - 1, k = 1; k < len; i++, j--, k++)
		{
			if (_func(s1, s2, l1, j, k) && _func(s1, s2, i, l2, len - k))
				return true;
		}
		return false;
	}
};

//https://www.bilibili.com/video/BV1gM41197rM?t=6598.4
//ͬ����l1,l2Ϊ��ά��Ȼ��len��Ϊ�߶Ȳ���⣬����len������len-k,���Դ���
//�Ͳ������֮����Ȼ�Ϳ�����д�߲�
//��ʼ���� ��д��һ��
//ÿ�����Ӷ���Ҫ����ö�٣�����O(N^4)

class Solution22
{
public:
	bool isScramble(string s1, string s2)
	{
		int n = s1.size();
		vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(n,vector<bool>(n+1)));
		for (int l1 = 0; l1 < n; l1++)
		{
			for (int l2 = 0; l2 < n; l2++)
				dp[l1][l2][1] = s1[l1] == s2[l2];
		}
		for (int len = 2; len <= n; len++)
		{
			for (int l1 = 0; l1 <= n - len; l1++)//�ڵݹ��������Щ���Ӳ��ᱻ������������û����д������
			{
				for (int l2 = 0; l2 <= n - len; l2++)
				{
					for (int k = 1; k < len; k++)
					{
						if (dp[l1][l2][k] && dp[l1 + k][l2 + k][len - k])
						{
							dp[l1][l2][len] = true;
							break;
						}
					}
					if (!dp[l1][l2][len])
					{
						for (int i = l1 + 1, j = l2 + len - 1, k = 1; k < len; i++, j--, k++)
						{
							if (dp[l1][j][k] && dp[i][l2][len - k]) 
							{
								dp[l1][l2][len] = true;
								break;
							}
						}
					}
				}
			}
		}
		return dp[0][0][n];
	}
};