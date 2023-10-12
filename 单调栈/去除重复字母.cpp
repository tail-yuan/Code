//����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ�Ρ�
//�豣֤ ���ؽ�����ֵ�����С��Ҫ���ܴ��������ַ������λ�ã���
//https://leetcode.cn/problems/remove-duplicate-letters/description/

//������indexλ���ַ��Ƿ�ɾ��ʱ,Ӧ�ÿ��Ǻ��滹�м�������ַ�,�������,��ô�ҷ���ɾ��,
//���û����,ֻ��Ӳ��ͷƤ����,���Կ��ǵ���Ƶͳ��.
//��֤�ֵ�����С,����Ӧ���Ǵ�ѹС,���ջ�е���Ԫ�����򼴿�
//����ά��ʱ,��ѹС+�ַ���Ƶ ͳһ����
//���ظ��ַ�����ʱ,����ջ���Ƿ��Ѿ�����,���û�о�ѹ��,������˾�ֱ������.
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int N = 26;
        vector<int>cnts(N);
        vector<bool>visi(N, false);
        vector<char>st(N);
        //��Ƶͳ��
        for (char ch : s)
            cnts[ch - 'a']++;
        int r = 0;
        for (char ch:s)
        {
            if (!visi[ch - 'a'])//ջ��û������ַ�
            {
                while (r > 0 && st[r - 1] > ch && cnts[st[r-1] - 'a'])
                {
                    visi[st[r - 1] - 'a'] = false;
                    r--;
                }
                st[r++] = ch;
                visi[ch - 'a'] = true;
            }
            cnts[ch - 'a']--;
        }
        string ret = "";
        for (int i = 0; i < r; i++)
            ret += st[i];
        return ret;
    }
};