//https://leetcode.cn/problems/find-k-th-smallest-pair-distance/
// https://www.bilibili.com/video/BV1Mh4y1P7qE?t=4583.4
//��ֵ�Բ�ֵ��Χ,[0,maxVal-minVal]
//�ṩfunc����,������ֵm,���ز�ֵС�ڵ���m����ֵ�Եĸ����ж��ٸ�,
//������: ����ֵԽ��ʱ,С�ڵ��������ֵ����ֵ�Ը�����Խ��(ע����С�ڵ���)
//if ret<k,˵����ֵ��С��,��ȥ�Ҳ�������Ѱ��ֵ. if ret>=k,��¼��,�����
//����������״������Ӱ����,���Կ�������
//����: nlogn + log(max-min)*n
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int smallestDistancePair(vector<int>& nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0];
        int ans = 0;
        while (l <= r)
        {
            int mid = ((r - l) / 2) + l;
            if (func(nums, mid) < k)
                l = mid + 1;
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
    //������������Ѱ����ֵ��С�ڵ���limit ����ֵ���ж��ٸ�
    //ʹ�ô��ڽ��,����ָ�벻����,O(N)
    int func(vector<int>& nums, int limit)
    {
        int n = nums.size();
        int ans = 0;
        for (int l = 0, r = 0; l < n; l++)
        {
            while (r + 1 < n && nums[r + 1] - nums[l] <= limit)
                r++;
            //[0,3]=>[0,1][0,2][0,3]���Զ��������
            ans += r - l;
        }
        return ans;
    }
};