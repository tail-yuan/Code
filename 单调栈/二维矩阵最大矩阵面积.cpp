
//https://www.bilibili.com/video/BV1HH4y1X7T9?t=6074.5

//��ά�������ѹ���������,
//�ֱ���index��Ϊ�׽���ѹ���������,Ȼ�������״ͼ�������ļ���
//��ѹ�������ʱ��,nums[j]�����index��jλ�������ж��ٸ�������1,
//Ȼ����nums�����н���ֱ��ͼ�������ļ���
//����������n*m,��ô�ӹ�����ʱ��ҪO(M),һ���ӹ�n��,����ʱ�临�Ӷ���O(N*M)


#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    vector<int>tmp;
    int r;
    vector<int>st;
public:
    int maximalRectangle(vector<vector<char>>& nums)
    {
        int n = nums.size(), m = nums[0].size();
        tmp = vector<int>(m);
        st = vector<int>(m);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                tmp[j] = nums[i][j] == '0' ? 0 : tmp[j] + 1;
            ans = max(ans, largestRectangleArea(m));
        }
        return ans;
    }
    int largestRectangleArea(int m)
    {
        r = 0;
        int ans = 0, cur=0, left=0;
        for (int i = 0; i < m; i++)
        {
            while (r > 0 && tmp[st[r - 1]] >= tmp[i])
            {
                cur = st[--r];
                left = r > 0 ? st[r - 1] : -1;
                ans = max(ans, tmp[cur] * (i - left - 1));
            }
            st[r++] = i;
        }
        while (r > 0)
        {
            cur = st[--r];
            left = r > 0 ? st[r - 1] : -1;
            ans = max(ans, (m - left - 1) * tmp[cur]);
        }
        return ans;
    }
};