
//https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

//������ΪK����������鳤��
//ʹ��ǰ׺��Ԥ����ʽ��������,��indexΪ��β������,��������������ʱ����̳���
//��δ�����? ǰ׺������preSum,����[a,b]�ĺ;���preSum[b]-preSum[a]��ֵ
//ǰ׺������϶��Ǳ��ֵ���������,������������ʱ��
//Ҫ��[0,index-1]�������ҵ��ܹ����ۼӺ�>=Kʱ,��ҵ��Ǹ�ֵ,��λ�ȡ?
//���Բ��õ������еķ�ʽ,queue<Node>
//Node<index,val>,val ��preSum[index]
//��preSum>Kʱ,���γ��Ե�����߽�,ʱ�̸�����̳���
//frontλ�õ�����,��Ҳ���ᱻʹ��.��Ϊ����Ѱ�������̳���,��Ȼ�ڴ�ʱ��������������
//�Ѿ��������,��ô֮�������ٶ�ֵ���и���,����f
// 
//��������ڸ���ʱ,����indexλ���ۼӺͱ�С,Ҫά�ֵ��������д�С����ĵ����Ծ�Ӧ�õ�����β(������͵���)
//Ȼ��index,preSum[index]����,
//����: ��������������sum -preSum[index]�������Ļ�,��ô��ȥ��preSum[index]�����ǰ����ۼӺ�
//�϶��������,��Ϊindexλ��ʱ��������preSum��С
//���һ��ø���,���Կ��Ե�����β.
//�������preSum[index]��ҲӦ�õ���,��Ϊ������Ҫ������̵�,�������ֺ�indexλ�ý�Ͽ϶��Ⱥ�index֮ǰ�����ֽ��
//Ҫ����,���ۼӺ���ֵ����ͬ�������
//https://www.bilibili.com/video/BV1y8411i7cY?t=1203.1
//1 <= nums.length <= 10^5
//-10^5 <= nums[i] <= 10^5
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    int maxlen = 100001;
public:
    int shortestSubarray(vector<int>& nums, int k)
    {
        //vector<int>preSum(maxlen);//preSum[i]��ʾǰi������ǰ׺��
        vector<long long>preSum(maxlen);//preSum[i]��ʾǰi������ǰ׺��
        vector<int>myqueue(maxlen);
        int h = 0, t = 0;
        
        int n = nums.size();
        for (int i = 0; i < n; i++)
            preSum[i + 1] = nums[i] + preSum[i];
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++)
        {
            // �����ǰ��ǰ׺�� - ͷǰ׺�ͣ���꣡->��¼�������ֵ������head
            while (h != t && preSum[i] - preSum[myqueue[h]] >= k)
                ans = min(ans, i - myqueue[h++]);
            // ��ȥͷ�����,��ô���漰�����������,��֤�������Ǵ�С����,���ֵ��Ȼ����
            while (h != t && preSum[myqueue[t - 1]] >= preSum[i])
                t--;
            myqueue[t++] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};