//https://leetcode.cn/problems/daily-temperatures/
//����һ���������� temperatures ����ʾÿ����¶ȣ�����һ������ answer ��
// ���� answer[i] ��ָ���ڵ� i �죬��һ�������¶ȳ����ڼ����
// �����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档

//Ѱ�Һ�������Լ�������Լ����Ԫ��,
//ʹ�õ���ջ��˼��,ά���ӵ׵����Ӵ�С��˳��
//������ģ��,��������Ҳ�ܽ�,��Ϊ����ʱ���Ը���
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>st(n);
        vector<int>ans(n);
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            while (r > 0 && nums[st[r - 1]] < nums[i])
            {
                int pop = st[--r];
                ans[pop] = i-pop;
            }
            st[r++] = i;
        }
    }
};