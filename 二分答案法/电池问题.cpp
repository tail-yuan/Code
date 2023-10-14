//https://leetcode.cn/problems/maximum-running-time-of-n-computers/description/
// �뷵��n̨����ͬʱ���е��������
//https://www.bilibili.com/video/BV1Mh4y1P7qE?t=5804.8
//�ؼ�����:
// ������ص�������,�������ж�����Ƭ���ʱ,��������ۼӺ�>=��������*Ҫ��ʱ��ʱ,һ���ܹ���ɹ���
//��Ƭ���: ��صĵ���<Ҫ��ʱ��
//����������д���Ҫ��ʱ��ĵ����ĵ��,����ķ�ʽ����������һ����һ̨���Լ���.
//
//N̨���Թ�ͬ���еķ��������з�Χ��,[0,��������ۼӺ�]��ֻ��һ̨����ʱ,���е�ض���������
//������: Ҫ���ʱ��Խ��,��ô��Ҫ�ĵ��Ҳ��Խ��
//func����,�ṩ��Ҫ��ʱ��midʱ,���Ƿ��ܹ������е�������


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution11
{
public:
	//O(n*log(sum))
	long long maxRunTime(int n, vector<int>& nums)
	{
		long long sum = 0;
		for (int x : nums)
			sum += x;
		long long l = 0, r = sum;
		long long ans = 0;
		while (l <= r)
		{
			long long  mid = l + ((r - l) >> 1);
			if (func(mid, n, nums))
			{
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		return ans;
	}
	bool func(long long limit, int n, vector<int>& nums)
	{
		long long sum = 0;//��Ƭ��ص������ܺ�
		for (int x : nums)
		{
			if (x > limit)
				n--;
			else
				sum += x;
			if (sum >= limit * n)
				return true;
		}
		return false;
	}
};

//https://www.bilibili.com/video/BV1Mh4y1P7qE?t=6538.0
// ̰���Ż�: beat 100%
			// ���е�ص���������max
			// �����ʱsum > (long) max * num��
			// ˵�� : ���յĹ���ʱ��һ���� >= max����������յĹ���ʱ�� >= max
			// ˵�� : �������յĴ�X��˵�����е�ض��ǽ���"��Ƭƴ��"�ĸ���
			// ��ôѰ�� ? * num <= sum ������У�������� ? ����
			// ��sum / num
//����,���е��ԵĹ���ʱ��һ��<max,ʱ�䷶Χ�Ϳ��Խ�һ����С,[0,max],���е��������;Ϳ�����СΪint
//�����longlong����Ч��

class Solution
{
public:
	//O(n*log(sum))
	long long maxRunTime(int n, vector<int>& nums)
	{
		long long sum = 0;
		int maxVal = 0;
		for (int x : nums)
		{
			sum += x;
			maxVal = max(maxVal, x);
		}
		if (sum > (long long )maxVal * n)
			return sum / n;
		int l = 0, r = maxVal;
		int ans = 0;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (func(mid, n, nums))
			{
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		return ans;
	}
	bool func(int limit, int n, vector<int>& nums)
	{
		long long  sum = 0;//��Ƭ��ص������ܺ�
		for (int x : nums)
		{
			if (x > limit)
				n--;
			else
				sum += x;
			if (sum >= (long long)limit * n)
				return true;
		}
		return false;
	}
};
