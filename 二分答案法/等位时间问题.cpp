//�����λʱ�����һ������arr����Ϊn����ʾn������Ա��arr[i]��ʾiλ�÷���Ա����һ���������ĵ�ʱ��
// ����һ������m����ʾ��m���˵�λ��
// ������Ǹ������ˣ�ÿ��������ѭ�п�λ���ϵ�ԭ����������Ҫ�ȶ�� ? 
//����mԶԶ����n������n <= 10^3��m <= 10^9������ô�������Ž� ? �ȸ������
//
//������: ������ôѡ����з���Ա,ֻҪ����ѭ�п�λ���ϵ�ԭ��,�����ŵ�ʱ�����ȷ����,ֻ���������ǲ�ͬ�ķ���Ա.
//�ⷨһ:ʹ��С����,<����Ա����ʱ��,����Ա����ʱ��>
//ÿ�ε���ջ��,�ۼӾ���ʱ��...
//һ����m��,ÿ����logn,����T=m*logn.��������10^9,��m�ܴ�ʱ�ͻᳬʱ

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution
{
public:
	class waiter
	{
	public:
		int ready;
		int cost;
		waiter(int r, int c)
			:ready(r)
			, cost(c)
		{}
	};
	struct greater
	{
		bool operator()(const waiter& w1, const waiter& w2)
		{
			return w1.ready > w2.ready;
		}
	};
	int waitTime(vector<int>& waiters, int m)
	{
		priority_queue<waiter, vector<waiter>, greater>heap;
		int n = waiters.size();
		for (int i = 0; i < n; i++)
			heap.push(waiter(0,waiters[i]));
		for (int i = 0; i < m; i++)
		{
			waiter top = heap.top();
			heap.pop();
			top.ready += top.cost;
			heap.push(top);
		}
		return heap.top().ready;
	}
};


//�ⷨ��:
//�ȴ�ʱ��ʱ�з�Χ��,[0,minWaiter*m],��ΪҲ֪����ѭ�п�λ���ϵ�ԭ��,
//�ṩfunc����,�涨����Ա��������midСʱ,�ܹ������ٿ����ṩ����
//��Ȼ����ʱ��Խ��,�ܹ��ṩ����Ҳ��Խ��,������.
//�Լ��ǵ�m+1���� 
class Solution
{
public:
	public:
	int waitTime(vector<int>& waiters, int m)
	{
		int minVal = INT_MAX;
		for (int i = 0; i < waiters.size(); i++)
			minVal = min(minVal, waiters[i]);
		int l = 0, r = minVal * m;
		int ans = 0;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (func(waiters, mid) >= m + 1)
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		return ans;
	}
	int func(vector<int>& nums, int time)
	{
		int ans = 0;
		for (int x : nums)
		{
			ans += (time/x) + 1;//����timeʱ�������ڷ�����û�����,Ҳ��!!
		}
		return ans;
	}
};