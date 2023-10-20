//https://leetcode.cn/problems/unique-substrings-in-wraparound-string
#include<iostream>
#include<vector>
using namespace std;
//˼·1:
//��iλ�� �ַ� Ϊ��β,dp[i]��ʾ��iλ�� �ַ� Ϊ��β�������Ӵ���,��Base�г��ֹ��ĸ���
// 
//���⻮��: �Լ�һ���Ӵ�(һ����Base�г���1)�Լ���ǰ��Ľ�Ϲ����Ӵ�,
// 
//��i-1Ԫ��Ϊ��β��base�г��ֹ�,dp[i-1],�ڼ�����֮�󻹳��ֹ�,[i-1]+1=[i] || [i-1]=='z'&&[i]=='a'
//��β���ϼ���,������ǰi-1����ͬ,dp[i]=dp[i-1].
//dp[i]=dp[i-1] +1 
//��ʼ��: ���ж���ʼ��Ϊ1,����ת�Ʒ���ֻ��Ҫ�жϺ�ǰ�����������ʱ,dp+=dp[i-1]
//���˳��: ������
//����ֵ:��������dp�������ֵ�������ĺ�.����,������ظ��ַ������ظ��ۼ�,����Ҫȥ��
//��ͬ�ַ���β��dpֵ,����ȡ�ϴ�ļ���.��Ϊ�ϴ�Ĵ�����ͬ�ַ���β�������Ǹ��ַ���,�϶����������˶̵��Ǹ��ַ���,�����ͱ������ظ�����.
//��int [26]�����Ӧ�ַ���β�����dpֵ����.������������ĺ�
class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        int n = s.size();
        vector<int>dp(n, 1);
        //��iλ�� �ַ� Ϊ��β�������Ӵ���Base�г��ֵĴ���
        //�Լ�һ��->1���ߺ�ǰ��Ĳ������->dp[i]=dp[i-1],����ǳ��Ȳ�+1
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
                dp[i] += dp[i - 1];
        }
        //��ͬ�ַ���β��,���Ŀ϶����������˶̵�,Ҫ�����ۼӺ�,����Ҫȥ��
        //������󼴿����
        int hash[26] = { 0 };
        for (int i = 0; i < n; i++)
            hash[s[i] - 'a'] = max(dp[i], hash[s[i] - 'a']);
        int ret = 0;
        for (auto e : hash)
            ret += e;
        return ret;
    }
};
//˼·��:
//��iλ���ַ�Ϊ��β,��S����̽�ֳ��ֹ�����󳤶�,�������������Base���г��ִ���,ȥ�صĹ���
//ab����bΪ��β��ǰ������쳤����2<=>��bλ���ַ�Ϊ��β,���ɵ��Ӵ�����Base�г��ֹ���,һ��������,b,ab
// ����ת��:
//dp[i]��ʾ��s�ַ�������iλ���ַ�Ϊ��β,��ǰ������쳤���Ƕ���,��Ȼ��������base�������ǰ����
//https://www.bilibili.com/video/BV1Ww41167Ac?t=10659.2
class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        int n = s.size();
        vector<int>str(n);
        for (int i = 0; i < n; i++)
            str[i] = s[i] - 'a';

        vector<int>dp(26);//ͳ�Ƶ���26���ַ�,��ǰ�ܹ��������󳤶�
        dp[str[0]] = 1;
        for (int i = 1,len=1; i < n; i++)
        {
            int cur = str[i];
            int prev = str[i - 1];
            if (prev + 1 == cur || (prev == 25 && cur == 0))
                len++;
            else
                len = 1;
            dp[cur] = max(dp[cur], len);
        }
        int ans = 0;
        for (int i=0;i<26;i++)
            ans += dp[i];
        return ans;
    }
};