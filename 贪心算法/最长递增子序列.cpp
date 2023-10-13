
//https://leetcode.cn/problems/longest-increasing-subsequence/description/
//�����������
//�ⷨһ: ʹ��dp�ķ�ʽ
// dp[i]������iλ��Ϊ��βʱ����������еĳ���
// dp[i]=max(dp[i],dp[j]+1) j����[0,i-1]λ��
// ��ʼ��ʱ����1
class Solution9 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n, 1);
        int ret = 1;//����������ʵ��ʼ��Ϊ1
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
//�ⷨ��: ���ֲ��ҵķ�ʽ
//----ֻ�ܰѵ���С����ѹ����������������ϣ�
//�����ǰ�Ƶ����ϴ�û�п��Է��õĶѣ����½�һ���ѣ��������ƷŽ�ȥ��
//�����ǰ���ж���ѿɹ�ѡ����ѡ������ߵ���һ�ѷ��á�
//���,�ж��ٸ���,��������о��Ƕ��ٳ���
//��ô�ڱ�����indexλ��,��������ַŵ��ĸ����Ͼ��漰�����ֲ���
#include<iostream>
#include<vector>
using namespace std;
class Solution1
{
public:
    //����ʱ���仮��Ϊtop[mid] < >= poker,>=���������,���ҵ�������������߽�
    int lengthOfLIS1(vector<int>& nums) 
    {
        int piles = 0;
        int n = nums.size();
        vector<int>top(n);//��¼����ÿһ����������һ���Ԫ��
        for (int i = 0; i < n; i++)
        {
            int poker = nums[i];
            int left = 0, right = piles;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (top[mid] >= poker)
                    right = mid;
                else left = mid + 1;
            }
            if (left == piles)
                piles++;
            top[left] = poker;
        }
        return piles;
    }
    int lengthOfLIS(vector<int>& nums)
    {
        int piles = 0;
        int n = nums.size();
        vector<int>top(n);
        for (int i = 0; i < n; i++)
        {
            int poker = nums[i];
            int left = 0, right = piles;
            int index = piles;//���û�в��ҵ�����λ��,Ҳ����һֱû����������.��ʼ����������
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (top[mid] >= poker)
                {
                    index = mid;
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            if (index == piles)
                piles++;
            top[index] = poker;
        }
        return piles;
    }
};
//�ⷨ��:
// ̰�Ľⷨ
//dpʱ����ֻ�ÿ���i��ǰһ��λ����˭,Ҳ����j����,����Ҫ�ٿ���j֮ǰ��Ԫ����ʲô.
//���ֵ�ʱ����Ϊ���Ǽ�¼��һ��top����,top[index]ֻ��¼�����������Сֵ,�������Ĵ���һ���м���
//̰���ǽ����������,
//��Ϊ���γɵ���������,0λ��ֱ����Ϊ����Ϊ1 [len=1]�����һ��Ԫ��,
// if [index] < [len=1],****̰��1: ֱ���滻,[len=1] =[index],����len=x������Ԫ����Сֵ
// ������ֵ����ּ�Ȼ�ܹ��ŵ���С��������,�϶��Ǹ��õ�.��������ȷ��,������֤��.
// else if [index]>[len=1],�����Լ��γ���һ��һ������Ϊ1��������,Ҳ��������֮ǰ�ĺ���,
// ˵���ǿ��Է���len=1�������еĺ���,�γɳ���Ϊ2��������,
// ****̰��2: ����ѡ����,����֮ǰ���Ǹ������еĺ���,�γɸ�����������,��Ϊ��Ҫ�ľ��ǳ��ȸ���,
// ��ô���һ��Ԫ�ؾ���[len=2]=[index]
// ...,�γɳ���Ϊ3,4,5��������,��󷵻�[len]����.
// ��top����ֳɼ�����һ����,����ƴ�ӵ����в������Ǹ����,ֻ�ǳ���ȷʵ����ͬ��.
//ʹ�������¼len=indexʱ����Сֵ,��������Ϊ�����������ǵ�����,(�����γɹ��� ֱ��֤����)
// ���Կ���ʹ�ö����Ż�,���ҵ���>=������߽�
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ret;
        ret.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ret.back())//������,�Ǿ�ѡ������������,�γ�len+1��������,��β����nums[i]
                ret.push_back(nums[i]);
            else//����С,������
            {
                int left = 0, right = ret.size() - 1;//-1 or not������ν
                while (left < right)
                {
                    int mid = (left + right) / 2;
                    if (ret[mid] < nums[i])left = mid + 1;
                    else right = mid;
                }
                ret[left] = nums[i];
            }
        }
        return ret.size();
    }
};
//int main()
//{
//    vector<int>arr{ 10,9,2,5,3,7,101,18 };
//    Solution1 s;
//    cout<<s.lengthOfLIS(arr);
//}