#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/submissions/475455191/
//������ʽ������forѭ��,�ֱ�ö��������������
//ö��indexλ��Ϊ������λ��,��Ҫ�ҳ�[0,index-1]�����е���Сֵ.
//����ʹ�ñ������ű����Ĺ��̼�¼�����е���Сֵ
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int ret = 0;
        int preMin = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            ret = max(ret, prices[i] - preMin);
            preMin = min(preMin, prices[i]);
        }
        return ret; 
    }
};