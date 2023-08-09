//https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/submissions/

class Solution 
{
public:
//1. 排序之后返回头k个值
//2. 使用堆的思想,O(nlogk)只能处理无重复值的情况,有重复值还需要再堆的基础上加上词频统计
//3. 快速选择算法,将前k小的数返回,但是并没有进行排序
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        sort(arr.begin(),arr.end());
        return {arr.begin(),arr.begin()+k};
    }
};

class Solution 
{
public:
//快速选择思想: 区间划分之后,最小的K个肯定已经放在了区间最左侧,进行区间个数比对返回结果
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        srand(time(NULL));
        qsort(arr,0,arr.size()-1,k);
        return {arr.begin(),arr.begin()+k};
    }
    void qsort(vector<int>& arr,int l,int r,int k)
    {
        if(l>=r)return;
        //获取随机值+划分三块区域
        int key=getRandom(arr,l,r);
        int i=l,less=l-1,more=r+1;
        while(i<more)
        {
            if(arr[i] >key) swap(arr[--more],arr[i]);
            else if(arr[i]<key) swap(arr[++less],arr[i++]);
            else i++;
        }
        //l,less less+1,more-1 more,r
        //求出区域元素个数,在选中的区间中继续去调用qsort函数找前k个元素
        int a=less-l+1,b=more-less-1;
        if(k<=a) qsort(arr,l,less,k);  //将左区间中前k个小的,放到区间前面
        else if(k-a<=b) return ;    //此时前k个已经摆好了
        else qsort(arr,more,r,k-a-b);//到右区间中将剩下的元素中前k-a-b个放到右区间较前面
    }
    int getRandom(vector<int>&arr,int left,int right)
    {
        return arr[rand() % (right-left+1)+left];
    }
};