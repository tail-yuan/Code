//��iλ��Ϊ��β
//https://leetcode.cn/problems/subarrays-with-k-different-integers/
// ���䷶Χ�̶�,�����Χ����Խ��,����ĸ���Խ���ܳ���K.������
// ֻ���������K��û�е����Ե�,��Ϊ��һ���������������С����Ͳ�����K.������K���е�������
//nums���������������Ǻ�������ĸ����Ƕ���?
//��������: ���������ֵ���������Ǽȶ���K��,���Ǻ�������
//���:
//�����f����,f(nums,k)���ص�����������������<=k��������ĸ���
//��ô����k��������ĸ���ret = f(nums,k)-f(nums,k-1)
//f����ͳ������[l,r]��������������С��kʱ��������ĸ���,�ۼ�����rΪ��β������������ĸ���
// ��rΪ��β��������ĸ�����r-l+1,����[0...3]: 0~3,1~3,2~3,3~3 4��
//��һ������xͳ��������ֵ��ַ����༰����,֧�ֲ���ɾ���̶�Ԫ��
//1. ��������Ĺ�����,x��������<k,r++
//2. ���x��������kind==k,��¼��ʱ��������ĸ���
//	Ȼ��l++,ɾ��l
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return f(nums, k) - f(nums, k - 1);
    }
    int f(vector<int>& nums, int k)
    {
        //Լ���ô�С��N,��ô���е����ֶ���1~N�����ڵ�����.��ô�Ϳ�N+1�ռ�������ִ�Ƶͳ��
        vector<int>cnts(20001,0);
        int collect = 0;
        int ans = 0;
        for (int l = 0, r = 0; r < nums.size(); r++)
        {
            if (++cnts[nums[r]] == 1)//�����ַ���һ�ν���
                collect++;
            while (collect > k)
            {
                if (--cnts[nums[l++]] == 0)
                    collect--;
            }
            //collect==k
            //ÿ�����һ��r,���ۼ�����rΪ��β�����������
            ans += r - l + 1;
        }
        return ans;
    }
};