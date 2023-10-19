//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
//̰��: �϶��ڹ�Ʊ�����Ľ׶�������Ʊ,����͵�����,����ߵ�����
//�ⷨһ:
// ����˫ָ��ķ�ʽ,�ֱ��¼��͵����ߵ㼴��.
//�ⷨ��:
//�������ǽ�����: ָ���Ž��������һ����,pn-p1=p2-p1 + p3-p2 + ... + pn-pn-1
//�൱��������������ÿ�춼�ڽ���
//�����½�����:ֱ�Ӳ���Ҳ����,�����벻���Ǯ
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int maxProfit1(vector<int>& prices)
    {
        int ret = 0;
        int n = prices.size();
        for (int i = 0; i < n;i++ )
        {
            int j = i;
            while (j + 1 < n && prices[j + 1] > prices[j])
                j++;
            ret += prices[j] - prices[i];
            i = j;
        }
        return ret;
    }
    int maxProfit2(vector<int>& prices) 
    {
        int ret = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                ret += prices[i] - prices[i - 1];
            }
        }
        return ret;
    }
};