
//https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
//https://www.bilibili.com/video/BV11h4y1w7Bu?t=2863.6
//���γɳ���Ϊk-1�Ĵ���,֮��ÿ�εĲ�������
//1. �봰��,2. �ռ����ֵ,3. ������ര��
//������γɴ���ʱҪ��֤�����ڵĵ�����,ʹ��ÿʱÿ����Ҫ��ȡ��ֵ���Ƕ��е�ͷ��
//�����з��±�,���Ա�ֵ֤���ظ�
//β��ʱ,��֤ǰ������ֱ��Ҵ�,����һֱ����.
//�Լ�ʵ��˫�˶���,ʹ�������˫ָ��ķ�ʽ,Ч�ʻ����
//ͷɾʱ,Ҫ���Ǵ�ʱ��ͷԪ���Ƿ����,�����ͷԪ�ص��±�>����++��l,����������

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    static const  int N = 100001;
    int h, t;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        h = t = 0;
        //int* myDeque = new int(N);
        int myDeque[N] = { 0 };
        int n = nums.size();
        //������k-1��С�Ĵ��ڴ�С
        for (int i = 0; i < k - 1; i++)
        {
            //��֤�����ڵ�����
            while (h < t && nums[myDeque[t-1]] <= nums[i])
                t--;
            myDeque[t++] = i;
        }
        vector<int>ans;
        int l = 0, r = k - 1;
        while (r < n)
        {
            while (h < t && nums[myDeque[t-1]] <= nums[r])
                t--;
            myDeque[t++] = r;
            ans.push_back(nums[h]);
            if (myDeque[h] == l)
                h++;
            l++;
            r++;
        }
        //delete[] myDeque;
        return ans;
    }
};
class Solution1
{
    int N = 100001;
    int h, t;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        h = t = 0;//�����ʱû��ֵ
        vector<int>myDeque(N);
        int n = nums.size();
        //����,���γ�k-1��С�Ĵ���
        for (int i = 0; i < k - 1; i++)
        {
            while (h < t && nums[myDeque[t - 1]] <= nums[i])
                t--;
            myDeque[t++] = i;
        }
        int m = n - k + 1;
        vector<int>ans(m);
        for (int l = 0, r = k - 1; r < n; l++, r++)
        {
            while (h < t && nums[myDeque[t - 1]] <= nums[r])
                t--;
            myDeque[t++] = r;
            ans[l] = nums[myDeque[h]];
            //�漰���±���ڵ�����,��Ϊ�´�ѭ������l++��
            if (myDeque[h] == l)
                h++;
        }
        return ans;
    }
};
//int main()
//{
//    char* ptr = new char[19];
//    delete[] ptr;
//    cout << "ok" << endl;
//    //��Ȼdeleteû�г��ֱ���,���ǲ�����ζ������Ի�����
//    const int N = 10;
//    int arr[N] = { 0 };
//	return 0;
//}