#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include"���鼯.hpp"
using namespace std;
template<class V,class W,W MAX_W =INT_MAX,bool Direction =false>
class Graph
{
	typedef Graph<V, W, MAX_W, Direction> self;
private:
	map<V, int> vIndexMap;
	vector<V> vertexs;		  //�㼯
	vector<vector<W>> matrix; //����洢��Ϣ
public:
	struct Edge
	{
		int srci;
		int desti;
		W w;
		Edge(int s, int d, int w1)
			:srci(s)
			, desti(d)
			, w(w1)
		{}
		bool operator>(const Edge& e)
		{
			return w > e.w;
		}
	};
public:
	//��Դ���·��-�������ͼ-��Ȩֵ�Ǹ�
	//dist: ��¼srci-�����������·��Ȩֵ����
	//pPath: ��¼srci-�����������·������������
	void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
	{
		int srci = GetVertexIndex(src);
		int n = vertex.size();
		dist.resize(n);
		pPath.resize(n, -1);

		dist[srci] = 0;
		dist[srci] = srci;
		vector<bool>S(n, false);//�Ѿ�ȷ�������·���Ķ��㼯��
		//ÿ�δ�Q ���ҳ�һ����㵽�ý�������С�Ľ��u ��
		//��u ��Q ���Ƴ���������S �У�
		//��u ��ÿһ�����ڽ��v �����ɳڲ���
		for (int j = 0; j < n; j++)
		{
			int u = 0;
			W min = MAX_W;
			for (int i = 0; i < n; i++)
			{
				if (S[i] == false && dist[i] < min)
				{
					min = dist[i];
					u = i;
				}
			}
			S[u] = true;
			//�ɳڴ���: ����·��ѡ��С,min(src->uParent->u,src->u)
			for (int v = 0; v < n; v++)
			{
				if (!S[v] && matrix[u][v] != MAX_W && 
					dist[u] + matrix[u][v] < dist[v])
				{
					dist[v] = dist[u] + matrix[u][v];
					pPath[v] = u;
				}
			}
		}

	}

public://��С������
	// Prim�㷨: ����һ��src��,ѡ����������С��. ̰��+���Ƶ�
	W Prim(self& minTree, const V& src)
	{
		int srci = GetVertexIndex(src);
		int sz = vertex.size();
		//1. ��ʼ��
		vertexs = minTree.vertexs;
		vIndexMap = minTree.vIndexMap;
		int m = minTree.matrix.size();
		int n = minTree.matrix[0].size()
			matrix.resize(m);
		for (int i = 0; i < m; i++)
			matrix[i].reize(n, MAX_W);
		//2. ���Ƚ���src���������е�ı���С��,ÿ�λ�ȡsrci��������С��
		priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
		for (int i = 0; i < n; i++)
		{
			if (matrix[srci][i] != MAX_W)
				pq.push(Edge(srci, i, matrix[srci][i]));
		}
		//3. ѡ��,ѡ����С���յ�û�ù���,Y[i]=false,������ֻ�
		//	Ҫѡ���ڵ�-1����,������С���������ۼ�total

		vector<int>X(sz, false);//X[i]=true����i������ù�
		vector<int>Y(sz, false);//Y[i]=true����i�����û�ù�
		X[srci] = true, Y[srci] = false;
		int size = 0;
		W total = W();

		while (!pq.empty())
		{
			Edge min = pq.top(); pq.pop();
			if (X[min.desti])//��С��Ŀ�����X������,�����Ѿ�ѡ����
			{}
			else
			{
				minTree.AddEdge(min.srci, min.desti, min.w);
				X[min.desti] = true, Y[min.desti] = false;
				++ size;
				total += min.w;
				if (size == sz - 1)
					break;
				//
				for (int i = 0; i < n; i++)
				{
					if (matrix[srci][i] != MAX_W && Y[i])
						pq.push(Edge(srci, i, matrix[srci][i]));
				}
			}
		}
		if (size == sz - 1)
			return total;
		else
			return W();
	}
	// Kruskal�㷨: ��ͼ�е����б���,ѡ����С�ı�. ̰��+���Ƶ�
	W Kruskal(self& minTree)
	{
		//1. ��ʼ��
		vertexs = minTree.vertexs;
		vIndexMap = minTree.vIndexMap;
		int m = minTree.matrix.size();
		int n= minTree.matrix[0].size()
		matrix.resize(m);
		for (int i = 0; i < m; i++)
			matrix[i].reize(n, MAX_W);
		//2. �����ڽӾ����Ȩֵ������,�ŵ�С����,ÿ�λ�ȡ����ͼ�е���С��
		priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i < j && matrix[i][j] != MAX_W)
					pq.push(Edge(i, j, matrix[i][j]));
			}
		}
		//3. ������С������,Ϊ�˱���ѡ���ظ���,��ѡ���ʱʹ�ò��鼯
		//	 ѡ�нڵ����-1����
		int sz = vertex.size();
		UnionFind ufs(sz);
		int size = 0;//�涨ѡ��sz-1����
		W total = W();

		while (!pq.empty())
		{
			Edge min = pq.top(); pq.pop();
			if (!ufs.IsOneSet(min.srci, min.desti))
			{
				minTree.AddEdge(min.srci, min.desti, min.w);
				ufs.Union(min.srci, min.desti);
				++size;
				total += min.w;
			}
			else {}//˵��ѡ���˵���С����������һ�����ϵ�,˵���Ѿ�ѡ����,�Ͳ���ѡ��
		}
		if (size == sz - 1)
			return total;
		else
			return W();
	}
public:
	void dfs(int&index, vector<bool>& visi)
	{
		cout << index << ":" << vertexs[index] << endl;
		visi[index] = true;
		for (int i = 0; i < vertex.size(); i++)
		{
			if (matrix[index][i] != MAX_W && !visi[i])
				dfs(i, visi);
		}
	}
	void DFS(const V& src)
	{
		int srci = GetVertexIndex(src);
		vector<bool> visi;
		int n = vertexs.size();
		visi.resize(n, false);

		dfs(srci,visi);
	}
	//�������
	void BFSLevel(const V& src)
	{
		int srci = GetVertexIndex(src);
		vector<bool> visi;
		int n = vertexs.size();
		visi.resize(n, false);
		queue<int>q;
		q.push(srci);
		visi[srci] = true;

		int levelSize = 1;
		while (!q.empty())
		{
			for (int i = 0; i < levelSize; i++)
			{
				int front = q.front(); q.pop();
				cout << front << ":" << vertexs[front] << " ";
				for (int i = 0; i < n; i++)
				{
					if (matrix[front][i] != MAX_W && !visi[i])
					{
						q.push(i);
						visi[i] = true;
					}
				}
			}
			cout << endl;
			levelSize = q.size();
		}
	}
	void BFS(const V&src)
	{
		int srci = GetVertexIndex(src);
		vector<bool> visi;
		int n = vertexs.size();
		visi.resize(n, false);
		
		queue<int>q;
		q.push(srci);
		visi[srci] = true;
		while (!q.empty())
		{
			int front = q.front(); q.pop();
			cout << front << ":" << vertexs[front] << " ";
			//��front���ڽӵ㶼�Ž���
			for (int i = 0; i < n; i++)
			{
				if (matrix[front][i] != MAX_W && !visi[i])
				{
					q.push(i);
					visi[i] = true;
				}
			}
		}
	}
public:
	Graph() = default;

	void AddEdge(const V& src, const V& dest, const W& w)
	{
		int srci = GetVertexIndex(src);
		int desti = GetVertexIndex(dest);
		_AddEdge(srci, desti, w);
	}
	void _AddEdge(int srci, int desti, const W& w)
	{
		matrix[srci][desti] = w;
		if (Direction == false)
			matrix[desti][srci] = w;
	}
	int GetVertexIndex(const V& v)
	{
		auto it = vIndexMap.find(v);
		if (it != vIndexMap.end())
			return it->second;
		else
		{
			cout << "�����������" << endl;
			return -1;
		}
	}
	Graph(const V* a, int n)
	{
		vertexs.reserve(n);
		for (int i = 0; i < n; i++)
		{
			vertexs.push_back(a[i]);
			vIndexMap[a[i]] = i;
		}
		matrix.resize(n);
		for (int i = 0; i < n; i++)
			matrix.resize(n, MAX_W);
	}
};