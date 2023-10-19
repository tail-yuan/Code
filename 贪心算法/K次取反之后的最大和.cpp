//https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/

//����̰�ĵ�˼��
//ȡ������Ϊ�˵õ���������,�������ȶԸ�������ȡ������,
//���Ը����ĸ���m��k�Ĵ�С�ȽϾ�ʮ�ֹؼ�
//if m>=k,��ѡ����С���Ǽ�������ת��Ϊ��������
//else 1. �����еĸ���������ȫת��Ϊ����,
//	   2. ��Ҫ��kʣ�µĴ�����ż�����ж�,k-=m
//			2.1 �����ż��,ֱ�ӷ��ؼ���,ֱ�Ӷ�һ����������,ż����ȡ�������õ����
//			2.2 ���������,��ѡ����С���Ǹ����ֽ���һ��ȡ����������.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        int m = 0, n = nums.size(), minElem = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)m++;
            minElem = min(minElem, abs(nums[i]));
            sum += abs(nums[i]);
        }
        int ret = 0;
        if (m >= k)
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < k; i++)
                ret += abs(nums[i]);
            for (int i = k; i < n; i++)
                ret += nums[i];
        }
        else
        {
            if ((k - m) % 2 == 0)
            {
                ret = sum;
            }

            else
            {
                ret = sum;
                ret -= 2*minElem;//һ��һ��,�ܺͼ�ȥ���Ƕ�����
            }
        }
        return ret;
    }
};