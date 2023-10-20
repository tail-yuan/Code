//https://leetcode.cn/problems/decode-ways/
#include<iostream>
#include<vector>
using namespace std;


//�����ҳ���ģ��
//func(i)����s[i...]���������ַ�ת���ķ�����
//1. '0'ת������,����ת������,�������������һ����֧����ֱ�ӷ���,s[i...]��������0
//2. �Լ�ת
//3. �Լ��ͺ���һ���ַ�ת��
class Solution1
{
public:
    int numDecodings(string s)
    {
        return func(s,0);
    }
    int func(string& s, int i)
    {
        if (i == s.size())//���������֧������ͨ,��һ�ַ���
            return 1;
        if (s[i] == '0')
            return 0;
        int ans = 0;
        if (i + 1 < s.size() && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
            ans += func(s, i + 2);
        return ans;
    }
};
//�����ظ�����,���Ը�Ϊ���仯����
class Solution2
{
    vector<int>memo;
    int n;
public:
    int numDecodings(string s)
    {
        n = s.size();
        memo = vector<int>(n,-1);
        return func(s, 0);
    }
    int func(string& s, int i)
    {
        if (i == s.size())//���������֧������ͨ,��һ�ַ���
            return 1;

        if (memo[i] != -1)
            return memo[i];

        int ans = 0;
        if (s[i] == '0')
        {
            ans = 0;
        }
        else
        {
            ans += func(s, i + 1);
            if (i + 1 < s.size() && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
                ans += func(s, i + 2);
        }
        memo[i] = ans;
        return ans;
    }
};

//�ϸ�λ����������: ����������д���
class Solution3 
{
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        vector<int>dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                dp[i] = 0;
            else
            {
                dp[i] = dp[i + 1];
                if (i + 1 < n &&( (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26))
                    dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};
//����iλ��ֻ������i+1��i+2λ��,���Կ���������������¼,�������¼���
//�ռ临�Ӷ��Ż�ΪO(1)
class Solution4
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        int next = 1;//dp[i]
        int nextnext = 0;//dp[i+1]
        for (int i = n - 1,cur=0; i >= 0; i--)
        {
            if (s[i] == '0')
                cur = 0;
            else
            {
                cur = next;
                if (i + 1 < n && ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26))
                    cur += nextnext;
            }
            nextnext = next;
            next = cur;
        } 
        return next;
    }
};