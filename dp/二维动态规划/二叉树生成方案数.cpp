//https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea
//Сǿ������n���ڵ�, �����������������ж����ֲ�ͬ�Ķ���������ڵ����Ϊn�����ĸ߶Ȳ�����m�ķ���
//��Ϊ�𰸺ܴ����Դ���Ҫģ��1000000007�����.

//https://www.bilibili.com/video/BV1WQ4y1W7d1?t=8590.7
#include<iostream>
#include<vector>
using namespace std;
class Solution11
{
	vector<vector<int>>memo;
	const int MOD = 1000000007;
public :
	int getNum(int n, int m)
	{
		memo = vector<vector<int>>(n, vector<int>(m, -1));
		return compute(n,m);
	}
	//���ڵ�����nʱ,���ز���С�ڵ���m�ķ������ж���
	int compute(int n, int m)
	{
		if (n == 0)
			return 1;//0���ڵ�,�߶�<=m�ķ�������һ��
		if (m == 0)
			return 0;//�нڵ�,���ǶѲ�����һ���ܹ�����=0�ķ���
		if (memo[n][m] == -1)
			return memo[n][m];
		long long ans = 0;
		//ö���������ܹ��ֶ��ٸ��ڵ�ȥ���ҷ�����,0~n-1,��Ϊ���ڵ�϶�Ҫռ��һ��
		for (int k = 0; k < n; k++)
		{
			ans = (ans + ((long long)compute(k, m - 1) *compute(n - k - 1, m - 1)) % MOD) % MOD;
		}
		memo[n][m] = ans;
		return (int)ans;
	}
};
//�����ϸ�λ��������ϵ: 
//ֻ����m-1�е�,����0~i�еĸ���,��һ������
//���˳����Ǵ�������,��������
//��ʼ��,0�����и��Ӷ���1
class Solution12
{
	const int MOD = 1000000007;
public:
	int getNum(int n, int m)
	{
		vector<vector<long long>>dp(n+1, vector<long long>(m+1));
		for (int j = 0; j <= m; j++)
			dp[0][j] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = 0;
				for (int k = 0; k < i; k++)
					dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - k - 1][j - 1] % MOD) % MOD;
			}
		}
		return dp[n][m];
	}
};
//���Ƶ�������һ��һ������������Ƹ���
//https://www.bilibili.com/video/BV1WQ4y1W7d1?t=9647.9
//��ô����Ҫ�������ϸ���,����dp[i][j]λ��ʱ,ǰһ����[0,j-1]���������ֻ�û����,Ҳ�Ϳ���ֱ�ӻ�ȡ
//��������,�������ϼ���
class Solution12
{
	const int MOD = 1000000007;
public:
	int getNum(int n, int m)
	{
		vector<long long >dp(n+1);
		dp[0] = 1;//��0��,��ʼ��Ϊ1
		for (int j = 1; j <= m; j++)//������,һ��һ�и���
		{
			for (int i = n; i >= 1; i--)
			{
				dp[i] = 0;
				for (int k = 0; k < i; k++)
				{
					dp[i] = (dp[i] + dp[k] * dp[i - k - 1] % MOD) % MOD;
				}
			}
		}
		return (int)dp[n];
	}
};