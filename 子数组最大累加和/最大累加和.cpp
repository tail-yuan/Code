//https://leetcode.cn/problems/maximum-subarray/description/
#include<iostream>
#include<vector>
using namespace std;
class Solution1
{
public:
    int maxSubArray1(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>dp(n+1);
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
    int maxSubArray2(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];
        int ret = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
    int maxSubArray3(vector<int>& nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int ret = nums[0];
        for (int i = 1; i < n; i++)
        {
            prev = max(nums[i] + prev, nums[i]);
            ret = max(prev, ret);
        }
        return ret;
    }
};
//1.
//dp[i]������iλ��Ϊ��β���ۼӺ��������������飬�������һ�β���
//1. �Լ�һ�飬2.��֮ǰ��һ�飬dp[i]=max(arr[i],dp[i-1]+arr[i])
// 
//2. ��ʼ�����漰��i-1�����Բ��ö࿪һ�����ӵķ�ʽ��2.1 ע���ʼ�������¿���0λ��Ϊ0��Ӱ���� 2.2 �ڷ���ԭ����ʱע���±�ı仯
//3. ����ֵ�� ����dp�����е����ֵ

//2. 
//��iλ����Ϊ��β�����������������չ�೤�ܹ�ʹ���ۼӺ������
//1. �Լ�һ�飬2. ��Ϊ�����������飬������Ҫ��ǰ��չ�õ�����+�������;���dp[i-1]�ĺ���

//3. 
//��Ϊֻ������ǰһ��λ�ã�����û�б�Ҫ׼��һ���ű�ʹ��һ��������¼ǰһ��λ�õ�ֵ����
//prevʱ�̸��£���Ϊdp[i]��ֵ
//ans��¼�Ƚϣ������ܷ��ø���dp[0]

//�������⣺ ������������ۼӺ������left,right,maxSum
//https://www.bilibili.com/video/BV1pw411M7Du?t=1055.3
// prev����ǰ��������ۼӺͣ�left�����䣬right������,sum�����Ѿ������ķ�Χ������ۼӺ�
//������iλ��ʱ�����prev>=0��˵��������ͼ��iλ�ÿ��Ժ�����һ��right++
//���prev<0,˵�����ɻ��������Լ�һ�飬prev=nums[i],left=right,Ѱ����iλ��Ϊ��ͷ��
//�������ܷ����ۼӺ͸�������䣬
// Ϊʲôֱ������ô���أ���Ϊ���������������ǰ���䣬��left<i���õ�������������ۼӺ�һ�����С

class Solution2
{
    int left, right, sum;
public:
    void extra(vector<int>& nums)
    {
        int n = nums.size();
        sum = INT_MIN;
        int prev = INT_MIN;
        for (int l = 0, r = 0; r < n; r++)
        {
            if (prev >= 0)
                prev += nums[r];
            else
            {
                prev = nums[r];
                l = r;
            }
            if (prev > sum)
            {
                sum = prev;
                left = l;
                right = r;
            }
        }
    }
};
