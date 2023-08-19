#include<iostream>
using namespace std;
//https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/description/?envType=study-plan-v2&envId=coding-interviews
//��С������!!!!
//��Ϊ.��eE��γ���ʱӦ�õ����ж��Ƿ����,�����޷�ֱ��ʹ��find����,ֻ�ܲ��ñ��λ����ʽ�ж��Ƿ����ظ�����

class Solution
{
public:
    //1. ȥ���ַ������˵Ŀո�
    string RemoveSpace(string& s)
    {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < n && s[left] == ' ') left++;
        while (right >= 0 && s[right] == ' ') right--;
        return s.substr(left, right - left + 1);
    }
    bool isNumber(string s)
    {
        s = RemoveSpace(s);
        //2. ʹ�ñ��λ�ж��Ƿ������ַ��ظ�����
        int epos = -1;
        bool flag = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                if (epos == -1)//epos�����һ���Ϸ�λ��,˵��֮ǰ���ֹ�e
                    epos = i;
                else
                    return false;
            }
        }
        //3. ��������������
        if (epos == -1) return isDecimal(s) || isInt(s);

        string left = s.substr(0, epos-1 -0 +1);
        string right = s.substr(epos + 1);
        return (isInt(left) || isDecimal(left)) && isInt(right);
    }
    bool isInt(string& s)
    {
        //4. �ַ�����""ʱreturn false
        if (s.size() == 0) return false;

        int index = 0;
        if (s[0] == '+' || s[0] == '-')
            index++;

        //��ѯindex����β�Ƿ�������
        int i = index;
        int count = 0;
        //5. right���ֱ���������,����ֻ��һ�� +
        for (; i < s.size() && s[i] != ' '; i++)
        {
            if (!isdigit(s[i]))
                return false;
            count++;
        }
        //6. ��Ϊs[i]������Ϊ������֮���м��ַ�,��·����
        return i == s.size()&&count>0;
    }
    bool isDecimal(string& s)
    {
        if (s.size() == 0) return false;

        int index = 0;
        if (s[0] == '+' || s[0] == '-')
            index++;
        bool flag = false;
        //7. С����.���߶�����������
        int left = 0, right = 0;
        int i = index;
        for (; i < s.size() && s[i] != ' '; i++)
        {
            if (s[i] == '.')
            {
                if (!flag)
                    flag = true;
                else
                    return false;
            }
            else if (isdigit(s[i]))
            {
                if (!flag)left++;
                else right++;
            }
            else
                return false;
        }
        return flag && (left > 0 || right > 0) && i == s.size();
        //����֮����ֿ�Ҳ��false,i�����м�����
    }
};

//int main()
//{
//    Solution s;
//    string str1 = "2e0";
//    string str = "4e+";
//    cout<<s.isNumber(str);
//    return 0;
//}