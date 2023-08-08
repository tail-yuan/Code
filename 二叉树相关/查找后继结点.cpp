#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node* parent;
	Node(int d = -1)
		:data(d)
		, left(nullptr)
		, right(nullptr)
		,parent(nullptr)
	{}
};
//1. ���node�ڵ���������,��ô���ĺ�̽�����������������ڵ�
//2. ���node�ڵ�û��������,��Ҫһֱ������,���ݾ���������
Node* getNode(Node* cur)
{
	if (right == nullptr)return nullptr;
	while (cur)
	{
		cur = cur->left;
	}
	return cur;
}
Node* GetSuccessorNode(Node* node)
{
	if (node == nullptr)return nullptr;
	if (node->right)
		return getNode(node->right);
	else
	{
		Node* parent = node->parent;
		while (parent && node != parent->left)
		{
			node = parent;
			parent = parent->parent;
		}
		return parent;
	}
}