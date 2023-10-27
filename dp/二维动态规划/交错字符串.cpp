//https://leetcode.cn/problems/interleaving-string/
// s3�ĳ��ȿ϶���s1��s2������ӵĺ�,������Ǿͷ���false
//dp[i][j]��ʾs1ǰi���ַ�,��s2ǰj���ַ�,���s3��ǰi+j���ַ�,�ܷ���
//ֻ����s3���һ���ַ�������s1����s2,
//dp[i][j]=dp[i-1][j] || dp[i][j-1],||����ѡ������һ������
//��ʼ��: �漰��i-1 j-1 ��ô�Ͷ࿪һ�ж࿪һ��
// 1. ע�⽫�¿��ٵĿռ��ʼ��,
//  ��0�д���s1ȡ0���ַ�,
//  ��0�д���s2ȡ0���ַ�,
// ֻ��Ҫ�ж��Ƿ񶼶�Ӧ���,��Ⱦ���true,ֻҪ����һ��λ�ò�ͬ,������false
// 2. ����ԭ�ַ���ʱע���±�-1,���߽�ԭ�ַ�����λ�üӸ�" "
//���˳��: �����Ϻ���,��������,��������
//����ֵ: dp[n][m]
#include<iostream>
#include<vector>
using namespace std;
class Solution34 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n = s1.size(), m = s2.size();
        if ((n + m) != s3.size())
            return false;
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;
        vector<vector<bool>>dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (s1[i] == s3[i])
                dp[i][0] = true;
            else
                break;
        }
        for (int j = 1; j <= m; j++)
        {
            if (s2[j] == s3[j])
                dp[0][j] = true;
            else
                break;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (s1[i] == s3[i + j] && dp[i - 1][j]) || (s2[j] == s3[i + j] && dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
//�ռ�ѹ��: �������Ϻ���,Ϊ�˱�����౻����,���Բ��ô�������ķ�ʽȥ��������
//��Ϊ��ԭ�ַ������޸�ֵ,�����Ч�ʵĽ���,�������Ǿ�ֱ��ʹ���±����,ֻ����ע��һ��-1����
class Solution35
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size())
            return false;
        vector<bool>dp(m + 1);
        dp[0] = true;
        for (int j = 1; j <= m; j++)
        {
            if (s2[j-1] == s3[j-1])
                dp[j] = true;
            else
                break;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[0] = s1[i - 1] == s3[i - 1] && dp[0];
            for (int j = 1; j <=m; j++)
            {
                dp[j] = (s1[i - 1] == s3[i + j - 1] && dp[j]) || (s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
            }
        }
        return dp[m];
    }
};