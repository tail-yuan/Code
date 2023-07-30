#include<iostream>
#include<vector>
#include<unordered_map>
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
class ListSplitData
{
public:
	//ʹ��6��ָ�������ʶ��������
	Node* listSplit2(Node* head, int pivot)
	{
		Node* sHead = nullptr;
		Node* sTail = nullptr;
		Node* eHead = nullptr;
		Node* eTail = nullptr;
		Node* bHead = nullptr;
		Node* bTail = nullptr;

		Node* next = nullptr;
		while (head)
		{
			next = head->next;
			if (head->data < pivot)
			{
				if (sHead == nullptr)
					sHead = sTail = head;
				else
				{
					sTail->next = head;
					sTail = head;
				}
			}
			else if (head->data > pivot)
			{
				if (bHead == nullptr)
					bHead = bTail = head;
				else
				{
					bTail->next = head;
					bTail = head;
				}
			}
			else
			{
				if (eHead == nullptr)
					eHead = eTail = head;
				else
				{
					eTail->next = head;
					eTail = head;
				}
			}
			head = head->next;
		}
	}
public:
	//1. ��������,��������->���黮��,������������������ƴ��������
	Node* listSplit1(Node* head, int pivot)
	{
		if (head == nullptr)return nullptr;
		int n = 0;
		Node* cur = head;
		while (cur)
		{
			n++;
			cur = cur->next;
		}
		vector<Node*>arr(n);
		cur = head;
		int i = 0;
		while (cur)
		{
			arr[i++] = cur;
			cur = cur->next;
		}
		arrPatition(arr, pivot);

		//�󾹷���,����������ǽڵ�ָ��,�Ϳ���ֱ������,��������int���������ٿ��ռ�
		for (int i = 1; i < arr.size(); i++)
		{
			arr[i - 1]->next = arr[i];
		}
		arr[i - 1]->next = nullptr;
		return arr[0];
	}
	void arrPatition(vector<Node*>& arr, int pivot)
	{
		//����Ϊ�������� less equal more
		int less = -1, more = arr.size();
		int index = 0;
		while (index < more)
		{
			if (arr[index]->data > pivot)
			{
				swap(arr[more - 1], arr[index]);
				more--;
			}
			else if (arr[index]->data < pivot)
			{
				swap(arr[less + 1], arr[index]);
				index++;
				less++;
			}
			else
				index++;
		}
	}
};