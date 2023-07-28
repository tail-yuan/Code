#include<iostream>
#include<vector>
using namespace std;

//��������arr,��target,��arr����Ϊ������,< = >��������
class NetherLandFlag
{
public:
	pair<int, int>partion(vector<int>& arr, int l, int r, int p)
	{
		int less = l - 1, more = r + 1;
		while (l < more)
		{
			if (arr[l] < p)//��ֵ�ŵ�less������
			{
				swap(arr[less + 1], arr[l]);
				less++;
				l++;
			}
			else if (arr[l] > p)//��ֵ�ŵ�more������
			{
				swap(arr[more - 1], arr[l]);
				more--;
			}
			else
				l++;
		}
		return {less+1,more-1};
	}
};