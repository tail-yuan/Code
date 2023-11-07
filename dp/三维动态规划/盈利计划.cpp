//https://leetcode.cn/problems/profitable-schemes/description/
#include<iostream>
#include<vector>
using namespace std;

//ʹ��dfs->memo���仯�����ķ�ʽ
class Solution7 
{
    vector<vector<vector<int>>>memo;
    const int MOD = 1000000007;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        int m = group.size();
        memo = vector<vector<vector<int>>>(m,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return dfs(0, group, profit, n, minProfit);
    }
    //������indexλ��ʱ����ʣ��rest���ˣ�����Ҫneed�����ܴﵽ��׼������һ���ж����ַ�����
    int dfs(int index,vector<int>& group, vector<int>& profit, int rest, int need)
    {
        if (rest <= 0)//��ʣ������
            return need == 0 ? 1 : 0;
        if (index == group.size())//�����Ѿ��ľ���
            return need == 0 ? 1 : 0;

        if (memo[index][rest][need] != -1)
            return memo[index][rest][need];

        //��ѡ��ǰ����
        int p1 = dfs(index+1, group, profit, rest, need);
        int p2 = 0;
        //ѡ��ǰ����
        if(group[index]<=rest)//��ǰ������Ҫ������ <= ʣ�µ�����
            p2 = dfs(index + 1, group, profit, rest - group[index], max(0,need - profit[index]));
        int ans = (p1 + p2) % MOD;
        memo[index][rest][need] = ans;
        return ans;
    }
};
//�����ϸ�λ�������������Ż�Ϊ��λ��̬�滮��
//����Ҫ����С��0ʱ������Ϊ0�������ꡣ��ΪҪ����Ϊdp����д洢��Ȼ��ʹ��need���в�ѯʱ���������dp[-100]Խ������
//https://www.bilibili.com/video/BV1gM41197rM?t=2562.8 �ռ�ѹ��Ϊ��ά
//������i+1�㣬���Եõ���5�㣬ϣ���Ƶ�����4�㣬���������¶�λ��Χ���䡣
//��ʼ���� ��������߲�ʱ����i=mʱ������û��ʣ�๤��ʱ����ʼ��Ϊ1
class Solution8
{
    const int MOD = 1000000007;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)
    {
        vector<vector<int>>dp(n + 1, vector<int>(minProfit + 1, 0));
        int m = group.size();
        //��ά���е�need=0ʱ����ʼ��Ϊ1
        for (int r = 0; r <= n; r++)
            dp[r][0] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int r = n; r >= 0; r--)
            {
                for (int need = minProfit; need >= 0; need--)
                {
                    int p1 = dp[r][need];
                    int p2 = 0;
                    if (r >= group[i])
                        p2 = dp[r - group[i]][max(0, need - profit[i])];
                    dp[r][need] = (p1 + p2)% MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};

//����01����˼��
//dp[i][j][k]��ʾ�� ǰi�������� ��ѡ�������㣨����������j���������£�����С��Kʱ��ѡ������ķ�������
//��iλ�õ�����ѡ��ѡ������,�����ѡ,dp[i-1][j][k],���ѡ��,dp[i-1][j-g[i]][k-p[i]]
//j-g[i]<0,�����i������������Ѿ�����j������,���Բ���.
//k-p[i]<=0,�����i����������������Ѿ�����Ԥ��k,�ǿ��Ե�.
// ����ǰi-1��ѡ��ʱֻ��Ҫ������p[i]>=k����,k`=[max(0,k-p[i])]
//��������õ��ļƻ�����Ӽ���
//��ʼ���� ��ǰ0������ѡ������������<=jʱ������С��0����ô����һ�ַ�ʽ����ѡ������Ϊ1
//���˳�� ֻ��Ҫi��С������У�jk����ν
//�࿪һ��һ��ʱ��֤����ԭ����ʱҪ�±� -1 
class Solution9
{
    const int MOD = 1000000007;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)
    {
        int len = group.size();
        vector<vector<vector<int>>>dp(len+1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        for (int j = 0; j <= n; j++)
            dp[0][j][0] = 1;

        for (int i = 1; i <= len; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for(int k=0;k <= minProfit;k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= group[i - 1])
                        dp[i][j][k] += dp[i - 1][j - group[i-1]][max(0, k - profit[i-1])];
                    dp[i][j][k] %= MOD;
                }
            }
        }
        return dp[len][n][minProfit];
    }
};

//���������Ż�Ϊ��ά����Ҫ����jk�ĸ���˳����Ҫ�Ӵ���С�˸���
class Solution10
{
public:
    int profitableSchemes(int n, int m, vector<int>& g, vector<int>& p)
    {
        const int mod = 1e9 + 7;
        int len = g.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        for (int j = 0; j <= n; j++)
            dp[j][0] = 1;

        for (int i = 1; i <= len; i++)
        {
            for (int j = n; j >= g[i - 1]; j--)
            {
                for (int k = m; k >= 0; k--)
                {
                    dp[j][k] += dp[j - g[i - 1]][max(0, k - p[i - 1])];
                    dp[j][k] %= mod;//Ϊ�˱�������������intԽ��
                }
            }
        }
        return dp[n][m];
    }
};