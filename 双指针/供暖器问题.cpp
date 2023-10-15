//https://leetcode.cn/problems/heaters/
//���ڣ�����λ��һ��ˮƽ���ϵķ��� houses �͹�ů�� heaters ��λ�ã�
// �����ҳ������ؿ��Ը������з��ݵ���С���Ȱ뾶��
//ע�⣺���й�ů�� heaters ����ѭ��İ뾶��׼�����ȵİ뾶Ҳһ��

//�ȶ����������������
//�������Ǹ���ů����ֵ,��������ж�,ѡ����Сֵ
//��¼���з���ѡ��֮������ֵ��Ϊ���Ȱ뾶,���ܱ�֤���еķ��ݶ��õ���ů
//https://www.bilibili.com/video/BV1V841167Rg?t=5122.1
//��ȵ�ʱ��һ��Ҫ������,̰��,��������ů����ͬһ��λ��ʱΪ�˱���rһֱͣ����һ��λ��(��Ϊ�ж�func���߼�����)
//funcֻ�ǱȽ�������ů�ھ���Զ�����бȽ�,���������ͬ,һ��Ҫ���¶�.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    //O(n*logn)->����,����ָ��ֱ������������ж�������,������O(N)
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        int j = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            while (!best(houses, heaters, i, j))//���i�ŷ���ѡ��j�Ź�ů��������õ�
                j++;
            ans = max(ans, abs(houses[i] - heaters[j]));

        }
        return ans;
    }
    bool best(vector<int>& houses, vector<int>& heaters, int i, int j)
    {
        return j == heaters.size() - 1 ||
            abs(houses[i] - heaters[j]) < abs(houses[i] - heaters[j + 1]);
        //��ȵ�ʱ�򷵻�false,Ҳ������һ��λ��
    }
};