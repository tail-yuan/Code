//ʹ�ö��ִ𰸷�,��Χ��[1,n*min(a,b)]֮��.
//���a<b,ֻ����aʱ,��ô��n����������־���n*a,����b�ļ���ʱ,��[1,n*a]�������л��и����
//���������,��ô����ζ�ŵ�n�����ֵ��������С.
//��������к���func(k)��������[1,k]��һ���ж��ٸ����������,
//���ret < n,˵�����kȡ�Ĳ���,k=mid+1,���ret>= n,˵��ȡ�Ŀ�����,k=mid
//��ôfunc�������ʵ��?
// �����ݳ�ԭ��:
//1~k���ж��ٸ����������,k/a + k/b - k/lcm(a,b)��С������

/// https://leetcode.cn/problems/nth-magical-number/submissions/
#include<iostream>
using namespace std;

class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        long long ret = lcm(a, b);
        long long ans = 0;
        for (long long l = 0, r = (long long)n * min(a, b), m = 0; l <= r;)
        {
            m = l+(r-l)/ 2;
            if ((m / a) + (m / b) - (m / ret) >= n)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return (int)(ans % 1000000007);
    }
    //������Լ��,a>bʱ,ʱ�临�Ӷ���O(log(a)^3),���Ӷ��㹻��.
    //ŷ������㷨: շת�����
    long long gcd(long long a, long long b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    //�����С������
    long long lcm(long long a, long long b)
    {
        return (long long)a / gcd(a, b) * b;
    }
};