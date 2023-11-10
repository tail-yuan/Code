//https://leetcode.cn/problems/maximum-sum-circular-subarray/
#include<iostream>
#include<vector>
using namespace std;
//��Ϊ�ǻ��ε�,������β����������Ϊһ������������
//����������������ܲ��漰����β,�����漰����β
//�����漰ʱ,���Ǽ�������������������ۼӺ�����,maxSum. �˴�����ʹ�ÿռ�ѹ��֮��,һ��������¼�ķ�ʽ����
//���漰ʱ,���������all-�������ۼӺ���С������minSum,
//����ѡ��ϴ�ֵ����
//��������С�ۼӺ�ʱ,������Ǹ���,�õ��ľ�������������ۼӺ�all,��ôall-minSumʱ�õ�0,�϶�����,Ӧ��ֱ�ӷ���maxSum
class Solution21 
{
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int n = nums.size();
        int all = nums[0];
        int maxSum =nums[0], minSum = nums[0];
        int maxPrev = nums[0], minPrev = nums[0];
        for (int i = 1; i < n; i++)
        {
            all += nums[i];
            maxPrev = max(nums[i], nums[i] + maxPrev);
            maxSum = max(maxSum, maxPrev);//��¼���ܸ��µ�����ۼӺ�

            minPrev = min(nums[i], nums[i] + minPrev);
            minSum = min(minPrev, minSum);
        }
        return minPrev == all ? maxSum : max(maxSum, all - minSum);
    }
};


//ʹ������״̬���м�¼,�������Ϸ�����Ҫ��¼���������Լ�������С����������
//f[i]��ʾ��������
//g[i]��ʾ������С��
//f[i] = max(f[i-1],f[i-1]+nums[i])
//g[i] = min(g[i-1],g[i-1]+nums[i])
//����״̬֮��û�й�ϵ,ֻ��ͬʱ��¼
//�漰����ʼ���Լ�i-1����Խ��ı߽�����,���ö࿪һ���ռ�ķ�ʽ.1. ��ʼ���¿���λ�� 2. ����ԭ����ʱ�±�-1
//��ʼ��f[0]ʱ,���[1](ԭ0λ��Ԫ��)<0,��ô�����϶��ǲ�ѡΪ��,�ۼӺͲ���,��Ӧ�ü�0����.
//                              >0,��ô�����϶���ѡΪ��,�ۼӺ�+nums[1]
//���վ�����f[0]=0ʱ������������
//ͬ��g[0]=0
class Solution22
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>f(n + 1);
        vector<int>g(n + 1);
        f[0] = g[0] = 0;
        int maxSum = INT_MIN, minSum = INT_MAX;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i] = max(nums[i - 1], nums[i - 1] + f[i - 1]);
            maxSum = max(maxSum, f[i]);
            g[i] = min(nums[i - 1], nums[i - 1] + g[i - 1]);
            minSum = min(minSum, g[i]);

            sum += nums[i - 1];
        }
        return sum == minSum ? maxSum : max(sum - minSum, maxSum);
    }
};