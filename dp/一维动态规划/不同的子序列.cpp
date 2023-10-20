//https://www.bilibili.com/video/BV1Ww41167Ac?t=11929.0
//��һ�ű�,�ֱ��¼ÿ���ַ�Ϊ��β�������м��ϵĸ���
//����iλ��,��֮ǰ���ֹ��������к������iλ���ַ�,
//�����������и��� = all -��ǰ�ַ��ϴμ�¼
//Ȼ��,��ǰ�ַ���¼+=������
//	 ,all+=������
//https://leetcode.cn/problems/distinct-subsequences-ii/description/
//cnts[i]������iλ�� �ַ� Ϊ��β�Ĳ�ͬ�����еĸ���
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int distinctSubseqII(string s)
    {
        int mod = 1000000007;
        vector<int>cnts(26);
        int all = 1;//�ռ�����һ��
        int newAdd = 0;
        for (char x : s)
        {
            newAdd = (all - cnts[x - 'a'] + mod) % mod;
            cnts[x - 'a'] = (cnts[x - 'a'] + newAdd) % mod;
            all = (all + newAdd) % mod;
        }
        return (all - 1 + mod) % mod;
    }
};