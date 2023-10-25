//https://leetcode.cn/problems/longest-common-subsequence/
#include<iostream>
#include<vector>
using namespace std;
//dp[i][j]��ʾs1[0...i]ƥ��s2[0...j]�����е���󳤶�
//���������ַ��������λ��,i,j
//if s1[i]==s2[j],dp[i][j]=dp[i-1][j-1]+1
//else  ����ѡ��,��s1[0...i]ȥƥ��s2[0...j-1],dp[i][j]=dp[i][j-1]
//             ,��s1[0...i-1]ȥƥ��s2[0...j],dp[i][j]=dp[i-1][j]
//����ѡ���ϴ�ֵ����
//��ʼ��: ����д��һ��,��һ��ʱ�漰��ֱ�Ӷ������ַ���������,���Խ������ϵ��������������
// ���Բ�ȡ�࿪һ��,�࿪һ�еķ�ʽ,
// 1. ע���ʼ���¿���0��0��,��i=0ʱ,�����һ�м�s2Ϊ��ʱ,ƥ��s1Ϊ0,ͬ���һ�ж���ʼ��Ϊ0
// // 2. ����ԭ�ַ���ʱע���±�-1 / ��ԭ�ַ���+" "����
// 
//���˳��: ������
//����ֵ: dp[n][m]
class Solution3 
{
public:
    int longestCommonSubsequence(string s1, string s2) 
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        s1 = " " + s1,s2=" "+s2;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i] == s2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
//--------------------------���潫����ΪʲôҪ�࿪һ��,�࿪һ���������˼·------------
//dfs
//p1: ������β����Ҫ,s1[0...i-1]��s2[0...j-1]
//p2: Ҫs1��β,��Ҫs2��β,s1[0...i-1]��s2[0...j]
//p3: Ҫs2��β,��Ҫs1��β,s1[0...i]��s2[0...j-1]
//p4: ������β��Ҫ,��β��ͬ, s1[0...i - 1]��s2[0...j - 1] +1

class Solution4
{
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        return dfs(s1, s2, s1.size() - 1, s2.size() - 1);
    }
    int dfs(string& s1, string& s2, int i, int j)
    {
        if (i < 0 || j < 0)
            return 0;
        int p1 = dfs(s1, s2, i - 1, j - 1);
        int p2 = dfs(s1, s2, i , j - 1);
        int p3 = dfs(s1, s2, i - 1, j);
        int p4 = (s1[i] == s2[j] ? 1 : 0) + dfs(s1, s2, i - 1, j - 1);
        return max(p1, max(p2, max(p3, p4)));
    }
};
//ʹ��dp���¼ʱ,��Ҫ��¼dp[-1][-1]=0,����������memo����dp�洢,�����Խ���λ��,
// �������۳���,Ȼ��࿪һ��һ��
// 
// ���Խ��±�����Ϊǰ׺������Ϊ�ɱ����,len
// ��i,jλ��Ϊ��β���������ַ���
//��Ϊ��þ����,��Ȼi,jλ�þ��Ѿ�ƥ����,��û��Ҫp1�ƵĻ������ٵ�ǰ���С�����ҽ��,����p1û��Ҫ
//
//���ܴ��ڶ�μ���s1[i]s2[j]��dp[i][j],���Կ�������Ϊ���仯����memo
class Solution5
{
    vector<vector<int>>memo;
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        memo = vector<vector<int>>(n+1,vector<int>(m+1,-1));
        //��Ϊ���ȵķ�Χ��0~n,����Ҫ�࿪һ���ռ�
        return dfs(s1, s2,n, m);
    }
    int dfs(string& s1, string& s2, int len1, int len2)
    {
        if (len1 == 0 || len2 == 0)
            return 0;
        if (memo[len1][len2] != -1)
            return memo[len1][len2];
        int ans = 0;
        if (s1[len1 - 1] == s2[len2 - 1])
            ans = dfs(s1, s2, len1 - 1, len2 - 1) + 1;
        else
            ans = max(dfs(s1, s2, len1 - 1, len2), dfs(s1, s2, len1, len2 - 1));
        memo[len1][len2] = ans;
        return ans;
    }
};

//https://www.bilibili.com/video/BV1WQ4y1W7d1?t=5298.2
//�ϸ����λ������,��������,��,��,�������˳���Ǵ�����
//********��ʱ��0��,��0��,�ֱ����s1,s2����Ϊ0ʱ��ƥ�����,����˵����0,���Կ���ֱ�Ӵ�1,1λ�ÿ�ʼ
//********�����Ϊʲô�࿪һ�ж࿪һ��,��ΪҪ����Խ����������,����ĵ���˼·.
class Solution5
{
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.size(),m=s2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        for (int len1 = 1; len1 <= n; len1++)
        {
            for (int len2 = 1; len2 <= m; len2++)
            {
                if (s1[len1 - 1] == s2[len2 - 1])
                    dp[len1][len2] = dp[len1 - 1][len2 - 1] + 1;
                else
                {
                    dp[len1][len2] = max(dp[len1 - 1][len2], dp[len1][len2 - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
//��ά����ռ�ѹ��,
//************Ϊ�˽�һ������һά�����ռ�ÿռ�,���ó��ȶ̵��Ǹ���Ϊ��
//https://www.bilibili.com/video/BV1WQ4y1W7d1?t=5681.1
//��һ�������洢���Ͻ�,���Ź�����ȥ����
//��ʵ���Ǹ���iλ��ʱ,leftUp=dp[i],Ȼ�����dp[i],leftUp���Ÿ�����i+1λ��ʱ��\
//��ʼ��Ϊ0����,��Ϊ��������������Ͻ���0
//��ʱ�����Ž�
class Solution6
{
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        if (s1.size() < s2.size())
            swap(s1, s2);
        //����֮��,s1�ǳ���,s2�Ƕ̵��Ǹ�,��s2����,��һά����ĳ���
        int n = s1.size(), m = s2.size();
        vector<int>dp(m + 1);
        for (int len1 = 1; len1 <= n; len1++) 
        {
            int leftUp = 0, backup;//backUp ����δ���µ�dp[i]
            for (int len2 = 1; len2 <= m; len2++) 
            {
                backup = dp[len2];
                if (s1[len1 - 1] == s2[len2 - 1]) 
                    dp[len2] = 1 + leftUp;
                else 
                    dp[len2] = max(dp[len2], dp[len2 - 1]);
                
                leftUp = backup;//������ȥ
            }
        }
        return dp[m];

    }
};