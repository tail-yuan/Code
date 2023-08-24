#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//��������:�����޻�ͼ�Ķ������򷽷�,���ж�������Ϊ��������
//����
//1. �ҵ��������Ϊ0�ĵ�,�������������������
//2. �������ͼ��ɾ��,���������Ըõ�Ϊ����ıߵ��յ�����-1
//3. �����ظ���������ֱ�����еĶ��㶼�����,����ͼ�в��������Ϊ0�Ķ��㼴��
class Solution
{
public:
	void topo_sort(vector<vector<int>>& arr, vector<int>& in)
	{
		queue<int> q;
		for (int i = 1; i < in.size(); i++)
		{
			if (in[i] == 0)
			{
				q.push(i);
				topo.push_back(i);
			}
		}
		while (!q.empty())
		{
			int front = q.front();
			q.pop();
			//��frontָ����յ����--
			for (int i = 0; i < arr[front].size(); i++)
			{
				int end = arr[front][i];
				in[end]--;
				if (in[end] == 0)
				{
					q.push(end);
					topo.push_back(end);
				}
			}
		}
	}
	void print()
	{
		for (int i = 0; i < topo.size(); i++)
			cout << topo[i] << " ";
		cout << endl;
	}
public:
	vector<int>topo;
};
//������
void test1()
{
	int n = 0;
	cin >> n;
	int tmp = n;
	vector<vector<int>>arr(n + 1);
	vector<int> in(n + 1);		//���,�±������,ֻ��¼����
	int index = 1;
	while (tmp--)
	{
		int next = 0;
		while (cin >> next && next != 0)
		{
			arr[index].push_back(next);
			in[next]++;
		}
		index++;
	}
	Solution s;
	s.topo_sort(arr, in);
	s.print();
}
void test2()
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>arr(n + 1);
	vector<int>in(n+1);
	while (m--)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		arr[start].push_back(end);
		in[end]++;
	}
	Solution s;
	s.topo_sort(arr, in);
	if (s.topo.size() != n)
		cout << -1 << endl;
	else
		s.print();
}
int main()
{
	test2();
	return 0;
}