//https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
//ʹ�õ���ջ��˼��,�ҵ�indexλ������������Լ�С��λ��,��ô��ѹС�ĵ�����,���ʱ��Ҳ����,
//���Լ��ĸ߶����������߽�������,���nums[cur]<=��������ĸ߶�,����������,�����ͣ��
// �õ����������(i-left-1)*nums[cur],����¼���������Сֵ����
//ģ���ϸ�������������С������
//����ģ��,�������ظ�ֵʱ�������?https://www.bilibili.com/video/BV1HH4y1X7T9?t=5368.6,���ֿ�������

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>st(n);
        int r = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (r > 0 && nums[st[r - 1]] >= nums[i])
            {
                int cur = st[--r];
                int left = r>0 ?st[r - 1]:-1;
                ans = max(ans, (i - left - 1) * nums[cur]);
            }
            st[r++] = i;
        }
        while (r > 0)
        {
            int cur = st[--r];
            int left = r > 0 ? st[r - 1] : -1;
            ans = max(ans, (n - left - 1) * nums[cur]);
        }
        return ans;
    }
};