// https://leetcode.cn/problems/reverse-nodes-in-k-group/

// k��һ�鷭ת����,Ȼ����漰��ָ��ı任��.����k���Ľڵ��ǲ��ö�
// 1. �������Ҫ��תx��,x=n/k
// 2. �ظ�n��k���ڵ�һ��ķ�ת���� (�������,ʹ��ͷ��ķ�ʽ��������)
// O(N)
#include "Header.hpp"
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int n = 0;
        ListNode *cur = head;
        while (cur)
        {
            n++;
            cur = cur->next;
        }
        n /= k;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy; // ָ��ͷ���ǰ�����
        cur = head;
        while (n--)
        {
            ListNode *tmp = cur;
            for (int i = 0; i < k; i++)
            {
                ListNode *next = cur->next;
                cur->next = prev->next; // ͷ��ķ�ʽ��������
                prev->next = cur;
                cur = next;
            }
            prev = tmp;
        }
        prev->next = cur;
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};