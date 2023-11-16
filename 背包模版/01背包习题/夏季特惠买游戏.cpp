//https://leetcode.cn/problems/tJau2o/description/
//costs[i]=ai-bi
//vals[i]=wi
//��������Ϸ��Ǯ���Գ���Ԥ��,ֻ��Ҫ���Żݼ۸񲻵��ڳ���Ԥ����ܽ��
//Ҳ����ÿÿ����Ҫ��һ����Ϸʱ,i����Ϸ,costs[i] > bi����
//ͨ����һ����ɸѡ������Ҫѡ�����Ϸ,��Ϊ���������Ϸ�����ǻ��кô�,�����������и�����Ż�
//��������Ϸ,���Ա���.
//Ȼ������ʣ�µ���Ϸ��ѡ��������Ϸ��,ֱ������������.
//��ôʣ�µ���Ϸ���Եõ��µ�����nums[],�õ���Ӧ��costs[i]��happys[i]
//�������������н���01������������ۼ���
//��������ܹ���õ����Ŀ���ֵ

//dp[i][j]��ʾ��1~i����Ʒ��ѡ��,Ԥ�㲻����jʱ�ܹ���õ�������ֵ
//i~[1,k]��Ϊֻ��Ҫ�ڲ���ֱ��ѡ�����Ϸ��ѡ��,֮ǰ��¼��һ����k��
//j~[1,x]��Ϊ����ѡ�����Ϸ����Ҵ��������Ԥ��,x������ʱ�仯��,��¼֮����x

#include<iostream>
#include<vector>
using namespace std;
long long compute(vector<long long>& costs, vector<long long>& vals, int k, int x)
{
	vector<long long>dp(x + 1);
	for (int i = 1; i < k; i++)//ע��k���ﲢ����<=������01����һ��.����Լ����costs[k]λ�������Ԫ��,����Ԫ��ֻ��k-1��
	{
		for (int j = x; j >= costs[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - costs[i]] + vals[i]);
		}
	}
	return dp[x];
}

int main()
{
	int n = 0, x = 0;
	while (cin >> n >> x)
	{
		vector<long long >costs(n + 1);
		vector<long long >happys(n + 1);
		long long  ans = 0;
		int k = 1;//��¼һ���ж��ٸ����Ǳ���ѡ�����Ϸ
		long long happy = 0;
		for (int i = 1, a = 0, b = 0; i <= n; i++)//��֤�±�����01������1��ʼ
		{
			cin >> a >> b >> happy;
			int well = a - b - b;
			if (well >= 0)
			{
				x += well;
				ans += happy;
			}
			else//ֻ�в��Ǳ���ѡ��,�ŷŵ�������Ѱ��һ����ѵ�ѡ��,�õ�������֮�ڵ�������ֵ
			{
				costs[k] = -well;
				happys[k++] = happy;
			}
		}

		ans += compute(costs, happys, k, x);
		cout << ans << endl;
	}
}
