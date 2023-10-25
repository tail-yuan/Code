//https://leetcode.cn/problems/minimum-path-sum/
#include<iostream>
#include<vector>
using namespace std;
//dfs: ����(i,j)λ�������һ�β���,
//������: i,jλ�ÿ����Ǵ���,���������λ�õ�,
// ����dfs�����ܹ����Ҹ���������ѡ��֮��,���ص����ҵ���С·����,
// Ȼ���Ҽ����Լ�������С·����.
//�����ڷ��ص�ʱ������˰��Լ������ٷ���
//����(i,j)λ�õ�·���кܶ�,ÿ���������dfs(i,j)�ظ�����,���Կ�������Ϊ���仯����
//�ﵽ��֦��Ŀ��
//ʹ��dp��ʽ,�����ϸ�λ������,(i,j)λ�������������Ϸ���������,�������˳���Ǵ�����������
// ���ֿ���ģʽ: 
// һ: 
//��ʼ��: ��Ϊ��һ��,��һ��ֻ��һ�������ѡ��,������Ҫ��dp[0][j].dp[i][0]���г�ʼ��,
//����Ҳ���Խ������зŵ�����������һ�����,������Ҫ�࿪һ��,�࿪һ��,
//�����������,��������,ֻ��Ҫ����ʱ�������һ��һ��ȫ����ʼ��ΪINT_MAX,dp[0][1]����dp[1][0]=0
//ʹ�ú�������ܹ�ȡ��grid[0][0]ֵ����
//���Ƿ���ԭ����ʱҪע���±�-1.����ֵ����dp[n][m]
//��: 
//��memo�Ľ�����,����λ������,(i,j)λ�������������,����������������
//����ֵ��dp[n-1][m-1],����dp[n][m]
//��ʼ��dp[0][0]=grid[0][0],��ʵ��ʼ����һ��,��һ��

//�����ɱ�������Ծ�������ֵ,���Կ��Ը���Ϊdp
class Solution1
{
    int n, m;
    vector<vector<int>>memo;
public:
    int minPathSum1(vector<vector<int>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        memo = vector<vector<int>>(n, vector<int>(m));
        return dfs(grid, n-1, m-1);
    }
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if (memo[i][j])
            return memo[i][j];

        //����: ��(i,j)λ�õ����ʼ�ĵ�(0,0)
        if (i == 0 && j == 0)
        {
            memo[i][j] = grid[0][0];
            return memo[i][j];
        }
        int p1 = INT_MAX, p2 = INT_MAX;
        if (i - 1 >= 0)
            p1 = dfs(grid, i - 1, j);
        if (j - 1 >= 0)
            p2 = dfs(grid, i, j - 1);
        memo[i][j] = min(p1, p2) + grid[i][j];
        return memo[i][j];
    }
};
class Solution2
{
    //------------
//dp1
public:
    int minPathSum2(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[0][1] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
    //dp2
    int minPathSum3(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < m; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
    //�ռ�ѹ��https://www.bilibili.com/video/BV1WQ4y1W7d1?t=1996.4
    int minPathSum4(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<int>dp(m);
        dp[0] = grid[0][0];
        for (int j = 1; j < m; j++)
            dp[j] = dp[j - 1] + grid[0][j];
        for (int i = 1; i < n; i++)
        {
            // i = 1��dp���������ж�ά��ĵ�1�е�����
            // i = 2��dp���������ж�ά��ĵ�2�е�����
            // i = 3��dp���������ж�ά��ĵ�3�е�����
            // ...
            // i = n-1��dp���������ж�ά��ĵ�n-1�е�����
            dp[0] = dp[0] + grid[i][0];//ÿһ�п�ͷ���Ҹ���
            for (int j = 1; j < m; j++)
            {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1];
    }
};