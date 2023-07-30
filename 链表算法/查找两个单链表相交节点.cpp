#include<iostream>
#include<vector>
using namespace std;


class Node
{
public:
	int data;
	Node* next;
	Node(int val)
		:data(val)
		, next(nullptr)
	{}
};

class findFirstInteractNode
{
public:
	//�������������һ���ཻ��
	//1. �������������ɻ� 1.1 �޽��㷵��nullptr 2. ����Ψһ����
	//2. �����������ɻ�&&�뻷�ڵ���ͬһ�� 
	//3. �����������ɻ�&&�뻷�ڵ㲻��ͬһ��,�����ĸ��뻷�ڵ����
	//ע:ע�ⵥ����ָ�������,���ɻ��Ŀ϶��ǹ���һ����,��ȡһ���������뻷�ڵ�ʹ�ÿ���ָ�뷽��
	Node* getFirstInteractNode(Node* head1, Node* head2)
	{
		if (head1 == nullptr || head2 == nullptr)return;
		Node* loop1 = getLoopNode(head1);
		Node* loop2 = getLoopNode(head2);
		if (loop1 == nullptr && loop2 == nullptr)
			return noloop(head1,head2);
		if (loop1 != nullptr && loop2 != nullptr)
			return bothLoop(head1,head2,loop1,loop2);
		return nullptr;
	}
	Node* bothLoop(Node* head1, Node* head2,Node*loop1,Node* loop2)
	{
		Node* cur1 = nullptr, * cur2 = nullptr;
		if (loop1 == loop2)
		{
			Node* cur1 = head1, * cur2 = head2;
			int n = 0;
			while (cur1)
			{
				n++;
				cur1 = cur1->next;
			}
			while (cur2)
			{
				n--;
				cur2 = cur2->next;
			}
			cur1 = n < 0 ? head2 : head1;
			cur2 = cur1 == head1 ? head2 : head1;
			int del = abs(n);
			while (del--) cur1 = cur1->next;
			while (cur1 != cur2) cur1 = cur1->next, cur2 = cur2->next;
			return cur1;
		}
		else
		{
			Node* cur1 = loop1->next;
			while (cur1 != loop1)//������һȦ,�϶�����һ���뻷�ڵ�����
			{
				if (cur1 == loop2)
					return loop2;
				cur1 = cur1->next;
			}
			return nullptr;
		}
	}
	Node* getLoopNode(Node* head)
	{
		//���������ɻ�
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
			return nullptr;
		Node* n1 = head->next;
		Node* n2 = head->next->next;
		while (n1 != n2)
		{
			if (n2->next == nullptr || n2->next->next == nullptr)
				return nullptr;
			n1 = n1->next;
			n2 = n2->next->next;
		}
		//��ʱn1n2�ڻ��ϵ�ĳһ���ڵ㴦,����һ����ͷ��,һ�����뻷�ڵ�����
		n1 = head;
		while (n1 != n2)
		{
			n1 = n1->next;
			n2 = n2->next;
		}
		return n1;
	}
	Node* noloop(Node* head1, Node* head2)
	{
		Node* cur1 = head1, * cur2 = head2;
		int n = 0;
		while (cur1)
		{
			cur1 = cur1->next;
			n++;
		}
		while (cur2)
		{
			n--;
			cur2 = cur2->next;
		}
		if (cur1 != cur2)//β�Ͳ���һ��,˵��û���ཻ
			return nullptr;
		//�н���
		cur1 = n < 0 ? head2 : head1;
		cur2 = cur1 == head1 ? head2 : head1;
		int dis = abs(n);
		while (dis--)
		{
			cur1 = cur1->next;
		}
		//cur1,cur2��ʱ���뽻����ͬ
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;//���ؽ���
	}
};