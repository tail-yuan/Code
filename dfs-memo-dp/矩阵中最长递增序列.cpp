#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/submissions/
class Solution
{
    int m, n;
    int next[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
    int memo[201][201];
public:
    //˼·:��������,ѡ��һ����Ϊ���,dfs()ȥ���ĸ�����,ͳ���ۼӺ�,��¼��ÿһ���ڵ�Ϊͷ�Ĵ�ֵ
    //������,������: ��i,jλ��Ϊ���,�������4������Ѱ�ҵ���·��,����Ҫ�����ֵ��¼������,ret=max(ret,dfs())
    //����ͷ: ����dfs�������ǽ���i,jΪ��ʼ����·������,������int ����ֵ
    //����: ���ж�����,����û����
    //��֦: û�м�֦,����ܸ�Ϊ���仯����,����Ϊ��֦,���Ѿ���Ϊͷ��������ֱֵ�ӷ���
    //����:û�л���,����һ����ǰ����ǰ��
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        m = matrix.size(), n = matrix[0].size();
        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = dfs(matrix, i, j);
                ret = max(ret, count);
            }
        }
        return ret;
    }
    //����ֵ: ��i,jΪ���������·���ĳ���.
    //����ÿһ���ڵ㶼��Ҫ�Ƚϳ��ĸ��������󳤶�,�������Լ�����,������С����ֵҲ��1
    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if (memo[i][j] != 0) return memo[i][j];

        int ret = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + next[k][0], y = j + next[k][1];
            if (x < m && x >= 0 && y<n && y >= 0 && matrix[x][y]>matrix[i][j])
            {
                ret = max(ret, dfs(matrix, x, y) + 1);
            }
        }
        memo[i][j] = ret;
        return memo[i][j];
    }
};