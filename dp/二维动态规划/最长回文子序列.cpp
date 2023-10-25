//https://leetcode.cn/problems/longest-palindromic-subsequence/

//�ⷨһ: str�����ĵ�����rstr�������������,����str�������������
//�ⷨ��: ����dp����
//��iλ��Ϊ��β,dp[i]��ʾ��������������Ļ��������еĳ���.
//��Ϊ��������,��ô��i-1���ַ�������[0,i-1]�ϵ�����һ��,ѡ��jλ����Ϊ�����ڶ���λ�ý�[i]�ַ���������,
// �����dp[i]=dp[j]+1�����޷��жϴ�ʱ�Ƿ��ǻ��Ĵ�.�������ֱ�ʾ����.
//dp[i][j]��ʾ[i,j]�����ڵ���������������Ļ��������еĳ���
//1. s[i]==s[j],
// 1.1 i==j =>��ֻ��һ���ַ�,1 
// 1.2 i+1=j =>�����������ַ�2 
// 1.3 i+1<j dp[i+1][j-1]+2(���Ǳ߽������ַ�) 
//  1.2 1.3�ϲ�,�����ʱ����i+1 j 0+2 �͵���2
// 
//2. s[i]!=s[j],
// 1.1 dp[i][j-1] 
// 1.2 dp[i+1][j] �ֱ��������������������ĳ���,ѡ�����ֵ����,
//   dp[i][j]=max(dp[i+1][j],dp[i][j-1])
//��ʼ��: ��ά����i=jλ���Ѿ������
//���˳��:  ��������,��������
//����ֵ: dp[0][n-1]


#include<iostream>
#include<vector>
using namespace std;
class Solution7
{
public:
	int longestPalindromeSubseq(string s)
	{
		int n = s.size();
		vector<vector<int>>dp(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; i--)
		{
			dp[i][i] = 1;//i==j,������Ϊ������,����j>i��ʼ��
			for (int j = i + 1; j < n; j++)
			{
				if (s[i] == s[j])
					dp[i][j] = dp[i+1][j-1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		return dp[0][n - 1];
	}
};
//https://www.bilibili.com/video/BV1WQ4y1W7d1?t=7021.8

//���仯����: ����dp��l<=r,����ֻ��Ҫ��дһ��ı����,����λ�����������.
class Solution8
{
	vector<vector<int>>memo;
public:
	int longestPalindromeSubseq(string s)
	{
		int n = s.size();
		memo = vector<vector<int>>(n, vector<int>(n));
		return dfs(s, 0, n - 1);
	}
	int dfs(string& s, int l, int r)
	{
		if (l == r)
			return 1;
		if (l + 1 == r)
			return s[l] == s[r] ? 2 : 1;
		if (memo[l][r] != 0)
			return memo[l][r];
		int ans = 0;

		if (s[l] == s[r])
			ans = dfs(s, l + 1, r - 1) + 2;
		else
			ans = max(dfs(s, l + 1, r), dfs(s, l, r - 1));
		memo[l][r] = ans;
		return ans;
	}
};
//�����ϸ�λ������,���������½�,��,��ĸ���
//�����Ǵ�������,��������
//https://www.bilibili.com/video/BV1WQ4y1W7d1?t=7551.4
//����ֵ�������Ͻǵĸ���
class Solution9
{
public:
	int longestPalindromeSubseq(string s)
	{
		int n = s.size();
		vector<vector<int>>dp(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; i--)
		{
			//��ά����,ÿһ��,����������������,
			dp[i][i] = 1;
			if (i + 1 < n)
				dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
			//Ȼ������
			for (int j = i + 2; j < n; j++)
			{
				if (s[i] == s[j])
					dp[i][j] = dp[i+1][j-1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		return dp[0][n - 1];
	}
};
//https://www.bilibili.com/video/BV1WQ4y1W7d1?t=8011.2
//�ռ��Ż�,����ά�����Ż�Ϊһά����,�������ϸ�������,
//����dp[j]λ��ʱ,��Ҫdp[j-1](�Ѹ���),dp[j](������,�����ֵ),���½ǵ�ֵ(leftdown)

class Solution10
{
public:
	int longestPalindromeSubseq(string s)
	{
		int n = s.size();
		vector<int>dp(n);
		int leftdown = 0, backup = 0;
		for (int l = n - 1; l >= 0; l--)
		{
			dp[l] = 1;//�Խ���λ��
			if (l + 1 < n)
			{
				leftdown = dp[l + 1];
				dp[l + 1] = s[l] == s[l + 1] ? 2 : 1;
			}
			for (int r = l + 2; r < n; r++)
			{
				backup = dp[r];
				if (s[l] == s[r])
					dp[r] = 2 + leftdown;
				else
					dp[r] = max(dp[r - 1], dp[r]);
				leftdown = backup;
			}
		}
		return dp[n-1];
	}
};