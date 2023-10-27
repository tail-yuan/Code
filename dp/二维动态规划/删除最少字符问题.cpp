// ɾ�����ټ����ַ����Ա����һ���ַ������Ӵ�
// ���������ַ���s1��s2
// ����s1����ɾ�������ַ����Գ�Ϊs2���Ӵ�
//https://www.bilibili.com/video/BV1cg4y1o719?t=4921.2
//dp[i][j]��ʾs1ǰi���ַ������s2ǰj�����ַ��������׺��,��Ҫɾ���ĸ���
// S1[0...i-1] s2[0...j-1],s1�ĵ�i���ַ���s2�ĵ�j���ַ�,
// 1. s1[i-1]!=s2[j-1], dp[i][j]=dp[i-1][j] +1 ��iλ��ɾ��һ��
// 2. s1[i-1]==s2[j-1], dp[i][j]=dp[i-1][j-1]
//����ֵѡ�����һ������Сɾ����������
#include<iostream>
#include<vector>
using namespace std;
class Solution36
{
public:
	int minDel(string& s1, string& s2)
	{
		int n = s1.size(), m = s2.size();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++)
			dp[i][0] = i;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = dp[i - 1][j] + 1;
				}
			}
		}
		int ans = INT_MAX;
		for (int i = 0; i <= m; i++)
			ans = min(ans, dp[n][i]);
		return ans;
	}
};