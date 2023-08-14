/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        //prevָ��m��ǰһ���ڵ�
        ListNode * prev=dummy;
        for(int i=1;i<m-1;i++)
            prev=prev->next;
        //
        ListNode* right=prev;
        for(int i=1;i<n-m+1;i++)
            right=right->next;
        //��ȡ������
        ListNode* left=prev->next;
        ListNode* cur=right->next;
        //
        prev->next=nullptr;
        right->next=nullptr;
        //��ת������
        reverseList(left);
        //�ӻ�ԭ��������
        prev->next=right;
        left->next=cur;
        return dummy->next;
    }
    //����m���Լ���n������һ��λ��
    void reverseList(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* cur=head;
        while(cur)
        {
            ListNode* cur_next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=cur_next;
        }
    }
};

ListNode* Func(ListNode* head,int n,int m)
{
	ListNode* dummy=new ListNode(-1);
	ListNode* prev=dummy;
	for(int i=1;i<m-1;i++)
		prev=prev->next;
	ListNode* left=prev->next;//��ת֮��,������������һ���ڵ�
	ListNode*right=prev;
	for(int i=1;i<n-m+1;i++)
		right=right->next;
	//right ���Ǵ���ת�����Ҷ˵�
	ListNode* cur=right->next;
	//
	prerv->next=nullptr;
	right->next=nullptr;//���ڷ�ת����ܹؼ�
	//
	reverseList(left);
	//
	prev->next=right;
	left->next=cur;
	return head;
}
void reverseList(ListNode* head)
{
	ListNode* prev=nullptr;
	ListNode* cur=head;
	while(cur)
	{
			ListNode* next=cu->next;
			cur->next=prev;
			prev=cur;
			cur=next;
	}
}