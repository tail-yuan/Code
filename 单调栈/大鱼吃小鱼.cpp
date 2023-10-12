
//��������: https://www.bilibili.com/video/BV1GH4y1D7TB?t=3245.9
//��Ϊֻ�ܳ��Ҳ���Լ�С����
//���Ӻ���ǰ����ʱ,����ջά��Сѹ��ĵ�����,
//top()һ�����������������,��ô����Ǵ�ѹС�Ļ�,Ϊʲô��ֱ�ӳԵ���?
//����ջ��¼������<���С,��������Լ���������ܹ���Ҫ������>
//��[index]>top()ʱ,������ԳԵ�,��ô����ջ��Ԫ��,������max([index]+1,top().����)
//�������: https://www.bilibili.com/video/BV1GH4y1D7TB?t=3504.8
//�������ֵʱ: https://www.bilibili.com/video/BV1GH4y1D7TB?t=3930.5
//ֱ�ӽ��벻�õ���,ֻ�е��ϸ�С��ʱ���ٵ���.

//https://www.nowcoder.com/practice/77199defc4b74b24b8ebf6244e1793de
#include<iostream>
#include<vector>
using namespace std;
int get_turns(vector<int>& arr)
{
	int n = arr.size();
	vector<vector<int>>st(n,vector<int>(2));//�����������<arr[i],turns>
	int r = 0;
	int ans = 0;
	int curTurns = 0;
	for (int i = n-1; i>=0; i--)
	{
		curTurns = 0;
		while (r > 0 && arr[i] > st[r - 1][0])
		{
			curTurns = max(curTurns + 1, st[--r][1]);
		}
		st[r][0] = arr[i];
		st[r++][1] = curTurns;
		ans = max(ans, curTurns);
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
	int ret = get_turns(arr);
	printf("%d\n", ret);
	return 0;
}