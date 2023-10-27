//https://leetcode.cn/problems/distinct-subsequences/
//dp[i][j]��ʾs[ǰ׺����Ϊi ]��������ƥ��t[ǰ׺����Ϊj ]�Ӵ��ķ�����
//�������һ��λ��,s[i]λ�ÿ��Բ�ѡ��,����sǰi-1��ȥƥ��t��ǰj��,��dp[i][j]=dp[i-1][j]
//Ҳ����ѡ��,��ôֻ���ڶ�����ȵ�ʱ���������,dp[i][j]=dp[i-1][j-1]
//��������������ܵõ����,��������ӵĹ�ϵ
//��ʼ��: ���ǵ�������i-1,��ԭʼ��һ�л���ַ���Խ������,�������⴦��,Ҳ����
// ��ȡ����һ�����뵽���������,���Ƕ࿪һ�ж࿪һ��
// 1. ע���¿�λ�õĳ�ʼ��: ��0�д���sΪ��ʱ,��ô""ȥ����������ƥ��t�ķ�������Ȼ��0
//						 ��0�д���tΪ��ʱ,��ôs���ɵ�������ƥ��յ�����ֻ��һ��,���ǿ�,���Ե�һ��Ϊ1
// 2. ����ԭ�ַ���ʱҪע���±�-1
//���˳��:��������,��������
//����ֵ: dp[ǰ׺����Ϊn][ǰ׺����Ϊm]��ƥ�䷽����

#include<iostream>
#include<vector>
using namespace std;
class Solution29
{
public:
	int numDistinct(string s, string t)
	{
		const int MOD = 1000000007;

		int n = s.size(), m = t.size();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++)
			dp[i][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
				if (s[i - 1] == t[j - 1])
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
			}
		}
		return dp[n][m] % MOD;
	}
};
//�ռ�ѹ��: ����ν�i�����ݸ���Ϊi+1������,
//��Ϊ[i][j]�����������Ϸ������Ϸ��ĸ���,һά������,[j]λ��δ���¾��Ǵ�����һ�е�ֵ,
//Ҫ��ֱ�ӻ�ȡ���Ϸ�����,�������Ѿ������¸���,����Ҫ��������ȥ��������
class Solution30
{
public:
	int numDistinct(string s, string t)
	{
		const int MOD = 1000000007;
		int n = s.size(), m = t.size();
		vector<int>dp(m + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = m; j >= 1; j--)
			{
				if (s[i - 1] == t[j - 1])
					dp[j] = (dp[j] + dp[j - 1]) % MOD;
			}
		}
		return dp[m] % MOD;
	}
};