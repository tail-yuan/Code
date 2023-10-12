
//https://leetcode.cn/problems/count-submatrices-with-all-ones/
//�ȵõ�һά�����б�������Ϊ�׵ľ���ĸ���
//��������ظ�ֵ: https://www.bilibili.com/video/BV1GH4y1D7TB?t=5029.8
//  ��Ϊ��ȵ���ջ���Ĳ������,�ȵ��������ֵ����ʱͳһ����ܰ�֮ǰ�����ж�ʧ�Ķ��һ���
//���θ�����ô����? 1 2 3 ���γ�6����Ͼ���3*(3+1)/2,
//����ͬ��m*n�ľ���,���γɵľ��θ������� (m*(m+1)/2)*n
//https://github.com/algorithmzuo/algorithm-journey/blob/main/src/class053/Code04_CountSubmatricesWithAllOnes.java
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    vector<int>st;
    vector<int>tmp;
public:
    int numSubmat(vector<vector<int>>& mat)
    {
        int n = mat.size(), m = mat[0].size();
        st = vector<int>(m);
        tmp = vector<int>(m);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                tmp[j] = mat[i][j] == 0 ? 0 : tmp[j] + 1;
            ans += countFromBottom(m);
        }
        return ans;
    }
    //������ĳһ��Ϊ��ʱ�ܹ����������ٸ�����
    int countFromBottom(int m)
    {
        int r = 0;
        int left = 0, len = 0, bottom = 0;
        int ans = 0;
        for (int i = 0; i <m; i++)
        {
            while (r > 0 && tmp[i] <= tmp[st[r - 1]])//����Ҳ����
            {
                int cur = st[--r];
                if (tmp[cur] != tmp[i])
                {
                    //ֻ���ϸ���ڵ�ʱ���������
                    left = r > 0 ? st[r - 1] : -1;
                    len = i - left - 1;
                    bottom = max(left == -1 ? 0 : tmp[left], tmp[i]);
                    ans += (tmp[cur] - bottom) * len * (len + 1) / 2;
                }
            }
            st[r++] = i;
        }
        while (r > 0)
        {
            int cur = st[--r];
            left = r > 0 ? st[r - 1] : -1;
            len = m - left - 1;
            int down = left == -1 ? 0 : tmp[left];
            ans += (tmp[cur] - down) * len * (len + 1) / 2;
        }
        return ans;
    }
};