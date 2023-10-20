//https://leetcode.cn/problems/decode-ways-ii/description/
//https://www.bilibili.com/video/BV1Ww41167Ac?t=6763.3
#include<iostream>
#include<vector>
using namespace std;

//�ڽ��뷽���Ļ�����������*����ת��Ϊ1~9������һ������,��i��i+1λ�ý������ۼ���
class Solution1
{
public:
    int numDecodings(string s) 
    {
        return func(s, 0);
    }
    int func(string& s, int i)
    {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        //����ת��
        int ans = func(s, i + 1) * (s[i] == '*' ? 9 : 1);
        if (i + 1 < s.size())
        {
            if (s[i] != '*')
            {
                if (s[i + 1] != '*')
                {
                    //s[index]:  num num
                    //index:     i  i+1
                    if ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
                        ans += func(s, i + 2);
                }
                else
                {
                    //s[index]:  num *
                    //index:     i  i+1
                    if (s[i] == '1')
                        ans += 9 * func(s, i + 2);
                    else if (s[i] == '2')
                        ans += 6 * func(s, i + 2);
                }
            }
            else
            {
                if (s[i + 1] != '*')
                {
                    //s[index]:  * num
                    //index:     i i+1
                    if (s[i + 1] <= '6')
                        ans += 2 * func(s, i + 2);//11~16 21~26 ���ַ���
                    else
                        ans += func(s, i + 1);//17~19 һ�ַ���
                }
                else
                {
                    //s[index]:  * *
                    //index:     i i+1
                    ans += 15 * func(s, i + 2);
                }
            }
        }
        return ans;
    }
};
class Solution2
{
    vector<long long>memo;
    static const long long mod = 1000000007;
    int n;
public:
    int numDecodings(string s)
    {
        n = s.size();
        memo = vector<long long>(n,-1);
        return (int)func(s, 0);
    }
    long long func(string& s, int i)
    {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (memo[i] != -1)
            return memo[i];

        //����ת��
        long long  ans = func(s, i + 1) * (s[i] == '*' ? 9 : 1);
        if (i + 1 < s.size())
        {
            if (s[i] != '*')
            {
                if (s[i + 1] != '*')
                {
                    //s[index]:  num num
                    //index:     i  i+1
                    if ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
                        ans += func(s, i + 2);
                }
                else
                {
                    //s[index]:  num *
                    //index:     i  i+1
                    if (s[i] == '1')
                        ans += 9 * func(s, i + 2);
                    else if (s[i] == '2')
                        ans += 6 * func(s, i + 2);
                }
            }
            else
            {
                if (s[i + 1] != '*')
                {
                    //s[index]:  * num
                    //index:     i i+1
                    if (s[i + 1] <= '6')
                        ans += 2 * func(s, i + 2);//11~16 21~26 ���ַ���
                    else
                        ans += func(s, i + 2);//17~19 һ�ַ���
                }
                else
                {
                    //s[index]:  * *
                    //index:     i i+1
                    ans += 15 * func(s, i + 2);
                }
            }
        }
        ans %= mod;
        memo[i] = ans;
        return ans;
    }
};
//�ϸ�λ������,ת��Ϊdp,�����������
//��ʼ��dp[n]=1
//�������ansת��Ϊdp[i]����,��������ȡģ
