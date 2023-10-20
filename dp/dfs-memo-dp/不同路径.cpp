#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/unique-paths/submissions/
class Solution1
{
    int m;
    int n;
public:
    int uniquePaths(int _m, int _n)
    {
        m = _m, n = _n;
        return dfs(0, 0);
    }
    int dfs(int row, int col)
    {
        if (row == m - 1 && col == n - 1)
        {
            return 1;
        }
        int ret = 0;
        if (row + 1 < m)
            ret += dfs(row + 1, col);
        if (col + 1 < n)
            ret += dfs(row, col + 1);
        return ret;
    }
};
class Solution2
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n));
        //��ʼ����һ�к͵�һ��
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
//�����Ż�:���һ��,���һ��,�������Խ�����ĵ�һ�е�һ�еĳ�ʼ�����뵽����ѭ��������
//������,��Ҫ��һ�е�һ�а�����Ϊ1,����dp[0][1]=1����
class Solution3
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        //��ʼ����һ�к͵�һ��
        dp[0][1] = 1;
        for (int i = 1; i <=m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};
//int main()
//{
//    Solution1 s1;
//    Solution2 s2;
//    Solution3 s3;
//    cout << (s1.uniquePaths(23, 12) == s2.uniquePaths(23, 12)&&s1.uniquePaths(23,12)==s3.uniquePaths(23,12));
//    //���ڱ����ݹ�Ч�ʵ�,��������һ�ᷢ�ֽ�����ǶԵ�.
//}