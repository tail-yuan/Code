//https://leetcode.cn/problems/minimum-window-substring/description/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
//�����������ÿ��λ�ÿ�ͷ���߽�βʱ�Ĵ�
//�������ڵĹؼ�: ���ҷ�Χ�ʹ�ָ��֮��ĵ����Թ�ϵ
//������: ��ΧԽ��,Խ���װ���t�Ӵ�.s�����䷶Χ,������Խ����,Խ�����ҵ���,������Խ����,Խ�������ҵ���.
// 
//����S�а���t�ַ��������ٸ����Ӵ�.t��S���ַ����ֵ�˳���������,���ǵö���.
//�ڹ����м�¼��ͷ�ͳ���,����ȡ���ؼ���.
//Ҳ�ǻ�������,ֻ��������ж���l++,
//��Ϊ����˳��,����ֻ��Ҫ�й̶��ַ�����ô�������.
//ʹ�õ���������,tmp��¼ÿ���ַ�Ӧ�ó��ֵĸ���,��ΪǷծ��,debt��¼�����ܸ�������ծ
//Ȼ���ڴ�����"��ծ"
//[i]��iλ��Ϊ��β��ǰ��С�Ļ�ծ����,��ծ����0ʱ,�����ڲ�Ƿծ���������С��߽�,left++
//��¼���Ⱥ���ʼλ��
//�ڱ���s������,�϶������t��û�е�,��ô�ͽ�ծ����������ֵĴ���++,�϶�������,����С��߽�ʱ>0��������³�
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";
        int tmp[256] = {0};
        for (auto e : t)
            tmp[e]--;

        int len = INT_MAX;//��¼��С�����Ӵ�
        int start = 0;
        int debt = t.size();
        for (int l = 0, r = 0; r < s.size(); r++)
        {
            if (tmp[s[r]]++ < 0)
                debt--; 
            if (debt == 0)
            {
                //���Ծ�����С��߽�
                while (tmp[s[l]] > 0)
                    tmp[s[l++]]--;
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    start = l;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
