//https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/

//Ҫ���Ӵ���ÿһ���ַ����ֵĴ�����>=k,�����Ӵ��ĳ���
//���ڱ����Ż�Ϊ��������
//      �����Դ���������?�������涨��,��[l,r]��Χ�����ҵ�require��,Ȼ����������С,������.ʵ�ֵ�����
// û�е�����,�������ഴ�쵥����ȥ��.
// 
//�ṩ����ʵ��,�Ӵ��б���ֻ����i���ַ�,ÿ���ַ�����>=k,��Ƕ೤,(1<=i<=26)
//��ôÿ��Ҫ����ַ�������require��,ÿ�ֱ������>=k��,
// ��Ƶͳ������cnts[26]={0}
//��ô�ڹ�������Ҫ��������,collect: ͳ���Ѿ����ֵ��ַ�����,count�Ƕ�Ӧ���ִ���; 
// satisfy: ͳ�Ƴ��ִ����Ѿ�>=k���ַ��������. count==K ʱ,satisfy++
//r++,��satisfy==requireʱ,˵����ʱrequire���ַ���������k��,��¼��ʱ��ans,
//��������Ĺ�����,����safisfy��Ȼ���仯,���ǳ��ȱ䳤��,ans��������,while
//�����rλ��֮��,����collect>require��,��߽�left++,ֱ����collect==require����.while
//Ȼ����������µ������ַ����,��������>=k�������
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.size();
        int ans = 0;
        for (int require = 1; require <= 26; require++)
        {
            int cnts[256] = { 0 };
            int collect = 0, satisfy = 0;
            for (int l = 0, r = 0; r < n; r++)
            {
                cnts[s[r]]++;
                if (cnts[s[r]] == 1)
                    collect++;
                if (cnts[s[r]] == k)
                    satisfy++;
                //���೬��
                while (collect > require)
                {
                    //--֮ǰ
                    if (cnts[s[l]] == 1)
                        collect--;
                    if (cnts[s[l]] == k)
                        satisfy--;
                    cnts[s[l]]--;
                    l++;
                }
                //����û��,ֱ�Ӹ���
                if (satisfy == require)
                    ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};