#include "Header.hpp"
// https://leetcode.cn/problems/add-two-numbers/
// ��Ϊ����洢������������ÿһλ������״̬,
// �½�dummyͷ���,Ȼ����������������,��һ��������¼��λ������һλ��������
// �õ���ÿһλ�Ľ���ŵ�һ���ڵ���,Ȼ�����β�弴��
// ע��: ������������е������㹻��,���������ʹ洢�϶��ǲ��е�,�ͻῼ�ǵ��ַ���
// ���ǽ�����->�ַ���->����->�ӷ�����ʱ�ո��Ӷȶ��Ƚϸ�

class AddNodeOfList
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *cur1 = l1, *cur2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        int carry = 0; // ��λ,���һλ��λ֮�����Ϊ10,Ҫ�������һλ,����cary!=0
        while (cur1 != nullptr || cur2 != nullptr || carry != 0)
        {
            if (cur1 != nullptr)
            {
                carry += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2 != nullptr)
            {
                carry += cur2->val;
                cur2 = cur2->next;
            }
            ListNode *newNode = new ListNode(carry % 10);
            tail->next = newNode;
            tail = newNode;
            carry /= 10;
        }
        tail = dummy->next;
        delete dummy;
        return tail;
    }
};