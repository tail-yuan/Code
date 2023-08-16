#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

//dp[i][j]表示在[1,i]号物品中挑选,在体积不大于j时能得到的最大价值,dp[n][v]
//dp[i][j]表示在[1,i]号物品中挑选,在体积正好等于j时能得到的最大价值,dp[n][v]
//空间优化: 使用滚动数组的方式更新,只关心上一行的j和j-v[i],为了避免值的覆盖,所以从后往前更新数据即可
const int N=1010;
int n,V;
int v[N],w[N];
int main()
{
    cin>>n>>V;
    for(int i=1;i<=n;i++)//下标直接从1开始
        cin>>v[i]>>w[i];
    //1. 
    // vector<vector<int>>dp(n+1,vector<int>(V+1));//默认多开一行多开一列
    vector<int>dp(V+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=V;j>=v[i];j--)
        {
            if(j-v[i]>=0)
                dp[j]=max(dp[j],dp[j-v[i]] + w[i]);
        }
    }
    cout<< dp[V]<<endl;
    //2. 
    // vector<vector<int>>dp2(n+1,vector<int>(V+1));//默认多开一行多开一列
    vector<int>dp2(V+1);//默认多开一行多开一列
    for(int j=1;j<=V;j++)
        dp2[j]=-1;   //初始化: 第0行,选0号物品,也就是不选物品还想正好等于j体积时的最大价值,-1代表整不了

    for(int i=1;i<=n;i++)
    {
        for(int j=V;j>=v[i];j--)
        {
            // dp2[i][j]=dp2[i-1][j];
            if(j-v[i]>=0 && dp2[j-v[i]] != -1)
                dp2[j]=max(dp2[j],dp2[j-v[i]] + w[i]);
        }
    }
    cout<<(dp2[V] == -1? 0:dp2[V])<<endl;
    return 0;
}

#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

//dp[i][j]表示在[1,i]号物品中挑选,在体积不大于j时能得到的最大价值,dp[n][v]
//dp[i][j]表示在[1,i]号物品中挑选,在体积正好等于j时能得到的最大价值,dp[n][v]
const int N=1010;
int n,V;
int v[N],w[N];
int main()
{
    cin>>n>>V;
    for(int i=1;i<=n;i++)//下标直接从1开始
        cin>>v[i]>>w[i];
    //1. 
    vector<vector<int>>dp(n+1,vector<int>(V+1));//默认多开一行多开一列
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=V;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-v[i]>=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
        }
    }
    cout<<dp[n][V]<<endl;
    //2. 
    vector<vector<int>>dp2(n+1,vector<int>(V+1));//默认多开一行多开一列
    for(int j=1;j<=V;j++)
        dp2[0][j]=-1;   //初始化: 第0行,选0号物品,也就是不选物品还想正好等于j体积时的最大价值,-1代表整不了

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=V;j++)
        {
            dp2[i][j]=dp2[i-1][j];
            if(j-v[i]>=0 && dp2[i-1][j-v[i]] != -1)
                dp2[i][j]=max(dp2[i][j],dp2[i-1][j-v[i]] + w[i]);
        }
    }
    cout<<(dp2[n][V] == -1? 0:dp2[n][V])<<endl;
    return 0;
}