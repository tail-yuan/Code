//https://leetcode.cn/problems/bLyHh0/submissions/
class Solution 
{
    private:
    vector<int> ufs;
public:
    int FindRoot(int x)
    {
        while(ufs[x]>=0)
            x=ufs[x];
        return x;//返回头的下标
    }
    int findCircleNum(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        ufs= vector<int>(n,-1);//-1的含义: 每一个节点以自己为头的集合中元素个数就是自己一个
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j] == 1)//i j两点之间存在相连关系
                {
                    int root1 =FindRoot(i);
                    int root2 =FindRoot(j);
                    if(root1 !=root2)
                    {
                        ufs[root1] += ufs[root2];
                        ufs[root2]=root1;
                    }
                }
            }
        }
        int count=0;
        for(auto e:ufs)
            if(e<0)
                count++;
        return count;
    }
};