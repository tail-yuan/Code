//https://leetcode.cn/problems/sum-of-subarray-minimums/description/
//����һ���������� arr���ҵ� min(b) ���ܺͣ����� b �ķ�ΧΪ arr ��ÿ���������������顣
//���ڴ𰸿��ܴܺ���� ���ش�ģ 10 ^ 9 + 7 ��

//ʹ�õ���ջ˼���ҵ�curλ������������Լ�С�����������λ��x,y
// ��ô��[x+1,y-1]������,cur������Сֵ,��ô�������cur��������ĸ�������
// (cur-x) * (y-cur)��,��ô��Щ����ĺ;��Ǹ���*arr[cur]
//������� : https://www.bilibili.com/video/BV1HH4y1X7T9?t=4183.4
// ����ջ���ֵʱ��Ȼ��ȡ��������
//�������ֵʱ���ܴ���©��? ����,������Խ����µ�������
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        const int MOD = 1000000007;
        int n = arr.size();
        vector<int>st(n);
        long long ans = 0;
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            while (r > 0 && arr[st[r - 1]] >= arr[i])
            {
                int cur = st[--r];
                int left = r == 0 ? -1 : st[r - 1];
                ans = (ans + (long long)(cur - left) * (long long)(i - cur) * arr[cur]) % MOD;
            }
            st[r++] = i;
        }
        while (r > 0)
        {
            int cur = st[--r];
            int left = r == 0 ? -1 : st[r - 1];
            ans = (ans + (long long)(cur - left) * (long long)(n - cur) * arr[cur]) % MOD;
        }
        return (int)ans;
    }
};
