//https://leetcode.cn/problems/container-with-most-water/description/
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    //���� ö����������������������[left,right]
    //V= (right-left) * min()
    //�Ż�: right�Ƿ���Ҫÿ�ζ����˵�left+1��λ������������
    //left++,1. ��Χ�϶�С��,2. ����ϴμ���ʱ�߶�����right������,right �ǽ�Сֵ,��β���nums[left]���V���Ǽ�С�� 3. ����ϴμ���ʱ�߶�����left������,left�ǽ�Сֵ,3.1 nums[left+1]>right,��Ҫ����.3.2 ���nums[left+1]<right,V�϶���С��������
    //����,���û���right,left++�������������if([left]< [right] && [left+1]>right)����һ��,������left<rightʱ������Ҫ����
    //��Ϊʲô�����������м�����?
    //�߶����ı߾�����,
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ret = INT_MIN;
        while (left < right)
        {
            int tmp = (right - left) * min(height[left], height[right]);
            ret = max(ret, tmp);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return ret;

        // int left=0,right=0;
        // int ret=0;
        // for(int i=0;i<height.size();i++)
        // {
        //     int tmp=0;
        //     while(left<=right)
        //     {
        //         tmp=(right-left)*min(height[left],height[right]);
        //         ret=max(ret,tmp);
        //         if(height[left]<height[right] && height[left+1] >height[right])
        //         {
        //             tmp=(right-left)*min(height[left],height[right]);
        //             ret=max(ret,tmp);
        //         }
        //         left++;
        //     }
        // }
    }
};