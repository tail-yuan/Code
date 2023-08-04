#include<iostream>
#include<vector>
using namespace std;
class Solution1
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int>dp(n);
        dp[0] = s[0] == '0' ? 0 : 1;
        if (n == 1) return dp[0];
        //��Ϊ�Ǵ�ǰ����,���ǰ����Ǹ���������,˵����i-1���޷�ת��,��ô�͸�û��Ҫ�ж�iλ���Ƿ��ܹ�ת��,����Ҫ��֤ǰһ��Ҳ��ת��,Ϊ�˴���06 05���ֲ���ת�������
        if (s[0] != '0' && s[1] != '0') dp[1] += 1;
        int t = (s[0] - '0') * 10 + s[1] - '0';
        if (t >= 10 && t <= 26)
            dp[1] += 1;
        for (int i = 2; i < n; i++)
        {
            if (s[i] != '0') dp[i] += dp[i - 1];
            int t = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (t >= 10 && t <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n - 1];
    }
};
class Solution2
{
public:
    //s�ַ���,�ܽ���,���ؽ�����,�Ͳ��ܽ���,return 0.
    //dp[i]��iΪ��β���ַ���,�ܹ��õ�����ķ�����.���s[i]==0,s[i-1]��s[i]���ܺϲ�����,��ôdp[i]=0,��i��β���ַ������ܽ���
    //����ܹ���������,dp[i] += d[i-1];����ܹ��ϲ�����,dp[i]+=dp[i-2]
    //dp[i]=dp[i-1]+dp[i-2],���൱����̨��,���ϵ���i��,Ҫô�Ǵ�i-1һ��������,Ҫô�Ǵ�i-2һ����������.���ַ�ʽ����,zuo����
    int numDecodings(string s)
    {
        int n = s.size();
        return zuo(s, n - 1);
    }
    //[0,index]�ܹ�����ĸ���
    //������,������: index,1. �Լ�ת��,2. ��ǰ��һ�����
    int zuo(string& s, int index)
    {
        //����:
        if (index == 0)
            return s[0] == '0' ? 0 : 1;
        if (index == 1)
        {
            int ret = 0;
            if (s[0] != '0' && s[1] != '0') ret += 1;

            int t = (s[0] - '0') * 10 + s[1] - '0';
            if (t >= 10 && t <= 26)
                ret += 1;
            return ret;
        }
        //index>=2
        int p1 = 0, p2 = 0;
        if (s[index] != '0')
            p1 = zuo(s, index - 1);
        int t = (s[index - 1] - '0') * 10 + s[index] - '0';
        if (t >= 10 && t <= 26)
            p2 = zuo(s, index - 2);
        return p1 + p2;
    }
};
class Solution3
{
public:
    int numDecodings(string s)
    {
        //����dp[1]��ʼ���ͺ����������ಿ��,�����Ż�
        //�࿪һ���ռ�,��ԭdp�������ݼ������Ų��һλ,
        //����Ҫע������:;
        //1. ������������µ�dp��,��������һ�����±��ж�s���ַ�ʱ,�±����Ҫ-1��
        //2. �������һλ����dp[0]��ʼ��Ϊdp[0]=1,��֤���������ȷ
        int n = s.size();
        vector<int>dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;//ԭdp����0λ�õĳ�ʼ��
        //��ԭdp����1λ�����뵽����ѭ������
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (t >= 10 && t <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];//ԭ������dp[n-1]
    }
};
//int main()
//{
//    string s = "1111111111111111111";
//    Solution1 s1;
//    Solution2 s2;
//    cout << (s1.numDecodings(s) == s2.numDecodings(s));
//
//}