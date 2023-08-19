#include<iostream>
#include<vector>
using namespace std;

class BSFind
{
public:
	//���������Ҿֲ���Сֵ����
	int FindOneLessVal(vector<int>& arr)
	{
		int n = arr.size();
		if (n == 0)return -1;
		if (n==1 || arr[0] < arr[1])
			return arr[0];
		if (arr[n - 1] < arr[n - 2])
			return arr[n - 1];
		int left = 1,right=n-2;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
				return mid;
			else if (arr[mid] > arr[mid + 1])
				left = mid + 1;
			else if(arr[mid] > arr[mid - 1])
				right = mid - 1;
		}
		return left;
	}
	//���鷭ת,����С����n���۵�������,�����Ϊ��������,�ҵ���Сֵ�±�
	// ��ת������������Сֵ
	//�ֵ��Ұ�����,ѡȡ���������Ϊ�����������仹��������ı�־.< >=
	int FindLeastVal(vector<int>& arr)
	{
		int n = arr.size();
		if (n == 0)return -1;
		int left = 0, right = n - 1;
		int x = arr[right];//ѡȡ���������Ϊ�����������仹��������ı�־
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] > x)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
	//������ֲ���
	bool BSExist(vector<int>& arr, int x)
	{
		int left = 0, right = arr.size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] > x)
				right = mid - 1;
			else if (arr[mid] < x)
				left = mid + 1;
			else
				return true;
		}
		return false;
	}
	//�ҵ��������������ߵ��±�,�������Ǹ�ֵ�����䵽���Ұ����� < >= 
	//����left��right��ָͬ���Ǹ�λ��
	int BSFindLeftEdge(vector<int>& arr, int x)
	{
		int left = 0, right = arr.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;//ż����ʱȡ����ߵ��Ǹ�
			if (arr[mid] > x)
				left = mid + 1;
			else right = mid;
		}
		return left;
	}
	//��������������������λ�� < >= 
	int FindInsertPos(vector<int>& arr, int x)
	{
		int left = 0, right = arr.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;//ż����ʱȡ����ߵ��Ǹ�
			if (arr[mid] > x)
				left = mid + 1;
			else right = mid;
		}
		if (arr[left] < x) return right + 1;
		return left;
	}

	//�ҵ�������������ұߵ��±�,�������Ǹ�ֵ�����䵽��������� <= > 
	//����left��right��ָͬ���Ǹ�λ��
	int BSFindRightEdge(vector<int>& arr, int x)
	{
		int left = 0, right = arr.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left+1) / 2;//ż����ʱȡ���ұߵ��Ǹ�
			if (arr[mid] < x)
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
	//x��ƽ����,����ȡ��, <= >
	int mySqrt(int x)
	{
		if (x < 1)return 0;
		int left = 1, right = x;
		while (left < right)
		{
			long long mid = left + (right - left+1) / 2;
			if (mid * mid < x)
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}

	//���ҷ�ֵ����,һ����������֮������½�,����������������
	//arr[mid]>arr[mid+1]�Ұ����� arr[mid]<arr[mid+1]������� mid+1�����Ƿ���ֵ,���Է�Ϊ <= >
	//arr[mid]>arr[mid-1]�Ұ����� arr[mid]<arr[mid-1]������� mid-1�����Ƿ���ֵ,���Է�Ϊ < >=
	int findTopIndex(vector<int>& arr)
	{
		int n = arr.size();
		if (n < 0)return -1;
		int left = 0, right = n - 1;
		while (left < right)
		{
			int mid = left + (right - left+1) / 2;
			if (arr[mid + 1] > arr[mid])
				left = mid;
			else 
				right = mid - 1;
		}
		return left;
	}
};