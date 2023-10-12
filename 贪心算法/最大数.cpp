//https://leetcode.cn/problems/largest-number/
//����һ��Ǹ����� nums����������ÿ������˳��ÿ�������ɲ�֣�ʹ֮���һ������������
//ע�⣺���������ܷǳ�����������Ҫ����һ���ַ���������������

//������ת��Ϊ�ַ���,Ȼ�����ֵ����������,Ȼ��ֱ����������
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
class Solution
{
    struct Less
    {
        bool operator()( const string& s1,  const string& s2)
        {
            return s1+s2 < s2+s1;
        }
    };
public:
    string largestNumber(vector<int>& nums)
    {
        priority_queue<string, vector<string>, Less>heap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            heap.push(to_string(nums[i]));
        }
        string ret = "";
        while (!heap.empty())
        {
            ret += heap.top();
            heap.pop();
        }
        //����0ֵ,���½����"00"
        int i = 0;
        while (i < ret.size() && ret[i] == '0') 
            i++;

        return (i == ret.size()) ? "0" : ret.substr(i);
    }
};
int main()
{
    Solution s;
    vector<int>arr{ 3,30,34,5,9 };
    cout << s.largestNumber(arr) << endl;
    return 0;
}