//https://leetcode.cn/problems/ugly-number-ii/
//����: Ĭ�ϵ�һ��������1,��������ֻ�ܰ���������2 3 5��ɵ���
//�뷵�ص�n������

//����: ����1~n������һ������֤�Ĺ���,�Ż�Ϊд����һ��������˭�Ĺ���
//��֪����1,��ѡ��һ��������1*2=2,1*3=3,1*5=5,ѡ�����cur���Ǹ�,������һ��������2
// ...
//https://www.bilibili.com/video/BV1Ww41167Ac?t=8383.9 
//ѡ������ָ��,�ֱ����*2,*3,*5,��ʼ��ָ���1������
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        vector<int>dp(n + 1);
        dp[1] = 1;
        for (int i = 2, i2 = 1, i3 = 1, i5 = 1, cur = 0; i <= n; i++)
        {
            int a = dp[i2] * 2;
            int b = dp[i3] * 3;
            int c = dp[i5] * 5;
            cur = min(a, min(b, c));
            if (cur == a)
                i2++;
            if (cur == b)
                i3++;
            if (cur == c)
                i5++;
            dp[i] = cur;
        }
        return dp[n];
    }
};