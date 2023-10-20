//存在疑问: 为什么一定要将d[i][j]当作是血包,dfs()返回作为所需要的血量,然后dfs-d[i][j],为什么不是+?
//拓展到正负数都存在的题时怎么办?
//疑问解答: x+d[i][j]代表经过这个点之后的血量,你也说到了正负数都存在,+负数不就是血量-吗?+正数不就是血量+吗?
//dfs()返回值不就是两个选择之后的min-这个点带来的影响吗?
//只能以某个点为起点
class Solution 
{
    int m;
    int n;
public:
//子问题:给定dfs一个方向,我相信dfs能给我返回从这个到达终点所需要的最小的血量消耗,选择两种中的较小值,+从i,j位置通过的消耗,就是从i,j位置到达终点的消耗.
//d值可正可负,导致从i,j点通过时已经死了,血量不能小于1，因此要和1取个max(凭啥这么处理)
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        m=dungeon.size(),n=dungeon[0].size();
        int ret= dfs(dungeon,0,0);
        return ret;
    }
    int dfs(vector<vector<int>>& d,int i,int j)
    {
        if(i==m-1 && j==n-1)
            return max(1-d[i][j],1);//保证活的最小值就是1
        int p1=INT_MAX,p2=INT_MAX;
        if(i+1<m)
            p1=dfs(d,i+1,j);
        if(j+1<n)
            p2=dfs(d,i,j+1);
        int tmp=min(p1,p2)-d[i][j];
        return max(tmp,1);
    }
};

class Solution 
{
    int m;
    int n;
    vector<vector<int>>memo;
public:
//子问题:给定dfs一个方向,我相信dfs能给我返回从这个到达终点所需要的最小的血量消耗,选择两种中的较小值,+从i,j位置通过的消耗,就是从i,j位置到达终点的消耗.
//d值可正可负,导致从i,j点通过时已经死了,血量不能小于1，因此要和1取个max(凭啥这么处理)
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        m=dungeon.size(),n=dungeon[0].size();
        memo=vector<vector<int>>(m,vector<int>(n));
        int ret= dfs(dungeon,0,0);
        return ret;
    }
    int dfs(vector<vector<int>>& d,int i,int j)
    {
        if(memo[i][j]!=0) return memo[i][j];

        if(i==m-1 && j==n-1)
        {
            memo[i][j]=max(1-d[i][j],1);
            return memo[i][j];
        }
        int p1=INT_MAX,p2=INT_MAX;
        if(i+1<m)
            p1=dfs(d,i+1,j);
        if(j+1<n)
            p2=dfs(d,i,j+1);
        int tmp=min(p1,p2)-d[i][j];
        memo[i][j]=max(tmp,1);
        return memo[i][j];
    }
};


class Solution 
{
    int m;
    int n;
    vector<vector<int>>memo;
public:
//子问题:给定dfs一个方向,我相信dfs能给我返回从这个到达终点所需要的最小的血量消耗,选择两种中的较小值,+从i,j位置通过的消耗,就是从i,j位置到达终点的消耗.
//d值可正可负,导致从i,j点通过时已经死了,血量不能小于1，因此要和1取个max(凭啥这么处理)
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[m][n-1]=1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0 ;j--)
            {
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                dp[i][j]=max(dp[i][j],1);
            }
        }
        return dp[0][0];
        // memo=vector<vector<int>>(m,vector<int>(n));
        // int ret= dfs(dungeon,0,0);
        // return ret;
    }
    int dfs(vector<vector<int>>& d,int i,int j)
    {
        if(memo[i][j]!=0) return memo[i][j];

        if(i==m-1 && j==n-1)
        {
            memo[i][j]=max(1-d[i][j],1);
            return memo[i][j];
        }
        int p1=INT_MAX,p2=INT_MAX;
        if(i+1<m)
            p1=dfs(d,i+1,j);
        if(j+1<n)
            p2=dfs(d,i,j+1);
        int tmp=min(p1,p2)-d[i][j];
        memo[i][j]=max(tmp,1);
        return memo[i][j];
    }
};