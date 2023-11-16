#include<iostream>
#include<vector>
using namespace std;

//dp[i][j]��ʾ��[1,i]����Ʒ����ѡ,�����������jʱ�ܹ���õ�����ֵ��dp[n][v]
//��i��λ��Ϊ��β��������,
//1. ��ѡ��i����Ʒ,dp[i][j]=dp[i-1][j] 2. ѡ��i����Ʒ,dp[i][j]=dp[i-1][j-costs[i]]+vals[i]
//dp(n+1,vector<int>(v+1));
// ��ʼ��: i=0,Ҳ���ǵ�0��,����û����Ʒ����ѡ��ʱ,���������jʱ�ܹ���ȡ�����������Ȼ��0
//       j=0,�ڵ�0��,����ѡ��[1...i]��Ʒ,�������������0ʱ,�ܹ���ȡ�����������Ȼ�ǲ�ѡ,Ϊ0
//costs�����Ӧ��Ҳ������[1,i]λ�õĴ���,[0]λ�ò��Ŷ���,���Բ���ע�����ԭ����ʱ�±�-1����

//�ռ�ѹ��,��Ϊ��Ҫ������һ������ֵ,����Ϊ�˸���ʱ���⸲��,���Խ�˳���Ϊ�����������

class Solution
{
public:
	int getMaxVal(int n,int limitV,vector<int>& costs, vector<int>& vals)
	{
		vector<vector<int>>dp(n + 1, vector<int>(limitV + 1));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= limitV; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= costs[i])
					dp[i][j] = max(dp[i][j], dp[i - 1][j - costs[i]] + vals[i]);
			}
		}
		return dp[n][limitV];
	}
	int getMaxVal1(int n, int limitV, vector<int>& costs, vector<int>& vals)
	{
		vector<int>dp(limitV);
		for (int i = 1; i <= n; i++)
		{
			//��j<costs[i]ʱ����ڶ������������,���ø���,Ҳ����ֱ�ӵ�����һ�е�ֵ����
			//��һ�е�ֵ���Ǵ�ʱ��dp[j],�����¼���
			for (int j = limitV; j >= costs[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - costs[i]] + vals[i]);
			}
		}
		return dp[limitV];
	}
};