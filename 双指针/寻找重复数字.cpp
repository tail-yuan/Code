//https://leetcode.cn/problems/find-the-duplicate-number/description/
//ֻ�����޼��������ҵ�����ظ�������

//�ⷨ:
//x=nums[i],��ô��һ��ָ��͵�xλ��,һֱ������ȥ,����ͼ��,��������ظ�ֵ�ͻ�������������г��ֻ������
//ʹ�ÿ���ָ��ķ�ʽģ��,Ȼ���ҵ����������е��뻷�ڵ�����ظ�ֵ.
//��ָ��һ��������,��ָ��һ����һ��,ע���ʼ��.���ջ��ڻ��ϵĽڵ�����
//֮������ָ����һ����ͷ,ͬ������һ��,�ͻ����뻷�ڵ�����.
#include<iostream>
#include<vector>
using namespace std;

class Solution2
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        if (nums.size() < 2)
            return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;//�ص���ͷ
        while (slow != fast)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};