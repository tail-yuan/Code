
//以某一个位置为起点进行思考的
class Solution 
{
    int ret;
    int m,n;
public:
//子问题: 到达i,j位置时,能选择往下走,往右走,累计路径和,到达终点时更新最小路径和
//回溯:恢复现场:采用的是形参,回到上一层自动恢复成功
//剪枝:无
//判断是否能改成记忆化搜索: 可能到达同一i,j位置进行相同的操作
//来到这个位置时判断,返回值时记录
    int minPathSum(vector<vector<int>>& grid) 
    {
        ret=INT_MAX;
        m=grid.size(),n=grid[0].size();
        dfs(grid,0,0,grid[0][0]);
        return ret;
    }
    void dfs(vector<vector<int>>&grid,int i,int j,int path)
    {
        if(i==m-1 && j==n-1)
        {
            ret=min(ret,path);
            return;
        }
        if(i+1 <m)
            dfs(grid,i+1,j,path+grid[i+1][j]);
        if(j+1<n)
            dfs(grid,i,j+1,path+grid[i][j+1]);
    }
};
//以某一个位置为终点改的记忆化搜索的方法
class Solution 
{
    int m,n;
    vector<vector<int>>memo;
public:
//子问题: i,j位置可能是从上,左来到这个位置的,相信dfs函数能够在我给定这两个选择之后,返回到达我的最小路径和,然后我加上自己就是最小路径和.
//所以在返回的时候别忘了把自己加上再返回
//回溯:无
//
    int minPathSum(vector<vector<int>>& grid) 
    {
        m=grid.size(),n=grid[0].size();
        memo= vector<vector<int>>(m,vector<int>(n));
        int ret=dfs(grid,m-1,n-1);
        return ret;
    }
    int dfs(vector<vector<int>>&grid,int i,int j)
    {
        if(memo[i][j]!=0) return memo[i][j];

        if(i==0 && j==0 )
        {
            memo[i][j]=grid[i][j];
            return memo[i][j];
        }
        //某一个节点,我用dfs获取到两条到达自己的路径和,选择小的向上返回
        int p1=INT_MAX,p2=INT_MAX;
        if(i-1>=0)
            p1 = dfs(grid,i-1,j);
        if(j-1>=0)
            p2 = dfs(grid,i,j-1);
        
        memo[i][j]= min(p1,p2)+grid[i][j];
        return memo[i][j];
    }
};
//改的动态规划
class Solution 
{
    int m,n;
    vector<vector<int>>memo;
public:
//子问题: i,j位置可能是从上,左来到这个位置的,相信dfs函数能够在我给定这两个选择之后,返回到达我的最小路径和,然后我加上自己就是最小路径和.
//所以在返回的时候别忘了把自己加上再返回
//回溯:无
//动态规划: 
//1. 开辟空间大小 (m,n),为了将第一行,第一列初始化并到整体运算中,采取多开一行,多开一列的方式.初始化不影响后续+访问grid时注意下标变换
//2. 填表顺序 从左上填到右下
//3. 初始化: dp[0][0]=grid[0][0]
    int minPathSum(vector<vector<int>>& grid) 
    {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        dp[0][1]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[m][n];
        // memo= vector<vector<int>>(m,vector<int>(n));
        // int ret=dfs(grid,m-1,n-1);
        // return ret;
    }
    int dfs(vector<vector<int>>&grid,int i,int j)
    {
        if(memo[i][j]!=0) return memo[i][j];

        if(i==0 && j==0 )
        {
            memo[i][j]=grid[i][j];
            return memo[i][j];
        }
        //某一个节点,我用dfs获取到两条到达自己的路径和,选择小的向上返回
        int p1=INT_MAX,p2=INT_MAX;
        if(i-1>=0)
            p1 = dfs(grid,i-1,j);
        if(j-1>=0)
            p2 = dfs(grid,i,j-1);
        
        memo[i][j]= min(p1,p2)+grid[i][j];
        return memo[i][j];
    }
};