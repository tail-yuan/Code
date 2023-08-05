#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/unique-paths/submissions/
class Solution1//dp思想: 以某一个位置为起点,向后走,是一种递推的方式,自底向上;
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
        //初始化第一行和第一列
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
//动归优化:多加一行,多加一列,这样可以将冗余的第一行第一列的初始化融入到后续循环代码中
//经分析,想要第一行第一列按规则都为1,则在dp[0][1]=1即可
class Solution3
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        //初始化第一行和第一列
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
//    //由于暴力递归效率低,所以你多等一会发现结果都是对的.
//}

//记忆化搜索
class Solution4
{
    int m,n;
public:
//选择i,j位置作为起点,往后找,在每个位置可以选择往右走还是往下走
//出口: 当到达终点时,说明确实找到了一种,return 1
//判断: 发现决策树中出现大量重复值的计算,所以可以采用额外空间记录重复计算的值,达到剪枝的目的
//->改为记忆化搜索
//1. 申请额外空间 2. 在返回之前记录 3. 在进入之后先查看是否已经存在
    int uniquePaths(int _m, int _n) 
    {
        m=_m,n=_n;
        vector<vector<int>> memo(m,vector<int>(n));
        return dfs(0,0,memo);
    }
    int dfs(int i,int j,vector<vector<int>>& memo)
    {
        //进来之后先看一眼
        if(memo[i][j])
            return memo[i][j];
        
        if(i == m-1 && j==n-1)
        {
            memo[i][j]=1;
            return memo[i][j];
        }
        
        int ret=0;
        if(i < m-1)
            memo[i][j]+=dfs(i+1,j,memo);//往下走
        if(j < n-1)
            memo[i][j]+=dfs(i,j+1,memo);//往右走
        return memo[i][j];
    }
};

//记忆化搜索->动态规划的优化版本,就是那个多开一行多开一列的情况
class Solution5
{
public:
//以i,j位置为终点,往回找,自顶向下的方式
//因为要的是二维矩阵中的m,n下标,所以二维矩阵肯定得开m+1,n+1大小的
//判断: 发现决策树中存在大量的重复值的计算,所以可以改为记忆化搜索
//->记忆化搜索,1. 开空间 2. 进入递归时先看一眼 3. 返回结果时记录一下
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>memo(m+1,vector<int>(n+1));//1
        return dfs(m,n,memo);
    }
    int dfs(int i,int j, vector<vector<int>>&memo)
    {
        if(memo[i][j]) return memo[i][j];//2
        //机器人是从1,1位置往后走,你都到第0行或者第0列肯定没法到达就是0
        if(i == 0 || j==0) 
        {
            return 0;//因为memo自身所有值初始化都是0
        }
        if(i==1 && j==1) 
        {
            memo[i][j]=1;
            return memo[i][j];//3
        }
        memo[i][j]=dfs(i-1,j,memo)+dfs(i,j-1,memo);//3
        return memo[i][j];
    }
};