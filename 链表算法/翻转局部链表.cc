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
        //prev指向m的前一个节点
        ListNode * prev=dummy;
        for(int i=0;i<m-1;i++)
            prev=prev->next;
        //
        ListNode* right=prev;
        for(int i=0;i<n-m+1;i++)
            right=right->next;
        //截取子链表
        ListNode* left=prev->next;
        ListNode* cur=right->next;
        //
        prev->next=nullptr;
        right->next=nullptr;
        //反转子链表
        reverseList(left);
        //接回原来的链表
        prev->next=right;
        left->next=cur;
        return dummy->next;
    }
    //传第m个以及第n个的下一个位置
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