//https://leetcode.cn/problems/increasing-triplet-subsequence/submissions/474081438/
#include<iostream>
#include<vector>
using namespace std;
//ʹ��̰�ĵ�˼��,ֻҪ�����˳���Ϊ3�ĵ���������,�ͷ���true
//������ȫ����ʹ��������������¼����Ϊ1,����Ϊ2�������е����һ��ֵ
class Solution
{
public:
    bool increasingTriplet(vector<int>& nums)
    {
        int a = nums[0], b = INT_MAX;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > b) return true;
            else if (nums[i] > a) b = nums[i];
            else if (nums[i] < a) a = nums[i];
        }
        return false;
    }
};