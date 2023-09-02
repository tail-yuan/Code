//��������: �����Դ�����ֻҪr++,��ô���ȿ϶��Ǳ䳤��,�ڲ������ظ�ʱ��С��Χ.
// ��ÿһ��λ��Ϊ��β����
//��¼ÿһ���ַ��ϴγ��ֵ�λ��last[256]=-1
//��߽�������max(last[[i]]+1,��ʱ������߽�)
//ʱ�̸���last[x]x�ַ���һ�γ��ֵ�λ��
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string str)
    {
        int n = str.size();
        vector<int>last(256,-1);
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++)
        {
            l = max(last[str[r]] + 1, l);
            ans = max(ans, r - l + 1);
            last[str[r]] = r;
        }
        return ans;
    }
};