//https://leetcode.cn/problems/ones-and-zeroes/
//�ڸ�����������ѡ������������������ַ��������������Ӽ�
//������ 0������<m ,1������<n

#include<iostream>
#include<vector>
using namespace std;
//����ģ�ͣ� �����ң�indexλ�õ��ַ�������Ҫ���ǲ�Ҫ
//strs[index...]����ѡ��ѡ��0<zero,1<one���ַ����������ѡ������
class Solution1 
{
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        return dfs(strs, 0, m, n);
    }

    int zeros, ones;
    void count(string& str)
    {
        zeros = 0, ones = 0;
        for (auto ch : str)
        {
            if (ch == '1')
                ones++;
            else
                zeros++;
        }
    }
    int dfs(vector<string>& strs, int index, int zeroLimit, int oneLimit)
    {
        if (index == strs.size())
            return 0;
        //��ѡ��ǰ�ַ���
        int p1 = dfs(strs, index + 1, zeroLimit, oneLimit);
        //ѡ��ǰ�ַ���
        int p2 = 0;
        count(strs[index]);
        if (zeros < zeroLimit && ones < oneLimit)
            p2 = 1 + dfs(strs, index + 1, zeroLimit - zeros, oneLimit - ones);
        return max(p1, p2);
    }
};
//�������ж���ѡ�񵽴�indexλ��ʱ����ѯ�����ж�������������
//Ϊ�˱����ظ�����ļ��㣬��������Ϊ���仯����
class Solution2
{
    vector<vector<vector<int>>> memo;
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int sz = strs.size();
        memo = vector<vector<vector<int>>>(sz, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return dfs(strs, 0, m, n);
    }
    //zero,one
    pair<int, int>count(string& str)
    {
        int zero = 0, one = 0;
        for (auto ch : str)
        {
            if (ch == '0')
                zero++;
            else
                one++;
        }
        return { zero,one };
    }
    int dfs(vector<string>& strs, int index, int zero, int one)
    {
        if (index == strs.size())
            return 0;
        if (memo[index][zero][one] != -1)
            return memo[index][zero][one];
        int p1 = dfs(strs, index + 1, zero, one);
        int p2 = 0;
        pair<int,int>ret = count(strs[index]);
        if (ret.first <= zero && ret.second <= one)
            p2 = 1 + dfs(strs, index + 1, zero - ret.first, one - ret.second);
        memo[index][zero][one] = max(p1, p2);
        return memo[index][zero][one];
    }
};
//�����ϸ�λ��������index������index+1���������˳���Ǵ�������zero one ����������࣬�����Ǵ�������
//����ֵ�� dp[0][m][n]
//��ʼ���� dp[sz][][]=0,zero one���˳������ν����Ϊ���������ڱ����ֵ
class Solution3
{
public:
    //zero,one
    pair<int, int>count(string& str)
    {
        int zero = 0, one = 0;
        for (auto ch : str)
        {
            if (ch == '0')
                zero++;
            else
                one++;
        }
        return { zero,one };
    }
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int sz = strs.size();
        vector<vector<vector<int>>>dp(sz+1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = sz - 1; i >= 0; i--)
        {
            pair<int,int>ret = count(strs[i]);
            int zero = ret.first, one = ret.second;
            for (int z = 0; z <= m; z++)
            {
                for (int o = 0; o <= n; o++)
                {
                    int p1 = dp[i + 1][z][o];
                    int p2 = 0;
                    if (zero <= z && one <= o)
                        p2 = 1 + dp[i + 1][z - zero][o - one];
                    dp[i][z][o] = max(p1, p2);
                }
            }
        }
        return dp[0][m][n];
    }
};
//https://www.bilibili.com/video/BV1gM41197rM?t=1113.1
//�ռ�ѹ��
//Ҫ����zero��one������i+1���ϵ����ݣ���ô�������ά����i+1�����Ϊi�����ݣ���
//Ҫ����ĳһλ�ã�����������ֵ���Ǿ߱��ģ�����ֱ�Ӹ��³���.
//Ҫ����ֵ�ø��ǣ�����Ҫ��zero��one�ĸ���˳�������涨����Ϊzero��one�����Ķ�������ֵ
//���Ա�֤���߶��Ǵ���������£����ܱ�֤������ֵ����δ���µġ�
// ÿ�ζ���������һ���Լ���λ�ã�Ҳ����p1һ���Ǿ����ģ�ֻ��zero��one��������ʱ�Ż�����֮ǰ�ĸ���
// ���Ա���ʱ�������ֿ����Ե�PK
//ÿ����һ���ַ���������һ�α���

//�������ԣ���ά���Ż�Ϊ��ά���Ǻ��б�Ҫ�ġ�
class Solution4
{
    int zero, one;
public:
    void count(string& str)
    {
        zero = 0, one = 0;
        for (auto ch : str)
        {
            if (ch == '0')
                zero++;
            else
                one++;
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        for (string& str : strs)
        {
            count(str);
            for (int z = m; z >= zero; z--)
            {
                for (int o = n; o >= one; o--)
                {
                    dp[z][o] = max(dp[z][o],1+ dp[z - zero][o - one]);
                }
            }
        }
        return dp[m][n];
    }
};
//����һ����ⷽʽ�� 01�������⣬��ʵ�����ڸ��������У�����������������½�����ѡ���õ�����ֵ����
//��indexλ��Ϊ��β�������⣬
//��ά���õ�01��������
//dp[i][j]������Ǵ� ǰi�� ��Ʒ����ѡ���ݻ� ������j ����������ܴﵽ������ֵ
//��������ʵ���Ͼ��Ǹ���һ����ѡ����,������ĳЩ�����������ܴﵽ���������.
//dp[i][j][k]����ľ��Ǵ�ǰi���ַ�����ѡ��,������0�ĸ���������j,1�ĸ���������k�������ѡ���Ӽ���������
//�����i���ַ���ѡ���ǲ�ѡ������,����i�ַ���0�ĸ���a,1�ĸ���b,�����ѡ������ǰi-1����ѡ,dp[i-1][j][k]
//���ѡiλ���ַ���,dp[i-1][j-a][k-b],��Ϊ�Ǹ���,���Ի���+1,
//�������ȡ�ϴ�ֵ
//�ռ��Ż�: ��Ϊ����������һ��,���Ա�֤�Ӻ���ǰ����
class Solution6
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int len = strs.size();
        vector<vector<vector<int>>>dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        //��Ϊ�ǲ�������01��������,��ѡ��ǰ0������ѡ��ʱ���Ӽ�����Ϊ0
        for (int i = 1; i <= len; i++)
        {
            //ͳ��ѡ��i�ַ�����01���
            int a = 0, b = 0;
            for (auto ch : strs[i - 1])//��Ϊ�࿪һ�ж࿪һ��,ע�����ԭ����ʱ�±�����
            {
                if (ch == '0') a++;
                else b++;
            }
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= a && k >= b)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - a][k - b] + 1);
                }
            }
        }
        return dp[len][m][n];
    }
};
class Solution5
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int sz = strs.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= sz; i++)//��ǰi���ַ�����ѡ��
        {
            int a = 0, b = 0;
            for (auto ch : strs[i - 1])//����ԭ����ʱҪע���±�
            {
                if (ch == '0') a++;
                else b++;
            }
            for (int j = m; j >= a; j--)
            {
                for (int k = n; k >= b; k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j - a][k - b] + 1);
                }
            }
        }
        return dp[m][n];
    }
};