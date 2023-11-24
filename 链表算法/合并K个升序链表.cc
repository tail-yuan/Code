// https://leetcode.cn/problems/merge-k-sorted-lists/description/

#include "Header.hpp"

// �ⷨһ:������ʽ
// �����ϲ��õ�һ���µ�,Ȼ���ٺ�һ������ϲ�...
// ʱ�临�Ӷ�: K�������ƽ��������N,����ÿ�������ȶ���N
// ����ʱ�临�Ӷ�ʱ��һ���뷨������������һ������ϲ�֮�󳤶��������ӵ�,�����2n
// �ٺϲ�һ�α��3n,O(3n+n)...
// ��ô��һ���Ƕ�,�ϲ����ɸ�һ������֮����i*n֮����Ҫ�ٱ���,������Ϊ��ÿ������Ϊn������
// ��������ʣ�������ϲ�һ�α���һ��,������:
// ֻ��Ե�һ������,��Ҫ��ʣ���k-1������ֱ�ִ��һ�κϲ�,�����ϲ���ʱ�临�Ӷ���O(n),
// ���Ե�һ������������ϲ���ռ�ݵ�ʱ�临�Ӷ���(k-1)*n
// ��Եڶ�������������ϲ���ռ�ݵ�ʱ�临�Ӷ�Ϊ(k-2)*n
//...
//(k-1)*n+(k-2)*n+(k-3)*n+...+n
// O(k^2 * n),���kҲ���Ǹ����ӽ�n,��O(n^3)
// leetCode : 132~140ms
class MergeKLists_1
{
private:
    ListNode *func(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if (l1)
            tail->next = l1;
        if (l2)
            tail->next = l2;
        return dummy->next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            ans = func(ans, lists[i]);
        }
        return ans;
    }
};

// �ⷨ��: ���ö����Ż�
// k��ָ��,��k���ڵ��ֵ�ŵ�����,Ȼ���ȡ��Сֵ���뵽��������
// С����һ��O(logk),��Ҫ����n��,������O(n*logk)
// leetCode : 24ms
class MergeKLists_2
{
    struct Less
    {
        bool operator()(ListNode *&l1, ListNode *&l2)
        {
            return l1->val > l2->val;
            // ˼����ʽ1: ����С���ѿ������µ�������ʱ,�϶��Ǹ� > �����д�ֵʱ������,������>
            // ˼����ʽ2: С������ɵ��ǽ���,������>����
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // 1. ����С����
        priority_queue<ListNode *, vector<ListNode *>, Less> heap;
        // 2. ������ͷ�����С����
        for (auto &l : lists)
        {
            if (l != nullptr)
                heap.push(l);
        }
        // 3. ����
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (!heap.empty())
        {
            ListNode *top = heap.top();
            heap.pop();
            tail->next = top;
            tail = top;
            if (top->next != nullptr)
                heap.push(top->next);
        }
        tail = dummy->next;
        delete dummy;
        return tail;
    }
};
// �ⷨ��: ����+�ݹ�ķ�ʽ
// ���仮��
// ���������ϲ�+�Ҳ�������ϲ�
//...��������,����������,���ֳ������⴦����
// Ȼ��ʹ�õݹ�ķ�ʽ����
// ʱ�临�Ӷ�: ÿ������ִֻ�кϲ��˸߶ȴμ���,�߶Ⱦ���O(logk)=>O(n*logk)
// leetCode : 24ms
class MergeKLists_3
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return func(lists, 0, lists.size() - 1);
    }
    ListNode *func(vector<ListNode *> &lists, int left, int right)
    {
        if (left > right)
            return nullptr;
        if (left == right)
            return lists[left];
        // ���仮��
        int mid = (left + right) >> 1;
        ListNode *l1 = func(lists, left, mid);
        ListNode *l2 = func(lists, mid + 1, right);
        return merge(l1, l2);
    }
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if (l1)
            tail->next = l1;
        if (l2)
            tail->next = l2;
        return dummy->next;
    }
};