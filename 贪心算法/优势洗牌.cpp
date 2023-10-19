//https://leetcode.cn/problems/advantage-shuffle/description/

//��������������ȵ����� nums1 �� nums2��nums1 ����� nums2 ������
//���������� nums1[i] > nums2[i] ������ i ����Ŀ��������
//���� nums1 ���������У�ʹ������� nums2 ���������

//̰��:
//1. �����������,�����ĺͶ�����ţ�Ĵ�,����ҲӮ����
//2. ����Ч�����,��Ӯ���þ���,������������ţ�ĺ�����
//Ϊ��O(1)ʱ���ȡ�����������е�Ŀ��ֵ,����������������򼴿�,����������ֵ��������
//���ش�ʱ����: �ǰ���nums2��ֵ��ԭʼ˳��һһƥ���ֵ,�����õ� ��������� ˼��
//���±�������򼴿�,��Ϊ�Ƕ���nums2ʵ�ֵ�,����ֻ��Ҫnums2���±����鼴��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        vector<int>index2(n);
        for (int i = 0; i < n; i++)
            index2[i] = i;
        sort(nums1.begin(), nums1.end());
        sort(index2.begin(), index2.end(), [&nums2](int i, int j)->bool {
            return nums2[i] < nums2[j];//��������
            });
        vector<int>ret(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (nums1[i] > nums2[index2[left]])
                ret[index2[left++]] = nums1[i];//ע���Ƕ�Ӧλ�÷�
            else
                ret[index2[right--]] = nums1[i];
        }
        return ret;
    }
};