#include<iostream>
#include<vector>
using namespace std;

class Sort
{
public:
	//������
	//��:������ռ�ģ�����ȫ�������ṹ
	//����Ƕ�������,���ݴ���O(logN),������O(N),������O(nlogn),��̯��ÿ�������O(logn)
	void HeapSort(vector<int>& arr)
	{
		if (arr.size() < 2)return;
		//�������
		for (int i = 0; i < arr.size(); i++)
		{
			HeapInsert(arr,i);//O(logN)
		}
		//���ж���
		int sz = arr.size();
		swap(arr[0],arr[sz-1]);
		while (sz>0)//O(N)
		{
			HeapIfy(arr,0,sz);//O(logN)
			swap(arr[0], arr[--sz]);
		}
	}
	//��index��λ�ò���x֮��,�����������ϵ���,�͸��׽ڵ�Ƚ�
	//Ĭ���Ǵ�ѵ���
	//����:�������������Ϊ�����,�����һ�����׽ڵ㿪ʼ���µ���heapIfy
	//��ײ�ռ����һ��,N/2,�޷������ٵ���,ֻ��һ��,������1
	//�����ڶ���N/4��,�������²���,��һ��,������2
	//�����ڶ���N/8��,�������²���2��,��һ��,������3
	//....
	//���帴�ӶȾ���T(N)=N/2*1+N/4*2+N/8*3....
	//��heapInsert��O(N*logN)=>O(N)
	void HeapInsert(vector<int>& arr, int index)
	{
		while (arr[index] > arr[(index - 1) / 2])
		{
			swap(arr[index], arr[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}
	//��indexλ�ÿ�ʼ���µ���,��ʱheap.size()=sz
	void HeapIfy(vector<int>& arr, int index, int sz)
	{
		int left = index * 2 + 1;
		while (left < sz)
		{
			int better = left;
			if (left + 1 < sz && arr[left + 1] > arr[left])
				better = left + 1;
			if (arr[better] < arr[index])
				break;
			else //if (arr[better] > arr[index])
			{
				swap(arr[better], arr[index]);
				index = better;
				left = index * 2 + 1;
			}
		}
	}
public:
	//T=O(nlogn)�ռ临�Ӷ�ΪO(logn)������ȡ������ʱ,��Ҫ�ǵݹ�ջ�еĿռ�ʹ��
	//version1-�ڿӷ�
	void QuickSort1(vector<int>& arr)
	{
		int n = arr.size();
		if (n < 2)return;
		return quick_sort(arr,0,n-1);
	}
	void quick_sort(vector<int>& arr, int l, int r)
	{
		if (l >= r)return;
		int key = partition1(arr, l, r);
		quick_sort(arr, l, key - 1);
		quick_sort(arr,  key+1,r);
	}
	int partition1(vector<int>& arr, int l, int r)
	{
		//����ȡ��,���⼫������ĳ���
		int key =l;
		while (l < r)
		{
			//����������һ��<key��ֵ
			while (l<r && arr[r]>arr[key])
				r--;
			while (l < r && arr[l] < arr[key])
				l++;
			swap(arr[l], arr[r]);
		}
		swap(arr[key], arr[l]);
		return l;
	}
	//version2-���仮��
	//����������������target������һ��ʱ,T=O(nlogn)�ƹ�,������1/3,1/4...,ÿһ�ָ��ʵ���������1/3p+(2/3(1-p))
	//����������֮������������O(nlogn)
	//���ѡ��һ���������һ������,���к����������⼴���仮��
	void QuickSort2(vector<int>& arr)
	{
		if (arr.size() < 2)
			return;
		quickSort(arr, 0, arr.size() - 1);
	}
	void quickSort(vector<int>& arr, int l, int r)
	{
		if (l >= r)return;
		int pos = rand() % (r-l+1);
		swap(arr[l + pos], arr[r]);
		pair<int, int>ret = partition(arr,l,r);
		quickSort(arr,l,ret.first-1);
		quickSort(arr,ret.second+1,r);
	}
	pair<int,int> partition(vector<int>& arr, int l, int r)
	{
		int less = l - 1, more = r + 1;
		while (l < more)//������more�����ֹͣ
		{
			if (arr[l] > arr[r])
			{
				swap(arr[more - 1], arr[l]);
				more--;
			}
			else if (arr[l] < arr[r])
			{
				swap(arr[less + 1], arr[l]);
				less++, l++;
			}
			else
				l++;
		}
		swap(arr[r],arr[more-1]);
		return {less+1,more-1};
	}
	//
	//master��ʽ��ʹ��
	void merageSort(vector<int>& arr)
	{
		if (arr.size() < 2)
			return;
		return merageSortHelper(arr, 0, arr.size() - 1);
	}
	//���ζ��ֵ���,a=2,b=2 log(b,a)=1,��������merage��O(N^1),d=1,����T(N)=O(N^d*logN)
	void merageSortHelper(vector<int>& arr, int left, int right)
	{
		if (left >= right)return;
		int mid = left + (right - left) + 1;
		merageSortHelper(arr, left, mid);
		merageSortHelper(arr, mid+1,right);
		merage(arr,left,mid,right);//����������������й鲢
	}
	void merage(vector<int>& arr, int left, int mid, int right)
	{
		vector<int>tmp(right-left+1);
		int p1 = left;
		int p2 = mid + 1;
		int i = 0;
		while (p1 <= mid && p2 <= right)
		{
			tmp[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
		}
		while (p1 <= mid)
			tmp[i++] = arr[p1++];
		while (p2 <= right)
			tmp[i++] = arr[p2++];
		//������ԭ����
		for (int i = left; i < tmp.size(); i++)
			arr[left + i] = tmp[i];
	}
public://<O(n^2),O(1)>
	//���ݷ����仯Ӱ������
	//����[0,i]��������,��i-1��ǰ�Һ��ʵ�λ�ò���
	void Insert(vector<int>& arr)
	{
		int n = arr.size();
		if (n < 2)return;
		for (int i = 1; i < n; i++)
		{
			for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
				swap(arr[j],arr[j+1]);
		}
	}
public://���ݷ����仯��Ӱ������

	//��iλ�ÿ�ʼ�����,����Ⱥ�һ������ͽ���
	//һ�ְ���һ�����ֵ,�����ұ߽�һֱ�����ƶ�
	void BubbleSort(vector<int>& arr)
	{
		int n = arr.size();
		if (n < 2)return;
		for (int i = n-1; i>=0; i--)//
		{
			for (int j = 0; j <i; j++)
			{
				if (arr[i] > arr[i + 1])
					swap(arr[i],arr[i+1]);
			}
		}
	}
	//��iλ�ÿ�ʼ�������С��������iλ��,i++
	//O(n^2)���ȶ�����
	void SelectSort(vector<int>& arr)
	{
		if (arr.size() < 2)
			return;
		for (int i = 0; i < arr.size(); i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < arr.size(); j++)
			{
				minIndex = arr[minIndex] > arr[j]?j:minIndex;
			}
			swap(arr[minIndex],arr[i]);
		}
	}
};