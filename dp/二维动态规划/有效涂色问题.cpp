// ��ЧͿɫ����https://www.bilibili.com/video/BV1cg4y1o719?t=4042.9
// ����n��m��������
// һ����n�����ӣ�ÿ�����ӿ���Ϳ��һ����ɫ����ɫ��m����ѡ
// ��Ϳ��n�����ӣ�����m����ɫ��ʹ���ˣ���һ����Ч����
// ��һ���ж�������Ч��Ϳɫ����
// 1 <= n, m <= 5000
// ����Ƚϴ��� % 1000000007 ֮�󷵻�
// ��������֤

//dp[i][j]����ǰi�������Ѿ��չ���j����ɫ����Ч������
// ��i�������ͿɫΪ׼,����֮ǰ�Ĳ���
//1. ǰi-1�������Ѿ��չ���j����ɫ,��ôiλ��ֻ��Ҫ��m����ɫ������ѡ��һ��Ϳɫ����,dp[i][j]=dp[i-1][j] *m
//2. ǰi-1�������Ѿ��չ���j-1����ɫ��ôiλ��ֻ��Ҫ��ʣ�µ�m-(j-1)����ɫ��ѡ��һ��Ϳ��,
//   dp[i][j]=dp[i-1][j-1] * (m-j+1)
//Ҳ������iλ��,����ѡ��֮ǰ����ɫ,����ѡ��ʣ�µ���ɫͿ��

//https://www.bilibili.com/video/BV1cg4y1o719?t=4402.9 ��ʼ��

#include<iostream>
#include<vector>
using namespace std;
class Solution34
{
public:
	int getWays(int n, int m)
	{
		const int MOD = 1000000007;
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		for (int i = 1; i <= n; i++)
			dp[i][1] = m;//i������ֻͿ��һ����ɫ,�ܹ���m��ѡ��
		for (int i = 1; i <= n; i++)
		{
			for (int j = 2; j <= m; j++)
			{
				dp[i][j] = (int)((long long)dp[i - 1][j] * j) % MOD;
				dp[i][j] = (int)(((long long)dp[i - 1][j - 1] * (m - j - 1)) + dp[i][j]) % MOD;
			}
		}
		return dp[n][m];
	}
};

