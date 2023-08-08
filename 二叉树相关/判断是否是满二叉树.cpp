#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d = -1)
		:data(d)
		, left(nullptr)
		, right(nullptr)
	{}
};
//�����������㹫ʽ: 2^height -1=����
//����������Ҫ�߶��Լ��ڵ�����
class info
{
public:
	int nodes;
	int height;
	info(int num, int h)
		:nodes(num)
		, height(h)
	{}
};
info process(Node* head)
{
	if (head == nullptr) return info(0,0);
	info left = process(head->left);
	info right = process(head->right);
	int height = max(left.height, right.height) + 1;
	int nodes = left.nodes + right.nodes + 1;
	return info(nodes, height);
}
bool isFullTree(Node* head)
{
	info ret = process(head);
	return (1 << ret.height - 1) == ret.nodes;
}