//https://www.bilibili.com/video/BV1Mh4y1P7qE?t=1775.5
//https://leetcode.cn/problems/split-array-largest-sum/
//��λ������仮��Ϊ������K��,��ÿһ���ۼӺ͵����ֵ����С

//ȷ���ۼӺ�sum��Χ,[0,���������ۼӺ�A],�������ж���0ʱ�ۼӺͶ���0,���ֻ��һ������,��ô���ʱ����������ۼӺ�
//��Χ���Զ��ĺֲܴ�,��Ϊ���ֵ�Ч�ʺܸ�
//������: ���ֵ�����Խ��,ÿһ�������е��ۼӺ�ԽС,��Ȼ��Ȼ�����������ۼӺ����ֵҲԽС
//�ṩһ������func(),�����ۼӺ�m,�����������������ۼӺ����ֵ������mʱ,����Ҫ���ֶ��ٸ�����
//�������ֵret<=k,˵��[m,A]�����ж��Ǵ���,�еĻ���������û�б����Ź���,���Ծ͵��������,���ۼӺ;����ܵ�С
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    int splitArray(vector<int>& nums, int k)
    {
        int l = 0, r = 0;
        for (int x : nums)
            r += x;
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int cur = func(nums, mid);
            if (cur <= k)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return (int)ans;
    }
    //��ĳһ���㳬��m,˵���޷���������
    int func(vector<int>& nums, int m)
    {
        int sum = 0;
        int count = 1;//���ֵõ�������������ʼ��Ϊ1
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > m)
                return INT_MAX;
            if (sum + nums[i] > m)
            {
                count++;
                sum = nums[i];
            }
            else
                sum += nums[i];
        }
        return count;
    }
};