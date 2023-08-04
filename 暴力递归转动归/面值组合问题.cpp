#include<iostream>
#include<vector>
using namespace std;

class Coins1 // ÿһ����ֵ��Ǯ��������,ֻҪ�����aimֵ�ľ���,�ж���������ܹ����aim
{
public:
	int minMoney(vector<int>& arr, int aim)
	{
		return process(arr,0,aim);
	}
	//�ж����ַ�����!
	int process(vector<int>& arr, int index, int rest)
	{
		if (index == arr.size()) 
			return rest == 0?1:0;
		int ways = 0;
		//��Ȼ��һ����ֵ�Ŀ����ظ�ʹ��,��ô�����Ҫ������һ���ȼ� ����* ��ֵ<=aim 
		for (int count = 0;count* arr[index] <= rest ; count++)
			//��һ����ֵ����1��,������
			//��һ����ֵ����2��,������
			//��һ����ֵ����3��,������,ֱ����һ����ֵ���������ֵ
		{
			ways += process(arr,index+1,rest - count*arr[index]);
		}
		return ways;
	}
};

//������������
class Coins2 // ÿһ����ֵ��Ǯ��������,ֻҪ�����aimֵ�ľ���
{
public:
	int getMin(vector<int>& arr, int aim)
	{
		return process(arr,aim);
	}
	//������������
	int process(vector<int>& arr, int rest)
	{
		if (rest < 0) return -1;
		if (rest == 0)return 0;
		//rest>0
		int minCount = INT_MAX;
		for (int i = 0; i < arr.size(); i++)
		{
			int count = process(arr, rest - arr[i]);
			if (count != -1)
				minCount = min(minCount, count + 1);
		}
		return minCount;

	}
};
//û��������,ֻ��һ��,�������������Ӳ������ƴ��aimm
class Coin3
{
public:
	int getMin(vector<int>& arr, int aim)
	{
		return process(arr,0, aim);
	}
	int process(vector<int>& arr, int index, int rest)
	{
		if (rest == 0)return 0;
		if (rest < 0)return -1;
		if (index == arr.size())
			return -1;
		int p1 = process(arr,index+1,rest-arr[index]);
		int p2 = process(arr,index+1,rest);
		if (p1 == -1 && p2 == -1) return -1;
		else
		{
			if (p1 == -1)
				return p2;
			else if (p2 == -1)
				return p1 + 1;
			else
				return min(p1+1,p2);
		}
	}
};