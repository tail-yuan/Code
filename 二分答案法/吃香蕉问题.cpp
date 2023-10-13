//�����㽶����,arr[index]��������㽶����
//�ڹ涨ʱ��time��,����ܹ��������㽶���������ÿ��СʱӦ�óԶ����㽶,
//Ҳ���ǽ����㽶���ٶ������.
//����: �����ٶ���v,���v>arr[index],����֮�󾡹���ʣ��,ѡ����Ϣ

//ȷ������ٶȵķ�Χ,[1,maxVal],maxVal���������㽶�����ֵ,һ��Сʱ��֤�ܳ���
//Ҳû�б�Ҫ���ٶ��Ǹ���ֵ��.
//������: �ٶ�Խ��,��ô���������㽶��ʱ��ͻ�ԽС
//��Ϊ�����ԵĴ���,���Զ��ֵ���С�����ų�������
//���ַ�ȷ���ٶ�,����ʱ���ٶ��ܷ��ڹ涨ʱ���ڶ�����
//��ô����Ҫʵ��f����,����������ٶ����Ƿ��ܹ���������㽶
//https://leetcode.cn/problems/koko-eating-bananas/
//T= O(N* log(max()))
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l = 1, r = 0;
        for (int x : piles)
            r = max(r, x);
        int ans = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (func(piles, m)<=h)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
    //���ݹ������ٶ���ʵ��������ȡ��a/b����ȡ��= (a+b-1)/b
    long func(vector<int>& piles, int m)
    {
        long ans = 0;
        for (int x : piles)
        {
            ans += (x + m - 1) / m;
        }
        return ans;
    }
};