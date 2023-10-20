#include<iostream>
#include<vector>
using namespace std;
class Solution1
{
    int n;
public:
    //思路: 可能是以任意位置为起点,得到最长的序列长度,所以
    //1. dfs要有int 返回值,代表以i为起点的最长序列长度
    //子问题: 得到一个下标i,遍历从i+1开始比他大能够放在i后面的值,组成很多子序列,记录最长的那个
    //回溯: 没有回溯
    //剪枝: 没有剪枝,如果能够改为记忆化搜索,剪枝就是将已经查找的以i为头的最长长度添加进备忘录
    //出口: 
    int lengthOfLIS(vector<int>& nums)
    {
        n = nums.size();
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            ret = max(ret, dfs(nums, i));
        }
        return ret;
    }
    //以i为开头的最长序列,有很多序列,你得记录最大的那个
    int dfs(vector<int>& nums, int index)
    {
        int ret = 1;
        for (int i = index + 1; i < n; i++)
        {
            if (nums[i] > nums[index])
                ret = max(ret, dfs(nums, i) + 1);
        }
        return ret;
    }
};
class Solution2
{
    int n;
public:
//以所有值为起点,可能达成的最长递增子序列,ret 记录返回最大值
//子问题:决策树: 以index为起点,相信dfs()能够处理好从index+1之后的所有子序列长度,然后在返回结果之上加上我1个,但是要记录所有子序列中长度最大值,所以要有 int 返回值,dfs(int index)
//需要遍历index+1 之后的,比[index]大的值,拼接在后面所能形成的最长子序列,
//判断是否能改为记忆化搜索: 我们发现,以某一个数为起点的dfs()过程大量重复
    int lengthOfLIS(vector<int>& nums) 
    {
        n=nums.size();
        vector<int> memo(n);
        int ret=0;
        for(int i=0;i<n;i++)
        {
            ret= max(ret,dfs(nums,i,memo));
        }
        return ret;
    }
    int dfs(vector<int>&nums,int index,vector<int>&memo)
    {
        if(memo[index]) return memo[index];

        int ret=1;
        for(int i=index+1;i<n;i++)
        {
            if(nums[i]>nums[index])
            {
                ret = max(ret,dfs(nums,i,memo)+1);
            }
        }
        memo[index]=ret;
        return memo[index];
    }
};

class Solution3
{
    int n;
public:
    //思路: 可能是以任意位置为起点,得到最长的序列长度,所以
    //1. dfs要有int 返回值,代表以i为起点的最长序列长度
    //子问题: 得到一个下标i,遍历从i+1开始比他大能够放在i后面的值,组成很多子序列,记录最长的那个
    //回溯: 没有回溯
    //剪枝: 没有剪枝,如果能够改为记忆化搜索,剪枝就是将已经查找的以i为头的最长长度添加进备忘录
    //出口: 
    //改动归: 
    //dp数组中记录的是记录以i为开头的子序列的最长的长度,要最大值,就需要ret=max(ret,dp[i])找到最大值返回
    //1. 开空间大小 n,
    //2. 填表顺序,填i=1的最长子序列长度dp[1],在递归到下一层时,需要i=3的dp值,所以填表顺序是先把后面的填好,从右往左填
    int lengthOfLIS(vector<int>& nums)
    {
        n = nums.size();
        vector<int>dp(n, 1);//至少是自己有一个,所以都初始化为1
        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);//自身大,还是后面的组成子序列长度+我自己1大
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};