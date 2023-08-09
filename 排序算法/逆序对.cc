//ret作为全局变量使用:只在merage合并的过程中产生逆序对
//划分的区间是升序的,在合并过程中关注(mid+1,right)中的y,如果在(left,mid)中有一个x>y,那么就有mid-index(x)+1个逆序对.
//这时,比y大的前面的都找完了,就找index(y)+1的了.将y放入tmp中
class Solution 
{
    int ret;
    vector<int>tmp;
public:
//归并排序思想,逆序对的产生发生在merage的过程中
    int reversePairs(vector<int>& nums) 
    {
        tmp.resize(nums.size());
        merageSort(nums,0,nums.size()-1);
        return ret;
    }
    void merageSort(vector<int>&nums,int left,int right)
    {
        if(left>=right) return ;
        int mid=(right-left)/2+left;
        merageSort(nums,left,mid);
        merageSort(nums,mid+1,right);
        int p1=left,p2=mid+1,i=0;
        while(p1<=mid && p2<=right)
        {
            if(nums[p1]<=nums[p2])
                tmp[i++]=nums[p1++];
            else
            {
                ret+= mid-p1+1; 
                tmp[i++]=nums[p2++];
            }
        }
        while(p1<=mid)tmp[i++]=nums[p1++];
        while(p2<=right)tmp[i++]=nums[p2++];
        //[left,right]拷贝回原数组
        for(int i=left;i<=right;i++)
            nums[i]=tmp[i-left];
    }
};


//如果划分区间是降序的,那么找逆序对,就需要关注(left,mid)区间中的x值,如果(mid+1,right)中有一个y值<x,那么就有(right-index(y)+1)
//个逆序对产生,都是对x小的.
class Solution 
{
    int ret;
    vector<int>tmp;
public:
//归并排序思想,逆序对的产生发生在merage的过程中
    int reversePairs(vector<int>& nums) 
    {
        tmp.resize(nums.size());
        merageSort(nums,0,nums.size()-1);
        return ret;
    }
    void merageSort(vector<int>&nums,int left,int right)
    {
        if(left>=right) return ;
        int mid=(right-left)/2+left;
        merageSort(nums,left,mid);
        merageSort(nums,mid+1,right);
        int p1=left,p2=mid+1,i=0;
        while(p1<=mid && p2<=right)
        {
            if(nums[p1]>nums[p2])
            {
                ret+= right-p2+1;
                tmp[i++]=nums[p1++];
            } 
            else
                tmp[i++]=nums[p2++];
        }
        while(p1<=mid)tmp[i++]=nums[p1++];
        while(p2<=right)tmp[i++]=nums[p2++];
        //[left,right]拷贝回原数组
        for(int i=left;i<=right;i++)
            nums[i]=tmp[i-left];
    }
};


//ret作为merageSort函数的返回值,意义是我给定你一个区间,你归并排序之后将逆序对的个数返回
//左区间逆序对+右区间逆序对+合并过程中产生的逆序对
//区间降序
class Solution 
{
    vector<int>tmp;
public:
//归并排序思想,逆序对的产生发生在merage的过程中
    int reversePairs(vector<int>& nums) 
    {
        tmp.resize(nums.size());
        int ret = merageSort(nums,0,nums.size()-1);
        return ret;
    }
    int merageSort(vector<int>&nums,int left,int right)
    {
        if(left>=right) return 0;
        int mid=(right-left)/2+left;
        int ret=0;
        ret+= merageSort(nums,left,mid);
        ret+= merageSort(nums,mid+1,right);
        int p1=left,p2=mid+1,i=0;
        while(p1<=mid && p2<=right)
        {
            if(nums[p1]>nums[p2])
            {
                ret+= right-p2+1;
                tmp[i++]=nums[p1++];
            } 
            else
                tmp[i++]=nums[p2++];
        }
        while(p1<=mid)tmp[i++]=nums[p1++];
        while(p2<=right)tmp[i++]=nums[p2++];
        //[left,right]拷贝回原数组
        for(int i=left;i<=right;i++)
            nums[i]=tmp[i-left];
        return ret;
    }
};
//区间升序
class Solution 
{
    vector<int>tmp;
public:
//归并排序思想,逆序对的产生发生在merage的过程中
    int reversePairs(vector<int>& nums) 
    {
        tmp.resize(nums.size());
        int ret = merageSort(nums,0,nums.size()-1);
        return ret;
    }
    int merageSort(vector<int>&nums,int left,int right)
    {
        if(left>=right) return 0;
        int mid=(right-left)/2+left;
        int ret=0;
        ret+= merageSort(nums,left,mid);
        ret+= merageSort(nums,mid+1,right);
        int p1=left,p2=mid+1,i=0;
        while(p1<=mid && p2<=right)
        {
            if(nums[p1] <= nums[p2])
                tmp[i++]=nums[p1++];
            else
            {
                ret+= mid-p1+1;
                tmp[i++]=nums[p2++];
            }
        }
        while(p1<=mid)tmp[i++]=nums[p1++];
        while(p2<=right)tmp[i++]=nums[p2++];
        //[left,right]拷贝回原数组
        for(int i=left;i<=right;i++)
            nums[i]=tmp[i-left];
        return ret;
    }
};