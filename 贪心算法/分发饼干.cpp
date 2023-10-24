
//https://leetcode.cn/problems/assign-cookies/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//���ȿ϶���Ҫ�Ƚ������������
//���s[j]>g[i],˵��������ӿ�������,����ret++;
//����֮���������̰�ĵ�˼��.
//���ý�����֤����֤��ȷ
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size();
        int ret = 0;
        for (int i = 0, j = 0; i < n && j < m; i++,j++)
        {
            while (j<m && g[i] > s[j])
                j++;
            if (j < m) ret++;
        }
        return ret;
    }
};