//https://leetcode.cn/problems/minimum-cost-for-tickets/description/

#include<iostream>
#include<vector>
using namespace std;

//�����ҳ���ģ��,���־�����ѡ����С����
//�Ӷ�����,������
//T = O(30*N),i����N������,ÿ��������func��������Ҫ����3�ξ���,ÿ�ξ�������Ҫ����Ѱ��ʧЧʱ��j
//������Ծ��������30��,���Ҳ����30������
//ÿ��i����Ҫ����һ��,������O(30*N)
class Solution1
{
    vector<int>durations;//����ʱ��
public:
    //duration��k�±�Ʊ�ĳ���ʱ��,cost��k�±�Ʊ�Ļ���
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        durations = vector<int>{1,7,30};
        return func(days, costs, 0);
    }
    //���days[i...]֮����Ҫ�����ٻ����Ƕ���
    int func(vector<int>& days, vector<int>& costs,int i)
    {
        if (i == days.size())
            return 0;
        int ans = INT_MAX;
        for (int k = 0; k < 3; k++)
        {
            int j = i;//j�������ƱʧЧ����һ��
            while (j<days.size() && days[i] + durations[k] > days[j])
                j++;
            ans = min(ans, costs[k] + func(days, costs, j));
        }
        return ans;
    }
};
//func(i)���ڴ������ظ�����,[0,i-1]�����в�ͬ��ѡ�����,����iλ�ö���Ҫ������С���ļ���
//���Կ�������Ϊ���仯����
//�ڴ������µ�ģ����ͨ����ļ�¼����Ч��
class Solution2
{
    vector<int>duration;
    vector<int>memo;
    int n;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        duration = vector<int>{ 1,7,30 };
        n = days.size();
        memo= vector<int>(n,-1);
        return func(days, costs, 0);
    }
    int func(vector<int>& days, vector<int>& costs, int i)
    {
        if (i == n)
            return 0;
        if (memo[i] != -1)
            return memo[i];
        int ans = INT_MAX;
        for (int k = 0; k < 3; k++)
        {
            int j = i;
            while (j<n && days[i] + duration[k] > days[j])
                j++;
            ans = min(ans, costs[k] + func(days, costs, j));
        }
        memo[i] = ans;
        return ans;
    }
};

//�ϸ�λ�������Ĵӵ׵����Ķ�̬�滮
//����λ������,Ҫ�ó�days[0....]����Ҫ��֪��days[4...],
//�ı�˳��,���ݹ��Ϊ��̬�滮
//ֻ��һ���ɱ����,i,��Χ��0,n-1,���Կ���n���ռ�͹�
//��ʼ��: dp[n]=0;
//���˳��: ��Ϊ����������Ҳ�,�������Һ���,���������˳��

class Solution3
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int>duration{ 1,7,30 };
        int n = days.size();
        const int inf = 0x3f3f3f3f;
        vector<int>dp(n + 1, inf);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int k = 0, j = i; k < 3; k++)
            {
                while (j<n && days[i] + duration[k] > days[j])
                    j++;
                dp[i] = min(dp[i], costs[k] + dp[j]);
            }
        }
        return dp[0];
    }
};