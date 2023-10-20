#include<iostream>
#include<vector>
using namespace std;

//https://leetcode.cn/problems/guess-number-higher-or-lower-ii/
class Solution1
{
public:
    //˼·: ���Ե�ѡ��,�����в��Ե���໨����ѡ����С���Ǹ�����.����:����ѡ��һ����Ϊ��ʼ,���ݴ�С��ʾ,��Ϊ��������,��������ѡ
    //      ������Ҫ������С�ֽ���,������С���Ҵ������Բ�һ���Ƕ��ֲ���.����Ҫ��һ�鱩��
    //dfs������,������: 1.1 �� 1~n ������ѡ��һ����i��Ϊ���ڵ�,��֪��С֮��,���ڷֳ������ǲ�����ѡ��һ������Ϊ�ڵ�.
    //      ����ʤ������С���ۿ�������������Ϊͷ�Ĳ���; ������������ѡ��ϴ������Ϊ��iΪ�ڵ�ķ���ֵ.
    //      ��֤�����������ܹ����.
    //      1.2 ÿ�ε�һ���ڵ�,����Ҫ�ڸ���������ѡ��һ����Ϊ��ʱ�Ľڵ�,Ȼ��������dfs�ܹ���������������С��������,
    //          ����ѡ������нϴ�ļ����Ҿ��Ǳ�֤ʤ��������,
    //dfs�ķ���ֵ: ��1~n �����ڵ���С����,������������iΪͷѡ�еĲ��Է������ٴ���֮��,����Ҫ��¼���в��Ե���С����
    int getMoneyAmount(int n)
    {
        int ret = dfs(1, n);
        return ret;
    }
    int dfs(int left, int right)
    {
        if (left >= right)//˵������Ҷ�ӽ��,ֱ�Ӳ³�������,���Բ���Ҫ֧��Ǯ
            return 0;

        int ret = INT_MAX;
        for (int i = left; i <= right; i++)
        {
            //1~i-1, i+1 right
            int x = dfs(left, i - 1);
            int y = dfs(i + 1, right);
            int minCost = i + max(x, y);

            ret = min(ret, minCost);
        }
        return ret;
    }
};

//��1~n֮��ѡ��ĳһ���ڵ�Ϊͷ�д������ظ�����,���Կ��Ը�Ϊ���仯����
//��Ϊ�������ɱ����,����ʹ�ö�ά��
class Solution2
{
    int memo[202][202];
public:
    int getMoneyAmount(int n)
    {
        int ret = dfs(1, n);
        return ret;
    }
    int dfs(int left, int right)
    {
        if (memo[left][right] != 0)
            return memo[left][right];

        if (left >= right)//˵������Ҷ�ӽ��,ֱ�Ӳ³�������,���Բ���Ҫ֧��Ǯ
        {
            memo[left][right] = 0;
            return memo[left][right];
        }

        int ret = INT_MAX;
        for (int i = left; i <= right; i++)
        {
            //1~i-1, i+1 right
            int x = dfs(left, i - 1);
            int y = dfs(i + 1, right);
            ret = min(ret, i + max(x, y));
        }
        memo[left][right] = ret;
        return memo[left][right];
    }
};