#include <iostream>
#include <vector>
#include<string.h>
using namespace std;
//dp[i][j]表示[0,i]前i个物品当中总体积不超过J所有选法中能达到的最大价值
//dp2[i][j]表示[0,i]前i个物品当中总体积恰好为J所有选法中能达到的最大价值
const int N=1010;
int n,V;
int v[N],w[N];
int main() 
{
    cin>>n>>V;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i];
    vector<vector<int>>dp(n+1,vector<int>(V+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=V;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=v[i])
                dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    }
    cout<<dp[n][V]<<endl;
    vector<vector<int>>dp2(n+1,vector<int>(V+1));
    for(int i=1;i<=V;i++) dp2[0][i]=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=V;j++)
        {
            dp2[i][j]=dp2[i-1][j];
            if(j>=v[i] && dp2[i][j-v[i]]!=-1)
                dp2[i][j]=max(dp2[i][j],dp2[i][j-v[i]]+w[i]);
        }
    }
    cout<<(dp2[n][V]==-1?0:dp2[n][V])<<endl;
}

#include <iostream>
#include <vector>
#include<string.h>
using namespace std;
//dp[i][j]表示[0,i]前i个物品当中总体积不超过J所有选法中能达到的最大价值
//dp2[i][j]表示[0,i]前i个物品当中总体积恰好为J所有选法中能达到的最大价值
//空间优化,利用滚动数组,依赖于上一行位置,以及这一行前面的位置,所以顺序需要从左往右
const int N=1010;
int n,V;
int v[N],w[N];
int main() 
{
    cin>>n>>V;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i];
    vector<int>dp(V+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=v[i];j<=V;j++)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[V]<<endl;
    vector<int>dp2(V+1);
    for(int i=1;i<=V;i++) 
        dp2[i]=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=v[i];j<=V;j++)
        {
            if(dp2[j-v[i]]!=-1)//判断条件的存在就是为了在无效时不用第二个条件,因为求的是max所以将其-1初始化为极小
            dp2[j]=max(dp2[j],dp2[j-v[i]]+w[i]);
        }
    }
    cout<<(dp2[V]==-1?0:dp2[V])<<endl;
}

#include <iostream>
#include <vector>
#include<string.h>
using namespace std;
//dp[i][j]表示[0,i]前i个物品当中总体积不超过J所有选法中能达到的最大价值
//dp2[i][j]表示[0,i]前i个物品当中总体积恰好为J所有选法中能达到的最大价值
//空间优化,利用滚动数组,依赖于上一行位置,以及这一行前面的位置,所以顺序需要从左往右
const int N=1010;
int n,V;
int v[N],w[N];
int main() 
{
    cin>>n>>V;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i];
    vector<int>dp(V+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=v[i];j<=V;j++)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[V]<<endl;
    vector<int>dp2(V+1);
    for(int i=1;i<=V;i++) 
        dp2[i]=-0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        for(int j=v[i];j<=V;j++)
        {
            dp2[j]=max(dp2[j],dp2[j-v[i]]+w[i]);
        }
    }
    cout<<(dp2[V]<0?0:dp2[V])<<endl;
}