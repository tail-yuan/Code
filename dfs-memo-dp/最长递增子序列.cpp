class Solution1
{
    int n;
public:
//以所有值为起点,可能达成的最长递增子序列,ret 记录返回最大值
//子问题:决策树: 以index为起点,相信dfs()能够处理好从index+1之后的所有子序列长度,然后在返回结果之上加上我1个,但是要记录所有子序列中长度最大值,所以要有 int 返回值,dfs(int index)
//需要遍历index+1 之后的,比[index]大的值,拼接在后面所能形成的最长子序列,
    int lengthOfLIS(vector<int>& nums) 
    {
        n=nums.size();
        int ret=0;
        for(int i=0;i<n;i++)
        {
            ret= max(ret,dfs(nums,i));
        }
        return ret;
    }
	//以某一个位置为起点,最长递增子序列长度
    int dfs(vector<int>&nums,int index)
    {
        int ret=1;
        for(int i=index+1;i<n;i++)
        {
            if(nums[i]>nums[index])
            {
                ret = max(ret,dfs(nums,i)+1);
            }
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

class Solution 
{
public:
//暴力递归->记忆化搜索->动归
//dfs函数的意义是,以index下标为起点的最长递增子序列的长度,那么dp数组的含义也是这个
//填表顺序是从后往前,
//返回值是: 我们想要的是以所有位置为头得到的最长子序列,所以要的是dp数组中最大值
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n,1);
        int ret=0;
        for(int j=n-1;j>=0;j--)
        {
            for(int i= j+1;i<n;i++)
            {
                if(nums[i] > nums[j])
                    dp[j]=max(dp[j],dp[i]+1);
            }
            ret=max(ret,dp[j]);
        }
        return ret;
    }
};