// https://leetcode.cn/problems/reorder-list/description/

// ����һ�������� L ��ͷ�ڵ� head �������� L ��ʾΪ��
// L0 �� L1 �� �� �� Ln - 1 �� Ln
// �뽫���������к��Ϊ��
// L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
// ����ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

// ��ʵ������������ĺϲ�
// ����ֻ��Ҫ1. ������������в��,Ȼ��õ���������,(����ָ��)
// 2. ��������Ǹ������������(��ָ������,ֱ�Ӹı�ָ�򼴿�)
// 3. ʵ����������ĺϲ�����(˫ָ��ϲ�)
#include "Header.hpp"
class Solution
{
public:
    ListNode *reverseList(ListNode *l2)
    {
        if (l2 == nullptr)
            return l2;
        ListNode *prev = nullptr, *cur = l2, *next = nullptr;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void reorderList(ListNode *head)
    {
        //û�ڵ�/һ���ڵ�/�����ڵ㶼û��Ҫ,��ֱ�ӷ���
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;
        // 1. ����ָ��ָ�����
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = head, *l2 = slow->next;
        slow->next = nullptr;
        // 2. ִ��l2���������
        l2 = reverseList(l2);
        // 3. �ϲ���������
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (l1 && l2)
        {
            tail->next = l1;
            tail = tail->next;
            if (l1)
                l1 = l1->next;
            tail->next = l2;
            tail = tail->next;
            if (l2)
                l2 = l2->next;
        }
        if (l1)
            tail->next = l1;
        if (l2)
            tail->next = l2;
        head = dummy->next;
        return ;
    }
};