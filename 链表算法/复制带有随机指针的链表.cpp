
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



class Node
{
public:
	int data;
	Node* next;
	Node* randPtr;
	Node(int val)
		:data(val)
		, next(nullptr)
		,randPtr(nullptr)
	{}
};
class CopyList
{
public:
	//1. �Ƚ����ķ�ʽ,�ù�ϣ���¼<Դ�ڵ�,�½��ڵ�>,Ȼ�����ԭ��������������
	//<O(N),O(N)>ʹ�õ�����ռ�
	Node* copyList1(Node* head)
	{
		unordered_map<Node*, Node*> hashMap;
		Node* cur = head;
		while (cur)
		{
			Node* newNode = new Node(cur->data);
			hashMap[cur] = newNode;
			cur = cur->next;
		}
		cur = head;
		while (cur)
		{
			hashMap[cur]->next = cur->next;
			hashMap[cur]->randPtr = cur->randPtr;
			cur = cur->next;
		}
		return hashMap[head];
	}
	//2. <O(N),O(1)> ���²����Ľڵ�ֱ��������ÿ���ڵ�ĺ���,���split
	Node* copyList2(Node* head)
	{
		if (head == nullptr)return;
		Node* cur = head;
		while (cur)
		{
			Node* next = cur->next;

			Node* newNode = new Node(cur->data);
			newNode->next = cur->next;
			cur->next = newNode;

			cur = next;
		}
		//����randPtr
		cur = head;
		Node* copyNode = nullptr;
		while (cur)
		{
			copyNode = cur->next;
			Node* next = cur->next->next;
			copyNode->randPtr = cur->randPtr == nullptr ? nullptr : cur->randPtr->next;
			cur = next;
		}
		//split����������
		Node* res = head->next;
		cur = head;
		while (cur)
		{
			Node* next = cur->next->next;
			copyNode = cur->next;
			cur->next = next;
			copyNode->next = next == nullptr ? nullptr : next->next;
			cur = next;
		}
		return res;
	}
};