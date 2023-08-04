#include<iostream>
#include<vector>
using namespace std;
class Solution1//��i,jλ��Ϊ����߱����ݹ�
{
    int m, n;
    int ret;
public:
    int maxValue(vector<vector<int>>& grid)
    {
        m = grid.size(), n = grid[0].size();
        dfs(0, 0, grid, grid[0][0]);
        return ret;
    }
    //��row,colλ����Ϊ���,�����λ��֮��,����Ǹ�λ���ǺϷ���,�Ѿ����Ǹ�λ�õ�ֵ������
    void dfs(int row, int col, vector<vector<int>>& grid, int path)
    {
        //����:�������һ��λ��,��Ҫ����ret���ֵ
        if (row == m - 1 && col == n - 1)
        {
            ret = max(ret, path);
            return;
        }
        if (row + 1 < m) dfs(row + 1, col, grid, path + grid[row + 1][col]);
        if (col + 1 < n) dfs(row, col + 1, grid, path + grid[row][col + 1]);
    }
};
class Solution2//��i,jλ��Ϊ�յ��߱����ݹ�
{
    int m;
    int n;
public:
    //dp[i][j]��ijλ��Ϊ��β,����ijλ��ʱ������ֵ
    int maxValue(vector<vector<int>>& grid)
    {
        m = grid.size(), n = grid[0].size();
        return zuo(m - 1, n - 1, grid);
    }
    //����ֵ�ǵ���xyʱ������ֵ
    int zuo(int x, int y, vector<vector<int>>& grid)
    {
        if (x == 0 && y == 0)
        {
            return grid[0][0];
        }
        int p1 = 0, p2 = 0;
        if (x > 0)
            p1 = zuo(x - 1, y, grid);
        if (y > 0)
            p2 = zuo(x, y - 1, grid);
        return grid[x][y] + max(p1, p2);
    }
};
class Solution3 
{
    int m;
    int n;
public:
    //dp[i][j]��ijλ��Ϊ��β,����ijλ��ʱ������ֵ
    //dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    //�Ż�:���һ��,���һ��
    //ע��:1. ��ʼ��λ��,ʹ�ò�Ӱ�����,��ӵĶ���0���� 2. ������gridʱע���±�任
    int maxValue(vector<vector<int>>& grid)
    {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};