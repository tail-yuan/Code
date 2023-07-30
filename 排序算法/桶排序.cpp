#include<iostream>
#include<vector>
using namespace std;

//�����ڱȽϵ�����=>Ͱ����
//��������
class BucketSort
{
public:
	int radix = 10;//�����ƾͷּ���Ͱ
	//��������
	void radixSort(vector<int>& arr)
	{
		if (arr.size() == 0)return;
		radixSortHelper(arr,0,arr.size()-1,getMaxDigit(arr));
	}
	void radixSortHelper(vector<int>& arr, int begin, int end, int digit)
	{
		//���λ��������Ҫ��Ͱ����Ͱ����
		//��Ͱģ��:ʹ��count[i]�����λ(ʮλ...)<=i�������м���
		//��Ͱģ��:����count[i]->ʹ��helper����˷Ű��ո�λ(ʮλ...)����ŵ�����
		for (int d = 1; d <= 10; d++)
		{
			vector<int>count(radix);
			for (int i = begin; i <= end; i++)
			{
				int j = getSingleDigit(arr[i], d);
				count[j]++;
			}
			//����ǰ׺��->�����λС�ڵ���i���м�������
			for (int i = 1; i < radix; i++)
				count[i] += count[i - 1];

			//��Ͱ->helper������
			vector<int>bucket(end-begin+1);
			for (int i = end; i >= begin; i--)
			{
				int j = getSingleDigit(arr[i],d);
				bucket[count[i] - 1] = arr[i];
				count[i]--;
			}
			//helper->arr
			for (int i = begin, j = 0; i <= end; i++, j++)
			{
				arr[i] = bucket[j];
			}
		}
	}
	int getSingleDigit(int num, int digit)//��ȡ����numĳһλ������,����:d=1->��Ҫ��λ��
	{
		return (num / (int)(pow(10, digit - 1))) % 10;
		// 123456 ����Ҫ5,��ʱԼ���õ�digit=2,123456 /10=12345 ,%10=5 
	}
	int getMaxDigit(vector<int>& arr)
	{
		//�ҵ����ֵ�����λ��
		int maxSum = 0;
		for (auto e : arr)
			maxSum = max(maxSum,e);
		int digit = 0;
		while (maxSum)
		{
			digit++;
			maxSum /= 10;
		}
		return digit;
	}

public:
	//��������
	void CountSort(vector<int>& arr)
	{
		if (arr.size() == 0)return;
		//1. �ҵ����ֵȻ�󿪿ռ�
		int maxSum = INT_MIN;
		for (int i = 0; i < arr.size(); i++)
			maxSum = max(maxSum,arr[i]);
		vector<int>count(maxSum+1);
		//2. ����,ͳ�ƴ�Ƶ
		for (int i = 0; i < arr.size(); i++)
			count[arr[i]]++;
		//3. ���
		int i = 0;
		for (int j = 0; j < count.size(); j++)
		{
			while (count[j]--)
				arr[i++] = count[j];
		}
	}
};