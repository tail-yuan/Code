
//https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/
//ÿ��ѡ����������������ɾ��,Ϊ������Ч��ʹ�ô����O(1)ʱ���ȡ
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution 
{
public:
    int halveArray(vector<int>& nums) 
    {
        priority_queue<double> bigHeap;
        int n = nums.size();
        double sum = 0;//�漰��С��,һ��Ҫ��double����,����ᷢ���ض����⵼�¾��ȶ�ʧ
        for (int i = 0; i < n; i++)
        {
            bigHeap.push(nums[i]);
            sum += nums[i];
        }
        sum /= 2.0;
        int count = 0;
        while (sum > 0)
        {
            double t = bigHeap.top() / 2.0; bigHeap.pop();
            sum -= t;
            bigHeap.push(t);
            count++;
        }
        return count;
    }
};