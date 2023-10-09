//https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/
//����ж��ٸ�������Ա����
//���ִ�+̰��+˫�˶���(�뵽��������֧�ֵ�����)
// 
//�������ķ�Χ���Ա�ȷ��,����0��,��඼�������,��ô��������ɶ��ٸ�����?
//������: ���8������϶������7������Ҫ����,����ʹ�ö��ִ𰸷�,����mid�������ܷ����,
//���mid�겻��,��ômid,right�϶�Ҳ�겻��,��ȥ����������,���mid�����,��¼��,���Ҳ����䳢��
//������Ҫfunc����,�ж�mid�������ܷ����
//���ֻҪ�����k������,��ô�����һ�����������������һ��ʱ,�϶�ѡ����Ҫ������С��k������,����
//һ��ѡ��������ǿ��k������ȥ�����С��k������,̰��˼��.
//func��������ȫȡ���ڹ��˳Ե�ҩ������������
//���,������һ������ʱ,�ȿ�һ���ڲ���ҩ��������ܹ���ɵ�����,�����Ƿ��뵽dq��,
//��dq�д����Լ�����������ʱ,ѡ��dq��ͷ����,Ҳ������С���������,һ���ܱ�֤����.��Ҫ����ߵ����񽻸������������
//��dq��û���Լ�����������ʱ,Ҫ��ҩ��,����ҩ֮��,���Լ���������Щ����,�ŵ�������,
//�ڱ�֤����������,Ӧ���ó���ҩ���Լ�ȥ����Լ�������Χ��Ҫ����������,Ҳ���ǵ�����ʱ��β��Ԫ��.
//һ����ʹ��ҩ����ʡ��,��������ҩ�蹻����.
//��Ϊ���ȶ��Ź�����,�������ҩ֮��û�п���ƥ�������,ֱ�ӷ���false
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
    vector<int>tasks;
    vector<int>workers;
    int MAXLEN = 100001;
    vector<int>dq;
    int h, t;
public:
    int maxTaskAssign(vector<int>& t, vector<int>& w, int pills, int strength)
    {
        tasks = t;
        workers = w;
        dq = vector<int>(MAXLEN);
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int tsz = tasks.size(), wsz = workers.size();
        int ans = 0;
        for (int l = 0, r = min(tsz, wsz); l <= r;)
        {
            int mid = (l + r) / 2;
            if (func(mid, pills, strength, 0, mid - 1, wsz - mid, wsz - 1))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
    bool func(int count, int p, int s, int tl, int tr, int wl, int wr)
    {
        h = t = 0;
        int cnt = 0;
        for (int i = wl,j=tl; i <= wr; i++)
        {
            //i: ���˱��,j:������
            //1. ��i�Ź����ܹ�����������ŵ�������
            for (; j <= tr && workers[i] >= tasks[j]; j++)
                dq[t++] = j;
            //2. �������ҩ�����������
            if (h<t && workers[i] >= tasks[dq[h]])
                h++;
            else
            {
                //3. ����ó�ҩ,������ҩ֮���ܹ�����������ŵ�������
                for (; j <= tr && workers[i] + s >= tasks[j]; j++)
                    dq[t++] = j;
                if (h < t)
                {
                    cnt++;
                    t--;
                }
                else
                    return false;
            }
        }
        return cnt <= p;
    }
};