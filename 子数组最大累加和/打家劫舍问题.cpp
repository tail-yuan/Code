//https://leetcode.cn/problems/house-robber/submissions/455246828/

//1. 
//dp[i]��ʾ��[0...i]��������ѡ��,�ܹ��õ��������ۼӺ�
//iλ�����ֲ�Ҫ,��ôdp[i]=dp[i-1]
//iλ������Ҫ,1.�Լ�һ�����,dp[i]=nums[i] 2. ��ǰ�������������,���ǲ���Ҫi-1λ��,dp[i]=dp[i-2]+nums[i]
//�������ȡ���ֵ
//2. 
//�ռ�ѹ��,��Ϊֻ������ǰ����λ��,���Կ���ʹ������������������

//3. ��������״̬���м�¼
//f[i]��ʾiλ��ѡ��,g[i]��ʾiλ�ò�ѡ��
//f[i] = nums[i]+g[i-1] iλ��ѡ��,��ôi-1λ�ñ�Ȼ��ѡ��
//g[i] = max(f[i-1],g[i-1]) iλ�ò�ѡ��,��ô����i-1λ��ѡ����߲�ѡ��,ȡ�ϴ�ֵ����
//�漰��i-1���µ�Խ������,ѡ��ֱ�ӳ�ʼ�� or �࿪һ��λ�ý��߽�ֵŲ�������������(��Ҫע���ʼ��)
//ѡ��ֱ�ӳ�ʼ��: ����ʵ������õ�,f[0]=nums[0] g[0]=0
#include<iostream>
#include<vector>
using namespace std;
class Solution11
{
public:
    int rob1(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 1], max(nums[i], nums[i] + dp[i - 2]));
        return dp[n - 1];
    }
    int rob2(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int prev = max(nums[0],nums[1]);
        int pprev = nums[0];
        for (int i = 2; i < n; i++)
        {
            int cur = max(prev, max(nums[i], pprev + nums[i]));
            pprev = prev;
            prev = cur;
        }
        return prev;
    }
    int rob3(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>f(n);
        vector<int>g(n);
        f[0] = nums[0], g[0] = 0;
        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(g[i - 1], f[i - 1]);
        }
        return max(f[n - 1], g[n - 1]);
    }
};