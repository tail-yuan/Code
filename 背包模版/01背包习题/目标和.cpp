//https://leetcode.cn/problems/target-sum/description/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//�ⷨ1:
//ʹ�ñ������Եķ�ʽ,����һ�����޷Ǿ���+������-
// -------------������С����ͨ������,����ʱ���� 1000ms����
class Solution11 //
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int ret = dfs(nums, target, 0, 0);
        return ret;
    }
    int dfs(vector<int>& nums, int target, int index, int path)
    {
        if (index == nums.size())
            return path == target ? 1 : 0;
        return dfs(nums, target, index + 1, path - nums[index])
            + dfs(nums, target, index + 1, path + nums[index]);
    }
};


//�ⷨ2:
//����ʹ�ü��仯������¼,���ǿ���path�����Ǹ��������,����ֻ��ʹ�ù�ϣ����м�¼
//���ڱ���i>=0,sum(j)����С��0,����sum�ļ�¼ʹ�ù�ϣ���¼
// 2.1 vector<unordered_map<int, int>>memo; i��ֱ��O(1)�������
// 2.2 unordered_map<int,unordered_map<int, int>>memo iҲ��O(logn)�������
// -------------T(N) �����200~300ms����
class Solution12_1
{
    vector<unordered_map<int, int>>memo;//i��vector��¼,j��unordered_map��¼
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();
        memo = vector<unordered_map<int, int>>(n);
        int ret = dfs(nums, target, 0, 0);
        return ret;
    }
    int dfs(vector<int>& nums, int target, int i, int path)
    {
        if (i == nums.size())
            return path == target ? 1 : 0;
        if (!memo[i].empty() && memo[i].count(path)!=0)//vector<i>λ���ж��� && path��¼��(�Ż��в���Ľڵ�,����0 or 1)
            return memo[i][path];
        int ret= dfs(nums, target, i + 1, path + nums[i]) + dfs(nums, target, i + 1, path - nums[i]);
        memo[i].insert({ path,ret });
        return ret;
    }
};
class Solution12_2
{
    unordered_map<int,unordered_map<int, int>>memo;//i��vector��¼,j��unordered_map��¼
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();
        int ret = dfs(nums, target, 0, 0);
        return ret;
    }
    int dfs(vector<int>& nums, int target, int i, int path)
    {
        if (i == nums.size())
            return path == target ? 1 : 0;
        if (memo.count(i)!=0 && memo[i].count(path)!=0)
            return memo[i][path];
        int ret = dfs(nums, target, i + 1, path + nums[i]) + dfs(nums, target, i + 1, path - nums[i]);
        if (memo.count(i) == 0)
            memo.insert({ i, unordered_map<int, int>() });
        memo[i].insert({ path,ret });
        return ret;
    }
};



//�ⷨ3:
//������ϸ��λ������,����������sum�����Ǹ������¶�ά��j�и����϶��治��,
//���Կ���λ��ƽ�Ƶķ�ʽ���д洢����
//https://www.bilibili.com/video/BV1NN41137jF?t=2953.4
//����: 
//sum���ֵ�����������ֶ��Ǹ�����a,��Сֵ�����������ֶ��Ǹ�����b,��ô��ά����[i][j]
//j: b<=j<=a,������벿�ֶ��Ǹ���,��ô����ʵ���ñ��ʱ�������ƽ��,��֤��벿�ֶ�>=0���� ---  1 
//��ƽ��a����λ����,[0...n][0...2*a],[j]->[j+a]λ�ô洢
//i���ܹ�ȡ��n��,���Կռ���Ҫ��n+1,jȡ��target���������,���Կռ��ڱ�֤Ϊ��ʱҪ����2*sum+1�ռ��
//ע���ʼ��: sum==targetʱ��һ�ַ�ʽ,1
//���˳��: ������i+1,���Դ�������,j��ȡֵ��-sum~+sum,��ʱ��Ҫע���±��ƫ����,��������ν
//����ֵ : dp[0][0]->dp[0][sum]
//T(N): 80ms����  �ڴ���22MB
class Solution13_1
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for (int e : nums)
            sum += e;
        //����: ����Ч��
        if (target<-sum || target>sum)
            return 0;
        int offset = sum;//1

        int n = nums.size();
        int maxSum = sum + offset;          //ע���뿪�ٿռ������
        vector<vector<int>>dp(n + 1, vector<int>(maxSum + 1));
        //dp[n + 1][target] = 1;
        dp[n][target + offset] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = -offset; j <= offset; j++)
            {
                if (j + offset + nums[i] <= maxSum)//ע��ȡֵ��Χ,maxSum���ܹ�ȡ����
                {
                    //dp[i][j]=dp[i+1][j+nums[i]];
                    dp[i][j + offset] = dp[i + 1][j + offset + nums[i]];
                }
                if (j + offset - nums[i] >= 0)
                {
                    dp[i][j + offset] += dp[i + 1][j + offset - nums[i]];
                }
            }
        }
        return dp[0][offset];
    }
};
//���ܲ������Ҳ��ֵ,Ҳ������������ֵ,��ô�޷��ռ�ѹ��,��Ϊ���۴���ͷ��ʼ,���ᵼ����һ���ֵ������
//������Ҫʹ�ù�������洢��һ�е�����,Ȼ��Ѱ�������һ��
class Solution13_2
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for (int e : nums)
            sum += e;
        if (target<-sum || target>sum)
            return 0;
        int offset = sum;
        int n = nums.size();
        int maxSum = sum + offset;
        vector<int> dp(maxSum + 1);
        dp[target + offset] = 1;
        for (int i = n - 1; i >= 0; i--) 
        {
            vector<int> next(maxSum+ 1);
            for (int j = -offset; j <= offset; j++)
            {
                if (j + offset + nums[i] <= maxSum)
                {
                    next[j + offset] += dp[j + offset + nums[i]];
                }
                if (j + offset - nums[i] >= 0)
                {
                    next[j + offset] += dp[j + offset - nums[i]];
                }
            }
            dp = next;
        }
        return dp[offset];
    }
};


//�ⷨ4
// ��˼·��ת��Ϊ01��������
// ˼��1:
// ��Ȼ��Ŀ˵nums�ǷǸ����飬����ʹnums���и�������[3,-4,2]
// ��Ϊ����ÿ����ǰ����+����-��
// ����[3,-4,2]��ʵ��[3,4,2]����һ���Ľ��
// ���Լ�ʹnums���и�����Ҳ���԰Ѹ���ֱ�ӱ��������Ҳ����Ӱ����
// ˼��2:
// ���nums���ǷǸ������������������ۼӺ���sum
// ��ô���target>sum��������û���κη������Դﵽtarget������ֱ�ӷ���0
// ˼��3:
// nums�ڲ������飬������ô+��-�����յĽ����һ������ı���ż��
// ���ԣ�������������ۼӺ���sum��������target����ż�Բ�һ��
// ��ôû���κη������Դﵽtarget������ֱ�ӷ���0
// ˼��4(����Ҫ):
// ����˵����һ������, nums = [1, 2, 3, 4, 5] ���� target = 3
// ����һ�������� : +1 -2 +3 -4 +5 = 3
// �÷�����ȡ�����ļ���ΪA = {1��3��5}
// �÷�����ȡ�˸��ļ���ΪB = {2��4}
// �����κ�һ�ַ�������һ���� sum(A) - sum(B) = target
// ��������������һ�������ʽ�����������߶�����sum(A) + sum(B)����ô�ͻ������£�
// sum(A) - sum(B) + sum(A) + sum(B) = target + sum(A) + sum(B)
// 2 * sum(A) = target + �������������ۼӺ�
// sum(A) = (target + �������������ۼӺ�) / 2
// Ҳ����˵���κ�һ�����ϣ�ֻҪ�ۼӺ���(target + �������������ۼӺ�) / 2
// ��ô��һ����Ӧһ��target�ķ�ʽ
// ����Ǹ�����nums��target = 1, nums�������ۼӺ���11
// ���ж��ٷ������1����ʵ�������ж������Ӽ��ۼӺʹﵽ6�ķ�����(1+11)/2=6
// ��Ϊ���Ӽ��ۼӺ�6 - ��һ����Ӽ��ۼӺ�5 = 1��target)
// �����ж��ٸ��ۼӺ�Ϊ6�Ĳ�ͬ���ϣ��ʹ����ж��ٸ�target==1�ı��ʽ����
// �����Ѿ�ת��Ϊ01����������


class Solution14
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for (int n : nums)
            sum += n;
        if (sum < target || ((target & 1) ^ (sum & 1)) == 1)
            return 0;
        return func(nums, (target + sum) >> 1);
    }
    // ��Ǹ�����nums�ж��ٸ��������ۼӺ���t
    // 01��������(�Ӽ��ۼӺ��ϸ���t) + �ռ�ѹ��
    // dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
    int func(vector<int>& nums, int t)
    {
        if (t < 0)
            return 0;
        vector<int>dp(t + 1);
        dp[0] = 1;//���ٸ������е��ۼӺ���0,0�����ǿռ�,Ҳ��һ������,������д1
        for (int num : nums)
        {
            for (int j = t; j >= num; j--)//�����������,Ϊ�˱�����౻����,���Դ��Ҳ࿪ʼ����
            {
                dp[j] += dp[j - num];
            }
        }
        return dp[t];
    }
};