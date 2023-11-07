//https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

// ��ǰ����(i,j)λ�ã�����һ��Ҫ�ߵ����½�(n-1,m-1)
// ��(i,j)����������һ��Ҫ�ߵ����½�(n-1,m-1)���ж�����·�����ۼӺ�%k��������r
// 
//��ǰλ��%k��ֵ��֪Ϊmod1����Ҫ��������%k��ֵΪmod2,��ô����Ƶ�������·����%k֮��Ӧ���Ƕ��٣� mod0
// mod0 = (k+mod2-mod1)%k

#include<iostream>
#include<vector>
using namespace std;
class Solution11
{
	const int MOD = 1e9 + 7;
	int n, m, k;
	vector<vector<vector<int>>>memo;
public:
	int numberOfPaths(vector<vector<int>>& grid, int k1)
	{
		n = grid.size();
		m = grid[0].size();
		k = k1;
		memo = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(k, -1)));
		return dfs(grid, 0, 0, 0);
	}
	int dfs(vector<vector<int>>& grid, int i, int j, int r)
	{
		if (i == n - 1 && j == m - 1)
			return grid[i][j] % k == r ? 1 : 0;
		if (memo[i][j][r] != -1)
			return memo[i][j][r];
		int need = (k + r - (grid[i][j] % k)) % k;
		int ans = 0;
		if (i + 1 < n)//����������
			ans = dfs(grid, i + 1, j, need);
		if (j + 1 < m)//����������
			ans = (ans + dfs(grid, i, j + 1, need)) % MOD;
		memo[i][j][r] = ans;
		return ans;
	}
};
//��i,j����һ����ά��Ȼ��ÿ��������һ�����ϵĸ߶ȣ�������ס��¥�����Ǿ���k��k��Ϊ��ȡģ�õ������Ը߶ȷ�Χ����0~k
//��ʼ����Ȼ�������½ǵ�ֵ�����h=grid[n][m]%k hλ�õ�¥����������1����������0,��ôdpֵ�͵õ�ȷ����
//i,jλ���������·��������ҷ��ĸ߶������е�����ֵ��
//����ֻ��Ҫ�����·��������ҷ����������ݸ��£�Ȼ�����������Ƶ�
//����ֵ����0,0λ��¥����0�ĸ��ӵ�ֵ
class Solution11
{
	const int MOD = 1e9 + 7;
public:
	int numberOfPaths(vector<vector<int>>& grid, int k)
	{
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k, 0)));
		dp[n - 1][m - 1][grid[n - 1][m - 1] % k] = 1;
		for (int i = n - 2; i >= 0; i--)
		{
			for (int r = 0; r < k; r++)
				dp[i][m - 1][r] = dp[i + 1][m - 1][(k + r - grid[i][m - 1] % k) % k];
		}
		for (int j = m - 2; j >= 0; j--)
		{
			for (int r = 0; r < k; r++)
				dp[n - 1][j][r] = dp[n - 1][j + 1][(k + r - grid[n - 1][j] % k) % k];
		}
		int need = 0;
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = m - 2; j >= 0; j--)
			{
				for (int r = 0; r < k; r++)
				{
					need = (k + r - grid[i][j] % k) % k;
					dp[i][j][r] = dp[i + 1][j][need];
					dp[i][j][r] = (dp[i][j][r] + dp[i][j + 1][need]) % MOD;
				}
			}
		}
		return dp[0][0][0];
	}
};