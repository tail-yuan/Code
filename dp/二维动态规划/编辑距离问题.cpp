//https://leetcode.cn/problems/edit-distance
//dp[i][j]����s1[ǰ׺i��]��ȫ��Ϊs2[ǰ׺j��]����С�����Ƕ���
//https://www.bilibili.com/video/BV1cg4y1o719?t=1655.1
//��ʼ��: �࿪һ�ж࿪һ�еķ�ʽ
//  1. �¿����Ŀռ���Ҫ��ʼ����֤����������ȷ,��0�д���s1Ϊ��ʱ,�����α��s2�Ĵ��۾����������Ӿ���,dp[0][j]=j*����
//              ��0��,����s2Ϊ��ʱ,���ձ�Ϊ�յĴ��۾�������ɾ���� ,dp[i][0]=i*ɾ���Ĵ���
//dp[0][0]��ȫ����Ҫ��,����0.
// 2. ����ԭ�ַ�����ʱ����Ҫע���±�-1
//����ֵ: ����s1[ǰn��]��ȫ�仯Ϊs2[ǰm��]����С����
//���˳��,�����������,����-> �ϵ���

//��һ��С̰��: ����������һ��λ�ö�����ͬ,��ֱ��ʹ��s[i]λ�ü���,�Ͳ���Ҫ��������s[i]�ַ���
#include<iostream>
#include<vector>
using namespace std;
class Solution31 
{
public:
    int minDistance(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            dp[i][0] = i;
        for (int j = 1; j <= m; j++)
            dp[0][j] = j;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    int p1 = dp[i - 1][j] + 1;//ɾ��s[i]λ��
                    int p2 = dp[i][j - 1] + 1;//����
                    int p3 = dp[i - 1][j-1]+1;//�滻s[i]λ��
                    dp[i][j] = min(p1, min(p2, p3));
                }
            }
        }
        return dp[n][m];
    }
};
//�ռ�ѹ��:�����������,ע��leftUp����
//��������,ע���ʼ��
class Solution32
{
public:
    int minDistance(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<int>dp(m + 1);
        for (int i = 1; i <= m; i++)
            dp[i] = i;//���������������
        int leftUp = 0, backUp = 0;
        for (int i = 1; i <= n; i++)
        {
            leftUp = (i - 1) * 1;//����ɾ��������1
            dp[0] = i * 1;//ɾ������
            for (int j = 1; j <=m; j++)
            {
                backUp = dp[j];
                if (s1[i - 1] == s2[j - 1])
                    dp[j] = leftUp;
                else
                {
                    int p1 = dp[j]+1;//ɾ��,ʹ��dp[i-1][j],Ҳ����ǰһ�е�����,һά�����о��Ǳ�����δ���µ���ֵ
                    int p2 = dp[j - 1] + 1;//����,ʹ��dp[i][j-1],Ҳ������һ��,ǰһ�е�����,
                    int p3 = leftUp + 1;//�滻,ʹ��dp[i-1][j-1],Ҳ�������ϵ�ֵ
                    dp[j] = min(p1, min(p2, p3));
                }
                leftUp = backUp;
            }
        }
        return dp[m];
    }
};
//������,ɾ��,�滻���۾��廯ʱ,���´���
class Solution33 {
public:
    int minDistance(string word1, string word2) {
        return minDistance2(word1, word2, 1, 1, 1);
    }
    int minDistance2(string s1, string s2, int a, int d, int r)
    {
        int m = s1.size(), n = s2.size();
        vector<int>dp(n + 1);
        for (int i = 1; i <= n; i++)
            dp[i] = i * a;
        for (int i = 1; i <= m; i++)
        {
            int prev = dp[0];
            dp[0] = d * i;
            for (int j = 1; j <= n; j++)
            {
                int tmp = dp[j];//ԭ����һ�е�dp[i-1][j]
                if (s1[i - 1] == s2[j - 1])
                    dp[j] = prev;
                else
                {

                    int p1 = dp[j - 1] + a;
                    int p2 = dp[j] + d;
                    int p3 = prev + r;
                    dp[j] = min(p1, min(p2, p3));
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
};