
// https://leetcode.cn/problems/house-robber-ii/submissions/455290787/
//��ҽ���II

//��Ϊ�ǻ�������,����0λ������ѡ���ǲ�ѡ
//[0]λ�����ֲ�ѡ,��ô���β�������,������[1,n-1]������в�������������ۼӺ���� (��ҽ���I)
//[0]λ������ѡ��,��ô[1],[n-1]λ�ò���ѡ,��[2,n-2]������д�ҽ���I����
//�������ֵ����
//�����ǲ�������״̬��¼�ķ�ʽ���
#include<iostream>
#include<vector>
using namespace std;
class Solution31
{
public:
	int rob(vector<int>& nums)
	{
		int n = nums.size();
		return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
	}
	int rob1(vector<int>& nums, int left, int right)
	{
		if (left > right)return 0;//û�з���û����
		int n = nums.size();
		//dp[i]��������ĳ������֮���Ǯ��
		vector<int>f(n);//͵
		vector<int>g(n);//��͵
		f[left] = nums[left], g[left] = 0;
		for (int i = left; i <= right; i++)
		{
			f[i] = g[i - 1] + nums[i];
			g[i] = max(f[i - 1], g[i - 1]);
		}
		return max(f[right], g[right]);
	}
};

class Solution32
{
public:
	int rob(vector<int>& nums)
	{
		int n = nums.size();
		if (n == 1)
			return nums[0];
		return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
	}
	int rob1(vector<int>& nums, int l, int r)
	{
		if (l > r)
			return 0;
		if (l == r)
			return nums[l];
		if (l + 1 == r)
			return max(nums[l], nums[r]);

		int pprev = nums[l];
		int prev = max(nums[l], nums[l + 1]);
		for (int i = l + 2; i <= r; i++)
		{
			int cur = max(pprev + nums[i], prev);
			pprev = prev;
			prev = cur;
		}
		return prev;
	}
};