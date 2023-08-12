#include<iostream>
#include<vector>
using namespace std;

typedef class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode(int v = -1)
		:val(v)
		, left(nullptr)
		, right(nullptr)
	{}
}Node;

//�ݹ��˼·���һ��
//��������һ���Ϸ���λ��,�Ҵ������Լ���ͷ���,������createTree()�����ܰ��Ҵ�����ҵ�����֮�󷵻�����,
//Ȼ�����ҵ�ָ��������,��������Ϊͷ������������,���ٷ����ҵ�ͷָ��.
Node* createTree(vector<int>& nums, int n, int index)
{
	if (index > n || nums[index] == -1)
		return nullptr;

	Node*  node = new Node(nums[index]);
	node->left = createTree(nums, n, index * 2 + 1);
	node->right = createTree(nums, n, index * 2 + 2);
	return node;
}