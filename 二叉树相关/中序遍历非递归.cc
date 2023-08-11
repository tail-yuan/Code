#include<iostream>
#include<stack>
using namespace std;
class TreeNode
{
	public:
	int data;
	TreeNode* left;
	TreeNode* right;
};
typedef TreeNode Node;
void inorderNoRecur(Node* root)
{
	if (root == nullptr)return;
	stack<Node*>st;
	Node* cur = root;
	while (cur || !st.empty())
	{
		//����߽���ջ
		while (cur != nullptr)
		{
			st.push(cur);
			cur = cur->left;
		}
		//��ʱջ��������ڵ�
		cur = st.top(); st.pop();
		//do thing!
		cout << cur->data << " ";
		cur = cur->right;
	}
}