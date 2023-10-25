//https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/
#include<iostream>
#include<vector>
using namespace std;
//˼·:��������,ѡ��һ����Ϊ���,dfs()ȥ���ĸ�����,ͳ���ۼӺ�,��¼��ÿһ���ڵ�Ϊͷ�����ֵ
//������,������: ��i,jλ��Ϊ���,�������4������Ѱ�ҵ���·��,����Ҫ�����ֵ��¼������,ret=max(ret,dfs())
//����ͷ: ����dfs�������ǽ���i,jΪ��ʼ����·������,������int ����ֵ
//����: ���ж�����,����û����
//��֦: û�м�֦,����ܸ�Ϊ���仯����,����Ϊ��֦,���Ѿ���Ϊͷ��������ֱֵ�ӷ���
//����:û�л���,����һ����ǰ����ǰ��
class Solution 
{
    int n, m;
    vector<vector<int>>memo;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        n = matrix.size(), m = matrix[0].size();
        memo = vector<vector<int>>(n+1,vector<int>(m+1));
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<m;j++)
            {
                int count = dfs(matrix, i, j);
                ret = max(ret, count);
            }
        }
        return ret;
    }
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    int dfs(vector<vector<int>>& matrix, int i, int j) 
    {
        if (memo[i][j] != 0)
            return memo[i][j];
        int ret = 1;//��С���Ⱦ�������,��ʼ��Ӧ����1
        for (int k = 0; k < 4; k++)
        {
            int x = dx[k] + i, y = dy[k] + j;
            if (x < n && x >= 0 && y<m && y >= 0 && matrix[x][y]>matrix[i][j])
            {
                ret = max(ret, dfs(matrix, x, y) + 1);//��¼i,j��ʼ�ĸ������м����Լ�֮�����󳤶�
            }
        }
        memo[i][j] = ret;
        return ret;
    }
};