#include<iostream>
#include<vector>
using namespace std;
//����Ժ���С�Ͷ���һ��˼��,�ڹ鲢�Ŀ�����ò�ͬ�ķ�ʽ�ռ����
class minSum
{
public:
	//���Ҳ�������x�����Լ������,��������������鲢ʱ�Ż����+,res+=x*i
	int getMinSum(vector<int>& arr)
	{
		if (arr.size() == 0)
			return;
		return merageSort(arr,0,arr.size()-1);
	}
	int merageSort(vector<int>& arr, int left, int right)
	{
		if (left >= right)return 0;
		int mid = left + (right - left) / 2;
		return merageSort(arr, left, mid) + merageSort(arr, mid + 1, right) + merage(arr,left,mid,right);
	}
	int merage(vector<int>& arr, int left, int mid, int right)
	{
		vector<int>tmp(right-left+1);
		int p1 = left, p2 = mid + 1;
		int res = 0;
		int i = 0;
		while (p1 <= mid && p2 <= right)
		{
			//�Ҳ���������ռ���ż����Ҵ�,��ôʣ�µĶ����Ҵ�,�Ҿ͵��ۼ���ô���
			res += arr[p1] > arr[p2] ? 0 : (right - p2 + 1) * arr[p1];
			tmp[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1]++;
		}
		while (p1 <= mid)
			tmp[i++] = arr[p1++];
		while (p2 <= right)
			tmp[i++] = arr[p2++];
		for (int i = 0; i < tmp.size(); i++)
			arr[left + i] = tmp[i];
	}
};