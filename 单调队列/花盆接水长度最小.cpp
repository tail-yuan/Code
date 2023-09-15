
//ÿ��ˮ��ÿ��1��λ������,
//����N��ˮ�������������ĸ߶� (x,y)
//��: ��Ҫ���䵽�����е�ˮ��,��������ʱ����ΪDʱ,�������С���䳤���Ƕ���
//https://www.luogu.com.cn/record/124757479

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
	static const int N = 100005;
	int maxQueue[N] = { 0 };
	int minQueue[N] = { 0 };
	int minh, mint, maxh, maxt;
	vector<vector<int>>nums;
private:
	struct compare
	{
		bool operator()(vector<int>& x, vector<int>& y)
		{
			if (x[0] < y[0])
				return true;
			else
				return false;
		}
	};
public:
	int minLenFallingWater(vector<vector<int>>& arr,int d)
	{
		const int MAX = 0x3f3f3f3f;
		minh = mint = maxh = maxt = 0;
		//�����±�x��������������,�źý��к���
		sort(arr.begin(),arr.end(),compare());
		//һ������jb����֮��,�ٽ���ȫ������nums,Ҫ��Ȼ�߼�������!!!!
		nums = arr;
		int n = nums.size();
		int ans = MAX;
		for (int l = 0, r = 0; l < n; l++)
		{
			while (!ok(d) && r < n)
				push(r++);
			if (ok(d))
				ans = min(ans, arr[r - 1][0] - arr[l][0]);//x�������
			pop(l);
		}
		nums.clear();
		Clear();
		//ע�ⷵ��ֵ����,��������������ж�!!!!!
		return ans==MAX?-1:ans;
	}
	void Clear()
	{
		for (int i = 0; i < N; i++)
		{
			minQueue[i] = 0;
			maxQueue[i] = 0;
		}
	}
	bool ok(int d)
	{
		int max_val = maxh < maxt ? nums[maxQueue[maxh]][1] : 0;
		int min_val = minh < mint ? nums[minQueue[minh]][1] : 0;
		return (max_val - min_val) >= d;
	}
	void push(int r)
	{
		while (maxh < maxt && nums[maxQueue[maxt - 1]][1] <= nums[r][1])
			maxt--;
		maxQueue[maxt++] = r;
		while (minh < mint && nums[minQueue[mint - 1]][1] >= nums[r][1])
			mint--;
		minQueue[mint++] = r;
	}
	void pop(int l)
	{
		//�ĸ������������ƣ��ɱ�д��������������������������
		if (maxh < maxt && maxQueue[maxh] == l)
			maxh++;
		if (minh < mint && minQueue[minh] == l)
			minh++;
	}
};
int main()
{
	int n = 0, d = 0;//n��ˮ,ʱ����Ϊd
	cin >> n >> d;
	vector<vector<int>> arr(n, vector<int>(2));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];
	}
	Solution s;
	int ret =s.minLenFallingWater(arr,d);
	cout << ret<< endl;
	return 0;
}