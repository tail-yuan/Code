//https://leetcode.cn/problems/kth-largest-element-in-an-array/submissions/
class Solution
{
public:
//使用堆的特性,O(nlogn)
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++)
            pq.push(nums[i]);
        for(int i=k;i<nums.size();i++)
        {
            if(pq.top()< nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
//快速选择算法 O(n)基于快排区间划分的思想,比较区间个数
//快速选择算法只是将区间划分,区间内还是无序的,并没有像快拍那样递归的进行了排序,只是将比key小的放在区间最前部分
class Solution 
{
public:
//划分三块区间之后,记录三块区间元素个数,a,b,c找出第k大的值并返回
    int findKthLargest(vector<int>& nums, int k) 
    {
        srand(time(NULL));
        int ret = qsort(nums,0,nums.size()-1,k);
        return ret;
    }
    //给定左右区间边界和需要在区间中找到第k大的值,相信函数能够返回第K大的数
    int qsort(vector<int>&nums,int left,int right,int k)
    {
        if(left==right) return nums[left];

        int key=getRandom(nums,left,right);
        int less=left-1,more=right+1,i=left;
        while(i<more)
        {
            if(nums[i] > key) swap(nums[--more],nums[i]);
            else if(nums[i]<key) swap(nums[++less],nums[i++]);
            else i++;
        }

        //left,less less+1,more-1 more,right
        int c=right-more+1,b=more-1 -less-1+1;
        if(k<=c) return qsort(nums,more,right,k);
        else if(k-c<=b) return key; //中间区间值都相同,直接返回key
        else return qsort(nums,left,less,k-b-c);//在左区间中找第K-b-c大的值
    }
    int getRandom(vector<int>&nums,int left,int right)
    {
        return nums[rand()%(right-left+1)+left];
    }
};