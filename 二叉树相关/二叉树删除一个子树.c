#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	char val;
	struct Node* left;
	struct Node* right;
}Node;
Node* createTree()
{
	char ch;
	scanf("%c", &ch);
	//getchar();
	if (ch == '*')
		return NULL;
	else 
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->val = ch;
		node->left = createTree();
		node->right = createTree();
		return node;
	}
}
void preOrder(Node* root)
{
	if (root == NULL)
		return;
	printf("%c ",root->val);
	preOrder(root->left);
	preOrder(root->right);
}
void eraseSubTree(Node* cur)
{
	if (cur == NULL)
		return;
	erase(cur->left);
	erase(cur->right);
	free(cur);
}
void eraseNode(Node* root,char val,Node* parent)
{
	if (root == NULL)
		return;
	if (root->val == val)
	{
		if (parent == NULL)//���ɾ�����Ǹ��ڵ�,��������ɾ��
		{
			root = NULL;
			return;
		}
		else
		{
			if (parent->left == root)
				parent->left = NULL;
			else
				parent->right = NULL;
			eraseSubTree(root);
		}
	}
	else
	{
		parent = root;
		eraseNode(root->left,val,parent);
		eraseNode(root->right,val,parent);
	}
}
int main()
{
	Node* root = createTree();
	preOrder(root);
	getchar();
	printf("\n������Ҫɾ���Ľڵ�ֵ\n");
	char val = "";
	scanf("%c", &val);
	eraseNode(root,val,NULL);
	printf("ɾ���ڵ�֮��������������\n");
	preOrder(root);
}