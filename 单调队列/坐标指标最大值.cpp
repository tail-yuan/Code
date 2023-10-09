//https://leetcode.cn/problems/max-value-of-equation/description/
// ������ x ��ֵ��С��������Ķ�ά��������άƽ�������ֵ
// yi + yj + |xi - xj| �����ֵ,Ҳ�����ҵ���������������ֵ,����Ҫ����������
// x�������ܳ���K
//
// ���ʽת��Ϊ yi + yj +xj-xi => xj+yj + yi- xi�����ֵ
// Ҳ���ǵ���һ����ʱyj+xjֵ��ȷ����С��,Ҫ�ҵ�֮ǰ������yi-xiֵ���ĵ�
//ʹ�õ�������,ά��һ���Ӵ�С�ĵ�����,Ȼ���ȡ��ͷԪ�غ��������ֵ.
//��key=yi-xiά��������,�Բ�����K�����ƶ�ͷ�Ĺ��ڲ���,������ͷ����
//���������ֵ,��֮ǰ�ĺ͸���,���õ�ָ��,���ұ�֮ǰ�����ֵ���ӽ�jλ��,���Կ��Ե�����β
//<index,yi-xi>
//��Ϊ������б�֤xֵ�Ǵ����������,������ȫ������xֵ�����indexΨһ��ʶ
//<x,y>
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    int MAXLEN = 100001;
public:
    int findMaxValueOfEquation(vector<vector<int>>& nums, int k)
    {
        int n = nums.size();
        vector<vector<int>>dq(MAXLEN,vector<int>(2));
        int h =0, t = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i][0];
            int y = nums[i][1];
            while (h < t && dq[h][0] + k < x)//��ʱ���x����
                h++;
            if (h < t)
                ans = max(ans, x+y+dq[h][1]-dq[h][0]);
            while (h < t && dq[t-1][1]-dq[t - 1][0] <= y-x)
                t--;
            dq[t][0] = x;
            dq[t][1] = y;
            t++;
        }
        return ans;
    }
};