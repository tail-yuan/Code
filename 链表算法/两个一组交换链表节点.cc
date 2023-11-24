#include "Header.hpp"

// �ⷨ1. ʹ�õݹ�ķ�ʽʵ��
// ������: ����func�����ܹ��������ڵ�֮���������ɽ���,Ȼ�󷵻�ͷ���ָ��
// ֻ��Ҫ���� head ->next ->ret�����ڵ�֮���ָ���ϵ����,����next����
// ����: ֻʣ��һ���ڵ��ʱ��Ͳ���Ҫ������
class TwoNodeSwapList_1th
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *ret = swapPairs(head->next->next);
        ListNode *next = head->next;
        head->next = ret;
        next->next = head;
        return next;
    }
};
// �ⷨ2: ʹ��ѭ���ķ�ʽ
// �����ĸ��ڵ�ָ�����,ָ��ڵ�,���ı���֮���ָ���ϵ����
// ��ʱ,���ö��һ��ͷ���ķ�ʽ�������̶Ƚ�����������ǵ����������
// prev cur next nnext
// ע�����dummyͷ���֮������ڵ�����ż������ʱ��Ľ�������
// 1. �������֮��,cur==nullptr,������ż��
// 2. �������֮��,next==nullptr,ֻʣ��cur һ���ڵ�,û�н����ı�Ҫ
class TwoNodeSwapList_2th
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy, *cur = head, *next = head->next, *nnext = head->next->next;
        while (cur && next)
        {
            // �����ڵ�
            prev->next = next;
            cur->next = nnext;
            next->next = cur;
            // �ƶ�ָ��1
            prev = cur;
            cur = nnext;
            // �ƶ�ָ��2
            if (cur)
                next = cur->next;
            if (next)
                nnext = next->next;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};