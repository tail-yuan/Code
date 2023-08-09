//https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/
class Solution 
{
    vector<int>counts;
    vector<int>tmp;
    vector<int>index;//记录数据原始下标
    vector<int>tmpIndex;//为了对下标的合并使用临时数组
public:
//采用区间降序,关注与(left,mid)中x值,查看(mid+1,right)中是否有y<x,那么right-p2+1个都是比x小的
//在两个区间降序合并之后,元素的下标重新变化,下标变了,下一次无法将值放到正确的位置
//如果用哈希表,那么如果有重复元素出现,就会存在值的覆盖,出现问题
//所以写个index数组记录数据原始的下标,在数据移动的过程中,下标也跟着移动,数据需要tmp数组,那么下标也需要一个tmpIndex移动
//一个数据的下标和数据移动好了之后,才可以i++,p1++,p2++
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n=nums.size();
        counts.resize(n);
        tmp.resize(n);
        tmpIndex.resize(n);
        index.resize(n);
        for(int i=0;i<n;i++)
            index[i]=i;

        merageSort(nums,0,n-1);
        return counts;
    }
    void merageSort(vector<int>&nums,int left,int right)
    {
        if(left>=right)return ;
        int mid=(right-left)/2+left;
        merageSort(nums,left,mid);
        merageSort(nums,mid+1,right);
        //后序遍历
        int p1=left,p2=mid+1,i=0;
        while(p1<=mid && p2<=right)//区间降序数组
        {
            if(nums[p1]>nums[p2])
            {
                
                counts[index[p1]] += right-p2+1;//随着合并之后下标的重新分配,count计数下标出现变换
                tmpIndex[i]=index[p1];
                tmp[i++]=nums[p1++];
            }
            else
            {
                tmp[i]=nums[p2];
                tmpIndex[i++]=index[p2++];
            }
        }
        while(p1<=mid) tmpIndex[i]=index[p1],tmp[i++]=nums[p1++];
        while(p2<=right) tmpIndex[i]=index[p2],tmp[i++]=nums[p2++];
        for(int i=left;i<=right;i++)
            nums[i]=tmp[i-left],index[i]=tmpIndex[i-left];
    }
};