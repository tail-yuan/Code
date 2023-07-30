#include<iostream>
#include<stack>
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
class IsPalindromeList
{
public:
	//1. ��ʹ�ÿ���ָ��ȷ���е�ͽ�β
	//2. �ı��Ҳ�ָ��ָ��
	//3. ͷָ����е�ָ��ͬʱ�ƶ�,�ж����
	bool isPalindrome2(Node* head)
	{
		if (head == nullptr || head->next == nullptr)
			return false;
		Node* n1 = head;
		Node* n2 = head;
		while (n2->next != nullptr || n2->next->next != nullptr)
		{
			n1 = n1->next;
			n2 = n2->next->next;
		}
		// n1<->mid n2<->last 
		n2 = n1->next;
		n1->next = nullptr;
		Node* n3 = nullptr;
		while (n2)
		{
			n3 = n2->next;
			n2->next = n1;
			n1 = n2;
			n2 = n3;
		}
		n2 = head;
		n3 = n1;
		bool res = true;
		while (n1 && n2)
		{
			if (n1->data != n2->data)
			{
				res = false;
				break;
			}
			n1 = n1->next;
			n2 = n2->next;
		}
		//recover list
		n1 = n3->next;
		n3->next = nullptr;
		while (n1)
		{
			n2 = n1->next;
			n1->next = n3;
			n3 = n1;
			n1 = n2;
		}
		return res;
	}
	//1. ʹ�ø�ջ�洢�ڵ�ֵ
	bool isPalindrome1(Node* head)
	{
		stack<int>st;
		Node* cur = head;
		while (cur)
		{
			st.push(cur->data);
			cur = cur->next;
		}
		cur = head;
		while (cur)
		{
			int top = st.top();
			if (cur->data != top)
				return false;
			cur = cur->next;
			st.pop();
		}
		return true;
	}
};