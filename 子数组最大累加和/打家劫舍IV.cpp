//https://leetcode.cn/problems/house-robber-iv/description/
//����͵��K������,����͵��ʱ��������,����ֻ��͵����ֵret >nums[i]��,
//������������Сֵ

//���ִ𰸷�,����������
//����ȷ����Χ,(minVal,maxVal)
//�������ret=50ʱ���ܹ�͵��K�䷿��,��ôret>50ʱ�϶�Ҳ��͵��K��,����Ҫ����������������Сֵ
//����ȥ���������Ѱ��,����ǵ�����
//������Ҫһ������func()������,������Ϊretʱ,��nums�������ܲ���͵��K�䷿��
//��Ҫע�����,��ʱ�Ͳ����������ۼӺ͵�����,����������Ͷ���ټ䷿������,���nums[i]>ability,+1���ɲ��������
//�����ǲ��ÿռ�ѹ���汾ʵ�ֵ�.
//�Ż�: ̰��,��͵�Ͻ�͵,Ȼ��������һ�����Ӽ���,Խ��͵Խ��,���涼��һ���ľ���+1,�������ۼӺ�ʱ���治ͬ�����
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
    int n;
public:
    int minCapability(vector<int>& nums, int k)
    {
        n = nums.size();

        int l = nums[0], r = nums[0];
        for (int i = 1; i < n; i++)
        {
            l = min(l, nums[i]);
            r = max(r, nums[i]);
        }
        int ret = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (func(nums, mid) >= k)
            {
                ret = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ret;
    }
    int func(vector<int>& nums, int ability)
    {
        if (n == 1)
            return nums[0] <= ability ? 1 : 0;
        if (n == 2)//��Ϊ���ڲ���ѡ��
            return (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;

        int pprev = nums[0] <= ability ? 1 : 0;
        int prev = (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
        for (int i = 2; i < n; i++)
        {
            int cur = max(prev, pprev + (nums[i] <= ability ? 1 : 0));
            pprev = prev;
            prev = cur;
        }
        return prev;
    }
    int func2(vector<int>& nums, int ability)
    {
        int ans = 0;
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] <= ability) 
            {
                ans++;
                i++;//������һ������,��Ϊ��������
            }
        }
        return ans;
    }
};

