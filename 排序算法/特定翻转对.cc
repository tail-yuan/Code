//https://leetcode.cn/problems/reverse-pairs/submissions/
class Solution 
{
    vector<int>tmp;
    int ret;
public:
//归并排序策略与翻转对统计策略相左,即ret更新策略和区间排序策略不同.采用ret选择策略可能导致区间数组变得无序,但是我们想要高效率计算对数还得需要区间单调性.这是问题所在.
//需要区间单调性,来一次获取多个翻转对,同向双指针,一次合并升级为O(n).一共O(logn)次,=>O(nlogn)
//策略1:专注于(left,mid)区间中的x,在(mid+1,right)中的y,满足x>2*y,ret+=right-p2+1,采用区间降序
//策略2:专注于(mid+1,right)区间中的y,在(left,mid)区间中的x,如果x/2 >y,ret+=mid-p1+1,采用区间升序
    int reversePairs(vector<int>& nums) 
    {
        int n=nums.size();
        tmp.resize(n);
        mergeSort(nums,0,n-1);
        return ret;
    }
    void mergeSort(vector<int>&nums,int left,int right)
    {
        if(left>=right)return ;

        int mid=(right-left)/2+left;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        int p1=left,p2=mid+1,i=0;
        //后序到这里得到两个有序数组,在这里进行翻转对的计算
        while(p1<=mid)
        {
            while(p2<=right && nums[p2]>=nums[p1]/2.0) p2++;//nums[p2]*2会出现问题
            if(p2>right) break;//没找到就不用找了
            ret += right-p2+1;
            p1++;
        }
        //别忘了将两个区间头指针更改回来,进行区间数值合并
        p1=left,p2=mid+1;
        while(p1<=mid && p2<=right)//完成区间降序排列
        {
            // if(nums[p1] > 2* nums[p2])
            //     ret+=right-p2+1;
            if(nums[p1] > nums[p2])
                tmp[i++]=nums[p1++];
            else
                tmp[i++]=nums[p2++];
        }
        while(p1<=mid) tmp[i++]=nums[p1++];
        while(p2<=right) tmp[i++]=nums[p2++];
        for(int i=left;i<=right;i++)
            nums[i]=tmp[i-left];
    }
};