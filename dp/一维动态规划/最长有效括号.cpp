//https://leetcode.cn/problems/longest-valid-parentheses/
#include<iostream>
#include<vector>
using namespace std;
//��iλ��Ϊ��β,������,��ܹ��õ��೤����Ч�����Ӵ�
//���õ���������е����ֵ����
//����֮ǰ�������dp[i]���۸����Լ�
//https://www.bilibili.com/video/BV1Ww41167Ac?t=9379.2
//dp[i]���������iλ��Ϊ��β�������,�������ƶ�Զ
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        vector<int>dp(n);
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                int prev = i - dp[i - 1] - 1;
                if (prev >= 0 && s[prev] == '(')
                    dp[i] = dp[i - 1] + 2 + (prev > 0 ? dp[prev - 1] : 0);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
#include<stack>
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int>st;//ջ�д��±�,������㳤��
        int ret = 0;
        st.push(-1);//����ֱ�Ӽ�
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                    st.push(i);//����ֱ�Ӽ�
                else
                    ret = max(ret, i - st.top());//����ֱ�Ӽ�
            }
        }
        return ret;
    }
};