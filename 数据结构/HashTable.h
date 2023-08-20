#pragma once
#include<iostream>
#include<vector>
using namespace std;

// 1. HashFunc������Լ�����string���͵��ػ�
// 2. HashData�������,
// 3. ��ɢ�����,���Բ���,������λ������(EMPTY DELETE EXIST),Լ�������վ�ֹͣ
// 4. ��ģ���ʹ��
// 5. ����ʱ,�����¶��󽻻��������666
// 6. ���ҽڵ�ʱʱ��ע��EXIST,�ҿ�λ��ʱEMPTY��DELETE�ĵ㶼����ʹ��,ɾ���ڵ�ʱֻ�ǽ���־λ����ΪDELETE
//
template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
template<>
struct Hash<string>
{
	size_t operator()(const string& key)
	{
		size_t res = 0;
		for (auto e : key)
		{
			res *= 31;
			res += e;//�ַ�ASCII��ֵ��˺�=>size_t ����
		}
		return res;
	}
};
namespace CloseHash
{
	//��ɢ��,�����ϣ��ͻʱ�ǽ���ͻ�����ݷ��ں���Ŀ�λ��
	//��ν������̽��(��������)�Ĺ�����,���x����y,��y��ͻ��y'������x����,��������
	// �����xɾ��֮�󵥴�����Ϊ�յĻ�,����һ�β���y'ʱ��x��λֱ��ͣ��,����ɲ��Ҳ���y'
	//�����վ�ֹͣ,��֪����ɾ���Ļ��Ǳ����Ϳյ�,�������ñ�־λenum������
	enum STATUS
	{
		EMPTY,
		DELETE,
		EXIST
	};
	template<class K,class V>
	struct HashData
	{
	public:
		pair<K, V> _kv;
		STATUS _st = EMPTY;
	};
	template<class K,class V,class HashFunc=Hash<K>>
	class HashTable
	{
	private:
		vector<HashData<K, V>> _tables;
		size_t n = 0;

	public:
		HashData<K,V>* Find(const K & key)
		{
			if (_tables.size() == 0)
				return nullptr;
			HashFunc hf;
			size_t start = hf(key) % _tables.size();
			size_t i = 0;
			size_t index = start + i;
			while (_tables[index]._st != EMPTY)//Լ���Ĳ��ҵ��վ�ֹͣ
			{
				if (key == _tables[index]._kv.first && _tables[index]._st == EXIST)
					return &_tables[index];
				i++;
				index = start + i;
				index %= _tables.size();
			}
			return nullptr;
		}
		bool Insert(const pair<K, V>& kv)
		{
			//û�ҵ��Ų��밡!�ҵ��˾Ͳ�������
			if (Find(kv.first) != nullptr)
				return false;
			if (_tables.size() == 0 || n * 10 / _tables.size() == 0.7)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				//�����µĴ��,���ݲ��뵽�±���
				//���¶���ı���
				//���ź���ջ֡����,�¶������֮ǰ�ľɱ�һ����ʧ
				HashTable<K, V, HashFunc> newHT;
				newHT._tables.resize(newSize);
				for (int i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._st == EXIST)
						newHT.Insert(_tables[i]._kv);
				}
				_tables.swap(newHT._tables);
			}

			HashFunc hf;
			size_t i = 0;
			size_t start = hf(kv.first) % _tables.size();
			size_t index = start + i;
			while (_tables[index]._st == EXIST)
			{
				++i;
				index = start + i;//���ҵĲ����ǿ��Ըı��,����̽�����һ��һ����,�ҵ��վ�ֹͣ
				index %= _tables.size();
			}
			//[index].st=EMPTY | DELETE
			_tables[index]._kv = kv;
			_tables[index]._st = EXIST;
			n++;
			return true;
		}
		//ɾ���ڵ�ʱֻ�ǽ���־λ����ΪDELETE
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret==nullptr)
				return false;
			else
			{
				--n;
				ret->_st = DELETE;
			}
		}
	};
	void TestHashTable1()
	{
		//HashTable<int, int, Hash<int>> ht;
		HashTable<int, int> ht;

		int a[] = { 2, 12, 22, 32, 42, 52, 62 };
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(72, 72));

		cout<<ht.Find(2)->_kv.second<<endl;
		ht.Erase(ht.Find(2)->_kv.first);
	}
	void TestHashTable2()
	{
		/*HashStr hs;
		cout << hs("sort")<<endl;
		cout << hs("insert") << endl;
		cout << hs("eat") << endl;
		cout << hs("ate") << endl;
		cout << hs("abcd") << endl;
		cout << hs("aadd") << endl;*/

		HashTable<string, string> ht;
		ht.Insert(make_pair("sort", "����"));
		ht.Insert(make_pair("string", "�ַ���"));

		// ��key��һ����������ʱ����Ҫ����һ���º�������keyת������
		//HashTable<Date, string, HashDate> htds;
	}
}
//int main()
//{
//	CloseHash::TestHashTable1();
//}
namespace LinkHash
{
	template<class K,class V>
	struct HashNode
	{
		pair<K,V> _kv;
		HashNode<K,V>* _next;
		HashNode(const pair<K, V>& d)
			:_kv(d)
			, _next(nullptr)
		{}
	};
	template<class K,class V,class HashFunc=Hash<K>>
	struct HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		bool Erase(const K& key)
		{
			HashFunc hf;
			int index = hf(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						_tables[index] = cur->next;
					}
					else
					{
						prev->_next = cur->next;
					}
					--_n;
					delete cur;
					cur = nullptr;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}
		Node* find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;
			HashFunc hf;
			int index = hf(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_kv.first == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}
		bool Insert(const pair<K, V>& kv)
		{
			HashFunc hf;
			Node* ret = find(kv.first);
			if (ret)
				return false;
			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node* >newHT;
				newHT.resize(newSize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = hf(cur->_kv.first) % newHT.size();
						cur->_next = newHT[index];
						newHT[index] = cur;
						cur = next;
					}
					_tables[i] = nullptr;//ÿ������һ���ͽ������β->nullptr
				}
				_tables.swap(newHT);
			}
			size_t index = hf(kv.first) % _tables.size();
			Node* newNode = new Node(kv);
			newNode->_next = _tables[index];
			_tables[index] = newNode;
			++_n;
			return true;
		}
	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};
	void TestHashTable()
	{
		int a[] = { 4, 24, 14,7,37,27,57,67,34,14,54 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(84, 84));
	}
}
int main()
{
	LinkHash::TestHashTable();
}