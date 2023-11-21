//https://leetcode.cn/problems/last-stone-weight-ii/description/
//1. ÿһ�ֶ�ѡ���������ֽ��ж�ײ,�õ����֮���ֵ���·ŵ�������,�ظ���������
//ֱ��ֻʣ�����һ����,������Ҫ�������������������е���Сֵ
//2. ������ôѡ��,ѡ��Ĺ��̾��ǻ��ֵĹ���.[3,2,5]
//�˴�ѡ��3��2,��ʵ���ǽ�3->A{},2->B{},���õ�3-2=1 ->A{},Ȼ����ѡ��5->B{},
//����Ͼ���3->A{},2,5->B{},Ȼ���� abs(sumA -sumB )��ֵ��С,���������������
//�϶���Խ�ӽ����������֮��õ��Ĳ�ֵ��С,��ô����Ǹ�������ۼӺ�Ϊ10,
//����AB����ʱ,ѡ��һ��������->A{},��ôʣ�µĶ�����B{},
//��ô�϶���ϣ����nums��������ѡһЩ����,���ۼӺ�<=5ʱ,A���ۼӺ�����Ƕ���(���sumA�����ӽ�5)
//ֻ������ѡ��,������������ۼӺ͵Ĳ�ֵ�Ż�����С.

//01�����������Ҫ���ǲ�Ҫ������
//dp[i][j]����ľ�����ǰi����Ʒ��ѡ��,��j<=tʱ�ܹ���õ�����ۼӺ��Ƕ���
//iλ�ò�Ҫ: dp[i][j]=dp[i-1][j]
//iλ��Ҫ: dp[i][j]=dp[i-1][j-nums[i]] +nums[i]
//����ȡ�����нϴ�ֵ
//��ʼ��: �漰��i-1,����ѡ��࿪һ��,dp[n+1][t+1].��Ҫ���¿��Ŀռ��ʼ��,dp[0]=0
//���˳��: �Ż�Ϊһά����ʱ,��ΪҪ�������������,����Ϊ�˱���������ݱ�����,��Ҫ�����������
//����ֵ����dp[t]
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = 0;
        for (int& num : stones)
            sum += num;
        int t = sum / 2;
        int near = func(stones, t);
        return sum - near-near;
    }
    int func1(vector<int>& nums, int t)
    {
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(t + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= t; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j > nums[i - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
        }
        return dp[n][t];
    }
    int func2(vector<int>& nums, int t)
    {
        int n = nums.size();
        vector<int>dp(t + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = t; j >= nums[i]; j--)
                dp[j] = max(dp[j], dp[j - nums[i - 1]] + nums[i - 1]);
        }
        return dp[t];
    }
public:
    int func(vector<int>& nums, int t)
    {
        vector<int>dp(t + 1);
        for (int num : nums)
        {
            for (int j = t; j >= num; j--)
                dp[j] = max(dp[j], dp[j - num] + num);
        }
        return dp[t];
    }
};