//https://leetcode.cn/problems/replace-the-substring-for-balanced-string/description/
//��Χ�����Է���:
//�����[l,r]�������ܹ�ͨ�����Ĵﵽƽ��,��ô��[left,right]����������Ͽ϶�Ҳ��ͨ���޸Ĵﵽƽ��
//����ok����[l,r]��Χ,�����ܷ��������Χ�����ַ���ƽ��
//�����[l,r]�Ͽ���ƽ��,��ô����minLen=r-l+1.��ô[l,r+1,r+2]�϶�Ҳ������,���Ժ���û�б�Ҫ������
//��ʱl++,�ٽ����ж�.Ϊʲôr���Բ��û���? ��Ϊ��[l,r]������ô���������ܴ�ɵ�һ��,��ô��С������϶���������.
//����rû�л��˵ı�Ҫ,ֱ������[l+1,r]�ܲ�����
// 
//OK����������?
//ֻ���޸�[l,r]��Χ�ڵ��ַ�,���賤��Ϊlen,��ôҪ��ÿ���ַ����ֵĴ�����len/4,
//�����[l,r]����֮�������λ���Ϸ����е��ַ����ִ���>len/4,��ô˵��ֻ�޸�[l,r]��Χ���ַ�����������
//[l,r]�����ܹ��޸ĵĸ�����x=r-l+1,������Ҫͨ���޸�[l ,r]�����ڵ��ַ�,��ÿ�ִ�Ƶ����require = len/4,
//��[l,r]������,ÿ���ַ�ȱ���ٵ���len/4,���������в�����,�����ַ���Ҫ���ۼ���һ��sum,
//if sum==x˵���ܹ��޸ĳɹ�,��[l,r]�������֧��ĳ���ȥ��ÿ���ַ�ȱ���ٵ���ƽ��ֵ.
//
//�������Ϊ[l,r)
//Ŀǰ���ڳ���̫С������,���ǻ���Ŭ���Ŀռ�,����������.
//cntsͳ�Ƶ���[l,r)����֮��Ĵ�Ƶ,��l=0,r=0������û��ʱ,��������Ĵ�Ƶͳ��
//��l++������,��Ϊcntsͳ�Ƶ���[l,r]֮��Ĵ�Ƶ,����l++֮ǰҪ��cntsͳ�Ƶ�lΪֹ,����cnts[str[l]]++
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    //Q W E R
    //0 1 2 3 ���ת��arr,arr[i]����ľ��Ǵ�Ƶ
    int balancedString(string s)
    {
        vector<int>arr(s.size());
        vector<int>cnts(4,0);
        int i = 0;
        for (int j=0;j<s.size();j++)
        {
            if (s[j] == 'Q') i = 0;
            else if (s[j] == 'W') i = 1;
            else if (s[j] == 'E')i = 2;
            else i = 3;
            arr[j] = i;
            cnts[arr[j]]++;
        }
        int n = s.size();
        int require = n / 4;
        int ans = n;//�����޸����䳤�Ⱦ���������,���޸�һ��
        for (int l = 0, r = 0; l < n; l++)
        {
            while (!ok(cnts, r - l, require) && r < n)
                cnts[arr[r]]--,r++;
            if (ok(cnts, r - l, require))
                ans = min(ans, r - l);
            cnts[arr[l]]++;
        }
        return ans;
    }
    bool ok(vector<int>& cnts, int len, int require)
    {
        for (int i = 0; i < 4; i++)
        {
            if (cnts[i] > require)
                return false;
            len -= require - cnts[i];
        }
        return len == 0;
    }
};