//https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71
// ����� �������ڱ��Ϊ0�Ľ�������
// ÿһ������������һ�����ұߣ�����������������ڵ�k���������������ڵ�����ֵ��E, ��һ�����������ڸ�k+1������
// ������õ�����ʧȥ��������H(k+1)��E֮���������
// ��� H(k+1) > E ��ô�����˾�ʧȥ H(k+1) - E ������ֵ�����������õ� E - H(k+1) ������ֵ��
// ��Ϊ���ڻ�ȡ����,���Կ�����ӵĹ����е�������Խ��,������maxʱ�Ϳ϶��������,ֱ�ӷ��ؼ���,ʵ�ּ�֦
//������Ҫ��������̨��,��ʼ��������Ӧ���Ƕ���?
//������: �϶��ǳ�ʼ����Խ��,�ܹ��ߵ�̨�������϶�����
//������Χ:[0,maxVal]̨�׸߶����ֵ
//�ṩfunc�����ж���m��ʼ�������ܷ񵽴����յ�̨��?

#include <iostream>
#include<vector>
using namespace std;
bool func(vector<int>& arr, int m, int maxVal)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (m <= arr[i])
			m -= arr[i] - m;
		else
			m += m - arr[i];
		if (m >= maxVal)
			return true;
		if (m < 0)
			return false;
	}
	return true;
}
int compute(vector<int>& arr)
{
	int l = 0, r = 0;
	for (int x : arr)
		r = max(x, r);
	int maxVal = r;
	int ans = -1;
	while (l <= r)
	{
		int m = l + ((r - l) / 2);
		if (func(arr, m, maxVal))
		{
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}

int main() 
{
	int n = 0;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int ret = compute(arr);
	printf("%d\n", ret);
	return 0;
}
