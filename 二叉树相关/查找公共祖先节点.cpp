#include<iostream>
#include<unordered_map>
#include<unordered_set>
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

void process(Node* head, unordered_map<Node*, Node*>& hashMap)
{
	if (head == nullptr) return;
	hashMap.insert({head->left,head});
	hashMap.insert({head->right,head});
	process(head->left, hashMap);
	process(head->right, hashMap);
}
Node* lowestCommonNode(Node* head, Node* o1, Node* o2)
{
	unordered_map<Node*, Node*> hashMap;//<cur,parent>
	process(head,hashMap);
	unordered_set<Node*> hashSet;
	//������������
	Node* cur = o1;
	while (cur!=head)//��û�����ڵ�,��һֱ������
	{
		hashSet.insert(cur);
		cur = hashMap[cur];
	}
	hashSet.insert(head);
	cur = o2;
	while (hashMap.count(cur)==0)//��o1�γɵĵ������в����Ƿ����o2�ĸ��׽ڵ㽻��
	{
		cur = hashMap[cur];
	}
	return cur;
}