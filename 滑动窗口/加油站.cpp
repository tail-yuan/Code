//https://leetcode.cn/problems/gas-station/	
//˼·: gas[i]�����iλ���ܹ���ȡ��������,cost[i]�����iλ�õ�����һ��λ�����ĵ�����
//leave= gas[i]-cost[i]������i+1λ��ʱ��ʣ�����.���leave>=0,������ʣ����,leave<0�����м��ͣ����
// �ʹ����iλ���޷�����i+1λ��.
//�жϴ��ĸ�λ��Ϊ����ܹ���һȦ,Ҳ�����ܹ�����n���ڵ�,
// ��ô��ÿ��λ��Ϊ��㶼����һ����������,�����;����leave<0,
//˵����ʱ�ĵ��޷�ʵ����һȦ,��ô��ȥ������һ����.�������൱�ڱ�������,T(N)=O(N^2),ÿ����leftʱ����Ҫ��right���˵�left+1λ��
//�Ż�Ϊ��������: �������leave<0��,left++,leave-[left],֮�������䳢�Լ�����������.
//��Ϊ���ڵĽ���Ŀ�涨��Ψһ��,��ô�ͷ���.

//����: ��������,��leftλ��Ϊ����������
//�ҵ���Χ�ʹ�ָ��֮��ĵ����Թ�ϵ
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        int len = 0;
        for (int l = 0, r = 0, sum = 0; l < n; l++)
        {
            while (sum >= 0)
            {
                if (len == n)
                    return l;
                //���ڼ�������������
                r = (l + (len)) % n;
                len++;
                sum += gas[r] - cost[r];
            }
            //sum<0
            len--;
            sum -= gas[l] - cost[l];
        }
        return -1;
    }
};