//https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
#include<iostream>
#include<vector>
using namespace std;
//�����ķ�ʽ��ʹ��˫ָ��,�̶�left,�ƶ�right,�ҵ���leftΪ��ͷ�ĵ���������ĳ���,ȷ���Ҷ˵�right-1
//��Ȼ��ʱ[right]<[left],��ô��[left+1,right-1]������ֵ����[right]��,��������̶�,
//���left����,�����ڽ�һ����С,���Կ���ֱ����left=right,����right��λ��,��������Ѱ��,����Ч��.
//̰��+˫ָ��
class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int ret = 0, n = nums.size();
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            while (j<n && nums[j]>nums[j - 1])
                j++;
            ret = max(ret, j - i);
            i = j;
        }
        return ret;
    }
};