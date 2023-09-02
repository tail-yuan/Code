//https://leetcode.cn/problems/minimum-size-subarray-sum/description/

//���:
//��������

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    //O(N):rһֱ������,�ߵ�n��ͣ������
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int ans = INT_MAX;
        int sum = 0;
        for (int l=0,r=0;r<nums.size();r++)
        {
            sum += nums[r];
            while (sum - nums[l] >= target)//����������߽�,Ѱ��������������Сֵ
                sum -= nums[l++];
            if (sum >= target)
                ans = min(ans, r - l + 1);
        }
        return ans==INT_MAX?0:ans;
    }
};