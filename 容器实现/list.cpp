#include<iostream>
#include<list>
using namespace std;
int main1()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(1);
	lt1.push_back(1);
	lt1.push_back(1);
	//1. ֻ֧�ֵ���������
	list<int>::iterator it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		//cout << *it1 << endl;
		it1++;
	}
	//2. splice()����,���ڵ��ƶ������������λ��(LRUʵ�ִ������õ�)
	list<int> lt2;
	lt2.push_back(2);
	lt2.push_back(2);
	lt2.push_back(2);
	lt2.push_back(2);
	lt2.push_back(3);
	//lt1.splice(lt1.begin(),lt2);//��lt2����Ԫ���ƶ���lt1.begin()֮ǰ
	lt1.splice(lt1.begin(), lt2, find(lt2.begin(),lt2.end(),3));
	list<int>::iterator it = lt1.begin();
	advance(it,3);//��itָ��3Ԫ�����ڽڵ�
	while (it != lt1.end())
	{
		cout << *it << endl;
		it++;
	}
	system("pause");
	return 0;
}
//list��˫������Ŷ!!!
namespace yuanwei
{
	template<class T>
	class Node
	{
	public:
		T data;
		Node<T> * next;
		Node<T>* prev;
		Node(T d=T())
			:data(d)
			, next(nullptr)
			, prev(nullptr)
		{}
	};
	//��Ϊlist������vectorһ���ڴ�ռ���������,֧��ָ��,���Ծ��Լ���װһ��������,������ָ��һ��,�������
	template<class T,class Ref=T&,class Ptr=T*>//T ,T& ,T*
	class __list_iterator
	{
	public:
		typedef Node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
	//private:
		Node* node;
	public:
		__list_iterator(Node* n)
			:node(n)
		{}
		//�ڵ㱾�����ڵ�����,���Բ����ͷ�node
		~__list_iterator()
		{}
		//��Ϊʵ�ֵ��ǵ�����,��������ɶ����ǳ����Ҳû��ϵ,��Ϊ��Ҫ�ľ���ָ��ͬһ��ڵ�,������Դ�ͷ�Ҳ�����������,����
		//��Ĭ�����ɵ�ǳ����ûë��
	public:
		Ref operator*()
		{
			return node->data;
		}
		Ptr operator->()
		{
			return &node->data;
		}
		//ǰ��++,�õ�����ָ����һ��λ��
		self& operator++()
		{
			node = node->next;
			return *this;
		}
		//����++,���صĻ���֮ǰ��
		self operator++(int)
		{
			self tmp(*this);
			node = node->next;
			return tmp;
		}
		//ǰ��--,�õ�����ָ��ǰһ��λ��
		self& operator--()
		{
			node = node->prev;
			return *this;
		}
		//����++,���صĻ���֮ǰ��
		self operator--(int)
		{
			self tmp(*this);
			node = node->prev;
			return tmp;
		}
		//!=�жϵ��������������Ƿ�ָ���ͬһ���ڵ�,�������ж�ֵ���!!!
		bool operator!=(const self& it)
		{
			return node != it.node;
		}
		bool operator==(const self& it)
		{
			return node == it->node;
		}
	};
	template<class T>
	class list
	{
	public:
		typedef Node<T> Node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef const __list_iterator<T, T&, T*> const_iterator;
	private:
		Node* head;
	public:
		list()
		{
			head = new Node();
			head->next = head;
			head->prev = head;
		}
		~list()
		{
			delete head;
			head = nullptr;
		}
	public:
		//list��˫������  end()(head)->begin()->.....->tail->end()(head)
		iterator begin()//ָ����������ʼλ��
		{
			return iterator(head->next);
		}
		iterator end()//ָ���������һ��Ԫ�ص���һ��λ��
		{
			return iterator(head);
		}
		const_iterator begin() const
		{
			return const_iterator(head->next);
		}
		const_iterator end()const 
		{
			return const_iterator(head);
		}
	public:
		void push_back(const T& val)
		{
			/*Node* tail = head->prev;
			Node* newNode = new Node(val);
			newNode->prev = tail;
			newNode->next = head;
			head->prev = newNode;
			tail->next = newNode;*/
			insert(end(), val);
		}
		void push_front(const T& x)
		{
			insert(begin(),x);
		}
		void pop_front()
		{
			erase(begin());
		}
		void pop_back()
		{
			erase(--end());
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
	public:
		//Ĭ�ϲ���posλ��ǰ
		iterator insert(iterator pos, const T& val)
		{
			Node* newNode = new Node(val);
			Node* cur = pos.node;
			Node* prev = cur->prev;

			newNode->next = cur;
			prev->next = newNode;
			newNode->prev = prev;
			cur->prev = newNode;
			return iterator(newNode);
		}
		//Ĭ�Ͻ�ɾ���ڵ�ĺ�һ���ڵ����������
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos.node;
			Node* prev = cur->prev;
			Node* next = cur->next;

			prev->next = next;
			next->prev = prev;
			delete cur;
			return iterator(next);
		}
	public:
		void empty_init()
		{
			head = new Node();
			head->next = head;
			head->prev = head;
		}

		//����д��->��������-> ���
		/*list(const list<T>& lt)
		{
			empty_init();
			for (auto e : lt)
			{
				push_back(e);
			}
		}*/
		//��������,����������
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		//�ִ�д��2,ʹ�õ����������ʼ��һ��tmp
		list(const list<T>& lt)
		{
			empty_init();//��֮ǰ�����ÿ�,������tmp֮��,�����������������Դ�ͷ�.���⽻��֮�����������޷��������ֵ

			list<T> tmp(lt.begin(), lt.end());
			swap(head,tmp.head);
		}
		////�ִ�д��1,ʹ�ù��캯������һ��tmp
		//list(const list<T>& lt)
		//{
		//	empty_init();
		//	list<T> tmp(lt);///////////error,����list()������Ӳ���,���ǲ�̫��
		//	swap(head, tmp.head);
		//}

		//��ֵ����
		list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				empty_init();
				for (auto e : lt)
				{
					push_back(e);
				}
			}
			return *this;
		}
		list<T>& operator=(list<T> lt)
		{
			swap(head, lt.head);
			return *this;
		}
	};
	void printList(const list<int>& lt)
	{
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << "->";
			++it;
		}
		cout << endl;
	}
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it = 20;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		printList(lt);

		list<int>lt2(lt);
		list<int>::iterator it2 = lt2.begin();
		while (it2 != lt2.end())
		{
			//*it = 20;
			cout << *it2 << " ";
			++it2;
		}
		cout << endl;
	}
}
int main()
{
	yuanwei::test_list1();
	return 0;
}