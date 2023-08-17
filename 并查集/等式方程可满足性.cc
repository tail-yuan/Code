//https://leetcode.cn/problems/satisfiability-of-equality-equations/description/
class Solution 
{
    private:
    vector<int>ufs;
public:
//因为不同变量之间相等具有可传递性,所以将相等的数字放到同一集合当中,判断根节点是否相同来代替实现判断
    int FindRoot(int x)
    {
        while(ufs[x]>=0)
            x=ufs[x];
        return x;
    }
    bool equationsPossible(vector<string>& nums) 
    {
        //多少个变量?  nums[i][0] nums[i][3]
        //因为都是小写的字母,所以最大不超过26
        ufs=vector<int>(26,-1);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(nums[i][1] == '=')//相等,进行合并操作
                {
                    int ai =nums[i][0] - 'a',bi=nums[i][3]-'a';
                    int root1 =FindRoot(ai);
                    int root2 =FindRoot(bi);
                    if(root1!=root2)
                    {
                        ufs[root1]+=ufs[root2];
                        ufs[root2]=root1;
                    }
                }
            }
        }
        //找不相同的,看是否是不同节点
        for(auto& str: nums)
        {
            if(str[1] == '!')
            {
                    int ai =str[0] - 'a',bi=str[3]-'a';
                    int root1 =FindRoot(ai);
                    int root2 =FindRoot(bi);
                    if(root1==root2)
                        return false;
            }
        }
        return true;
    }
};