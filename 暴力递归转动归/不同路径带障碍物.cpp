#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/unique-paths-ii/submissions/
class Solution1
{
    int m;
    int n;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();
        return dfs(obstacleGrid, 0, 0);
    }
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        //�������:�������ϰ���ôֱ�ӷ���0
        if (grid[row][col] == 1) return 0;//[[1]]

        //�����յ�,˵��������һ����ȷ��·
        if (row == m - 1 && col == n - 1)
            return 1;
        int ret = 0;
        if (row + 1 < m && grid[row + 1][col] == 0)
            ret += dfs(grid, row + 1, col);
        if (col + 1 < n && grid[row][col + 1] == 0)
            ret += dfs(grid, row, col + 1);
        return ret;
    }
};
class Solution
{
public:
    //���[i-1][j]����[i][j-1]���ϰ���Ļ�,˵���������ǵ�������·�ǲ�ͨ����û��·������,dp[i][j]=0+��һ��ֵ
    int uniquePathsWithObstacles(vector<vector<int>>& ob)
    {
        //�Ż�,���һ�ж��һ��
        //ע���ʼ��dp[0][1]=1
        //ע���±�任,�ڷ���obԭ����ʱ
        int m = ob.size(), n = ob[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (ob[i - 1][j - 1] == 0)//������Ǵ��ϰ�������,˵��·������Ч��
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};