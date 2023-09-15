
// https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// https://www.bilibili.com/video/BV11h4y1w7Bu?t=3209.2
// ����һ���������� nums ����һ����ʾ���Ƶ����� limit�����㷵�������������ĳ��ȣ�
// ���������е���������Ԫ��֮��ľ��Բ����С�ڻ��ߵ��� limit ��
// ������������������������飬�򷵻� 0 ��

//ʹ�ô��ڵ÷���������,���˵����������������������֮��Ĳ�ֵ,��ô��������������ֵ����Сֵ�Ĳ�ֵ
//����������,��ô�����ǺϷ�������,���Ը��³������ֵ.��ô���������������,�½���������
//��ʹ��ֵ��ø���,���߲���.���½��������ֱ����ֵ��,���߱���СֵСʱ�ͻ�ʹ�ò�ֵ���,��������м�,����++;
//�����Ծͳ�����.���һ��С���䲻���,��ô������ȥ�Ĵ�����϶������,����l++;
// ���һ�������䶼���,��ôС����һ�����.
// ���½��������ֵ��²�ֵ>limitʱ,��l�����ĳ��Ⱦ�ȷ����,��¼���ֵ.
//��ô�����ʱ���O(1)��ȡ��������ֵ����Сֵ��?ʹ�������������о�����
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
    static const int N = 100001;
    vector<int>arr; 
    int min_h, min_t;
    int max_h, max_t; 
    int maxDeque[N] = { 0 };//��˫�˶���
    int minDeque[N] = { 0 };//С˫�˶���
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        min_h = min_t = max_h = max_t = 0;

        arr = nums;
        int ans = 0;
        //[L,R),ÿ�ζ�����Rλ�������ܷ����
        int n = arr.size();
        for ( int l = 0, r = 0; l < n; l++)
        {
            while (r < n && ok(limit, nums[r]))
                push(r++);

            ans = max(ans, r - l);
            pop(l);
        }
        return ans;
    }
    bool ok(int limit, int num)
    {
        int max_val = max_h < max_t ? max(arr[maxDeque[max_h]], num) : num;
        int min_val = min_h < min_t ? min(arr[minDeque[min_h]], num) : num;
        return max_val - min_val <= limit;
    }
    void push(int r)
    {
        while (max_h < max_t && arr[maxDeque[max_t - 1]] <= arr[r])
            max_t--;
        maxDeque[max_t++] = r;
        while (min_h < min_t && arr[minDeque[min_t - 1]] >= arr[r])
            min_t--;
        minDeque[min_t++] = r;
    }
    void pop(int l)
    {
        if (max_h < max_t && maxDeque[max_h] == l)
            max_h++;
        if (min_h < min_t && minDeque[min_h] == l)
            min_h++;
    }
};