//https://leetcode.cn/problems/lemonade-change/
//5Ԫ�����úܴ�,̰�ĵĽǶȾ���������ѡ����,�����ܱ��������5Ԫ
//���û�����20Ԫʱ,����ѡ�񷵻�һ��10Ԫ,һ��5Ԫ,Ҳ����ѡ�񷵻�����5Ԫ,
//̰�ĵ�ѡ���һ�ַ�ʽ,�Դﵽ����ı���5Ԫ��Ŀ��

//����ֻ�漰��5Ԫ��10Ԫ,����ֻҪͳ��������ֽ�ҵĸ���
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0, ten = 0;
        //for (int& x : bills)//ʹ�÷�Χfor��Ч�ʺܵ�
        int n = bills.size();
        for (int i = 0; i < n; i++)
        {
            int x = bills[i];
            if (x == 5)
                five++;
            else if (x == 10)
            {
                if (five == 0)
                    return false;
                else
                {
                    ten++;
                    five--;
                }
            }
            else
            {
                if (ten && five)
                {
                    ten--, five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};