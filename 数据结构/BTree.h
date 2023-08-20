#pragma once

template<class K, size_t M>
struct BTreeNode
{
	//Ӧ����M-1���ؼ���,M������.Ϊ�˷�������ٷ���,�Ͷ������һ���ռ�
	K _keys[M];
	BTreeNode<K, M>* _subs[M + 1];
	BTreeNode<K, M>* _parent;
	size_t _n;
	BTreeNode()
	{
		for (int i = 0; i < M; i++)
		{
			_keys[i] = K();
			_subs[i] = nullptr;
		}
		_subs[M] = nullptr;
		_parent = nullptr;
		_n = 0;
	}
};
template<class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	pair<Node*, int> Find(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			size_t i = 0;//ĳһ�ڵ���±�
			while (i < cur->_n)//�ڵ����йؼ�����
			{
				if (key < cur->_keys[i])
				{
					break;
				}
				else if (key > cur->_keys[i])
				{
					++i;//�������Ҹ����ֵȥ��
				}
				else
				{
					return make_pair(cur, i);
				}
			}
			//ÿ������һ���߼�¼���׽ڵ�,���ڵ�Insertʱ������ҪӦ�����������
			parent = cur;
			cur = cur->_subs[i];
			//1. ��break������,��ָ��������
			//2. ��i==_n���˽ڵ��������,��Ҫ����һ����,��ʱi=n,�����Ǻ��ӵ����һ���ڵ��±�
		}
		return make_pair(parent, -1);//û�ҵ�
	}
	void InsertKey(Node* cur, const K& key, Node* child)
	{
		int end = cur->_n - 1;
		while (end >= 0)
		{
			if (key < cur->_keys[end])
			{
				cur->_keys[end + 1] = cur->_keys[end];//Ų�����ݵ�ʱ����Ҳ�ø�����
				cur->_subs[end + 2] = cur->_subs[end + 1];
				--end;
			}
			else
			{
				break;
			}
		}
		//end=-1,��0λ�ò���
		//break����,�ڱȽϵ���һ��λ��ֱ�Ӳ������
		cur->_keys[end + 1] = key;
		cur->_subs[end + 2] = child;//�����ʱ�򽫺���Ҳ����
		cur->_n++;
		if (child)
		{
			child->_parent = cur;
		}
	}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_n++;
			return true;
		}
		pair<Node*, int> ret = Find(key);
		if (ret.second >= 0)
		{
			return false;
		}

		Node* cur = ret.first;
		K newKey = key;
		Node* child = nullptr;
		while (1)
		{
			InsertKey(cur, newKey, child);
			if (cur->_n < M)//M ���ؼ���ʱ������
			{
				return true;
			}
			else
			{
				//����һ��ֵ��bro keys[mid+1,M-1]�Լ�subs[]
				size_t mid = M / 2;
				Node* broNode = new Node;
				int j = 0;
				size_t i = mid + 1;
				for (i; i <= M - 1; i++)
				{
					//��������һ����(��ʣ���һ���Һ���)
					broNode->_keys[j] = cur->_keys[i];
					broNode->_subs[j] = cur->_subs[i];
					//�����˱�����
					if (cur->_subs[i])
						cur->_subs[i]->_parent = broNode;
					++j;
					cur->_keys[i] = K();//����һ��
					cur->_subs[i] = nullptr;
				}
				//��ʣ���һ���Һ���
				broNode->_subs[j] = cur->_subs[i];
				if (cur->_subs[i])
					cur->_subs[i]->_parent = broNode;
				cur->_subs[i] = nullptr;

				broNode->_n = j;
				cur->_n -= j + 1;//����һ�����˸���
				//���µ��Ǹ��ڵ�,���²����µĸ�
				if (cur->_parent == nullptr)
				{
					_root = new Node;
					_root->_keys[0] = cur->_keys[mid];
					cur->_keys[mid] = K();

					_root->_subs[0] = cur;
					_root->_subs[1] = broNode;
					_root->_n = 1;
					cur->_parent = _root;
					broNode->_parent = _root;
					break;
				}
				else
				{
					//���ϼ�������
					//��cur->parentȥ����cur->keys[mid] ��broNdoe�ڵ�
					newKey = cur->_keys[mid];
					cur->_keys[mid] = K();
					child = broNode;
					cur = cur->_parent;
				}
			}
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
	}
	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
			return;
		size_t i = 0;
		for (i; i < cur->_n; i++)
		{
			_InOrder(cur->_subs[i]);
			cout << cur->_keys[i] << " ";
		}
		_InOrder(cur->_subs[i]);
	}
private:
	Node* _root = nullptr;
};



void TestBtree()
{
	int a[] = { 53, 139, 75, 49, 145, 36, 101 };
	BTree<int, 3> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}
