//ǰ׺��,ʹ�þ�̬����ķ�ʽʵ��
//https://www.bilibili.com/video/BV1Yu4y1Q7vR?t=2719.0
//���񽲽�
#include<iostream>
#include<vector>
using namespace std;
class Trie
{
private:
	const int max_n = 150001;
	vector<vector<int>> tree;
	vector<int> pass;
	vector<int> end;
	int cnt;
public:
	Trie()
	{
		cnt = 1;
		tree = vector<vector<int>>(max_n,vector<int>(26));
		pass = vector<int>(max_n);
		end = vector<int>(max_n);
	}
public:
	void insert(string& word)
	{
		int cur = 1;
		pass[cur]++;
		for (int i = 0; i < word.size(); i++)
		{
			int path = word[i] - 'a';
			if (tree[cur][path] == 0)
				tree[cur][path] = ++cnt;
			cur = tree[cur][path];
			pass[cur]++;
		}
		end[cur]++;
	}
	int search(string& word)
	{
		int cur = 1;
		for (int i = 0; i < word.size(); i++)
		{
			int path = word[i] - 'a';
			if (tree[cur][path] == 0)
				return 0;
			cur = tree[cur][path];
		}
		return end[cur];
	}
	int preFixNum(string& word)
	{
		int cur = 1;
		for (int i = 0; i < word.size(); i++)
		{
			int path = word[i] - 'a';
			if (tree[cur][path] == 0)
				return 0;
			cur = tree[cur][path];
		}
		return pass[cur];
	}
	void erase(string& word)
	{
		if (search(word) > 0)
		{
			int cur = 1;
			for (int i = 0; i < word.size(); i++)
			{
				int path = word[i] - 'a';
				if (--pass[path] == 0)//ɾ��һ��û��,�����ֱ�Ӳ�Ҫ��
				{
					//����pathû·��.��Ϊ������,�����ı�Ǽ�ʹ��������,����Ҳ�������ֵ���Ǿ�ֵ�����
					tree[cur][path] = 0;
					return;
				}
				cur = tree[cur][path];
			}
			end[cur]--;
		}
	}
	//ÿһ���������������,������ȫ�ֱ�����¼,����Ҫ�ǵ����
	void clear()
	{
		for (int i = 1; i <= cnt; i++)
		{
			tree[i].clear();
			end[i] = 0;
			pass[i] = 0;
		}
	}
};