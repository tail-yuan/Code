//https://leetcode.cn/problems/trapping-rain-water/
//iλ���Ϸ��ܹ���ż������ӵ�ˮ��,Ȼ���ۼ�
//water[i]= min(����������ֵ,�Ҳ��������ֵ) -arr[index],
//���water[i]<0,˵��indexλ���㹻��,����û��ˮ�洢,ֱ�ӵ���0����
//����֮��: water[i]= max(0,min(����������ֵ,�Ҳ��������ֵ) -arr[index])
//���Կ���ʹ�ø�������ֱ��¼iλ��������ֵ,�Ҳ����ֵ��ʲô����

//�ⷨ��: ˫ָ���Ż��ռ临�Ӷ�
//lmax=nums[0],rmax=nums[n-1],l=1,r=n-2
//if lmax>rmax,��ôrλ�õ�ˮ���Ϳ���ȷ����,��Ϊrλ��ˮ��ȡ���������������ֵ�н�Сֵ,Ҳ����rmax,
//Ϊʲô����˵ȷ����? �����������в����ڱ�lmax����ֵ,ѡ���ƿ����rmax,���ڱ�lmax�����ֵ,ѡ��ƿ����Ȼ��rmax
//����˵����ȷ����,����ˮ��֮��,�ƶ�rָ��,����rmax
//ͬ�� lmax<rmax
//��lmax==rmaxʱ,������ѡ�����,����Ǹ�����.
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    //<O(N),O(N)>
    int trap1(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0] = nums[0];
        for (int i = 1; i < n; i++)
            left[i] = max(nums[i], left[i - 1]);
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], nums[i]);
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans += max(0, min(left[i], right[i]) - nums[i]);
        return ans;
    }
    int trap(vector<int>& nums)
    {
        int n = nums.size();
        int l = 1, r = n - 1, lmax = nums[0], rmax = nums[n - 1];
        int ans = 0;
        while (l <= r)
        {
            if (lmax <= rmax)
            {
                ans += max(0, lmax - nums[l]);
                lmax = max(nums[l++], lmax);
            }
            else
            {
                ans += max(0, rmax - nums[r]);
                rmax = max(nums[r--], rmax);
            }
        }
        return ans;
    }
};