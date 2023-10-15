//https://leetcode.cn/problems/boats-to-save-people/description/
//������񶼲�Ӱ����,�������Ÿ���
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(), people.end());
        int ans = 0;
        int n = people.size();
        int l = 0, r = n - 1;
        int sum = 0;
        while (l <= r)
        {
            sum = l == r ? people[l] : people[l] + people[r];
            if (sum > limit)
            {
                r--;
            }
            else
            {
                l++;
                r--;
            }
            ans++;
        }
        return ans;
    }
};
//��������: �����������һ����,���غͱ�����ż��
//ֻ������������һ��,ż��ż��һ��,������ż������ֳ���,Ȼ�������������Ӽ���.