#include<iostream>
using namespace std;
//https://blog.csdn.net/weixin_58843717/article/details/129297240
class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* parent;
	int bf;	//ÿ���ڵ��Դ��ĸ�������
};
class AVLTree
{
private:
	Node* root;
public:
	//��Ϊ�������ǽ��漰�������ڵ�bf��Ϊ0,������ʵ��
	//���ӻ�ͼ���ƽ�����Ӹ���ע��:
	//90->left=30 30->right=60; ����֮ǰ90->bf=-1  30->bf=0;
	//60->bf =1 ˵��60->right=newNode; 60->bf=-1˵��60->left=newNode
	//����֮��90->bf=-2 30->bf=1 ����30Ϊ���Ľ�������,����90Ϊ��������
	//��ת֮����30->bf=1����,60->bf��ȻΪ0,
	//if 60->bf=1 ,90->bf=-1 ;if 60->bf=-1,90->bf=1
	void RotateLeftRight(Node* parent)
	{
		Node* subl = parent->left;
		Node* sublr = subl->right;
		int sublr_bf = sublr->bf;
		RotateLeft(subl);
		RotateRight(parent);
		if (sublr_bf == 1)
			parent->bf = -1;
		else if (sublr_bf == -1)
			parent->bf = 1;
		else
		{}
	}
	//�ǲ�ס״̬���¾ͻ�ͼ
	//�������: 90->right=30,30->left=60;30->bf=0,90->bf=1;
	//60->bf =1 ˵��60->right=newNode; 60->bf=-1˵��60->left=newNode
	//����֮��90->bf=2 30->bf= -1 ����30Ϊ���Ľ�������,����90Ϊ��������
	//��ת֮���ֲ���,60->bf��ȻΪ0,
	//if 60->bf=1 ,90->bf=-1; if 60->bf=-1,30->bf=-1
	void RotateRightLeft(Node* parent)
	{
		Node* subr = parent->right;
		Node* subrl = subr->left;
		int subrl_bf = subrl->bf;
		RotateRight(subr);	//subr->bf=-1<0,˵����߸�,������
		RotateLeft(parent);//parent->bf=2>0,˵���ұ߸�,������
		if (subrl_bf == -1)
		{
			//parent->bf = 0;
			subr->bf = 1;
		}
		else if (subrl->bf == 1)
		{
			parent->bf = -1;
			//subr->bf=0;
		}
		else
		{}
	}
	void RotateLeft(Node* parent)
	{
		Node* subr = parent->right;
		Node* subrl = subr->left;
		//1. 
		subrl->parent = parent;
		parent->right = subrl;
		
		Node* pparent = parent->parent;
		//2.
		subr->left = parent;
		parent->parent = subr;
		//
		if (parent == root)
		{
			subr = root;
			subr->parent = nullptr;
		}
		else
		{
			if (parent == pparent->left)
				pparent->left = subr;
			else
				pparent->right = subr;
			subr->parent = pparent;
		}
		subr->bf = parent->bf = 0;
	}
	void RotateRight(Node* parent)
	{
		Node* subl = parent->left;
		Node* sublr = subl->right;
		//1.
		parent->left = sublr;
		if (sublr)
			sublr->parent = parent;
		Node* pparent = parent->parent;
		//2. 
		subl->right = parent;
		parent->parent = subl;
		//3. 
		if (parent == root)
		{
			subl = root;
			subl->parent = nullptr;
		}
		else
		{
			if (pparent->left == parent)
				pparent->left = subl;
			else
				pparent->right = subl;
			subl->parent = pparent;
		}
		subl->bf = parent->bf = 0;
	}
};