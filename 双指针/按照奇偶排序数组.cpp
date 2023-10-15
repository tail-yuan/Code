#include<iostream>
#include<vector>
using namespace std;
//����һ���Ǹ��������� nums��  nums ��һ�������� ���� ��һ�������� ż�� ��
//��������������Ա㵱 nums[i] Ϊ����ʱ��i Ҳ�� ���� ���� nums[i] Ϊż��ʱ�� i Ҳ�� ż�� ��
//����Է��� �κ���������������������Ϊ�� ��
//Ҳ�����������������±�λ��,ż������ż���±�λ��.

//ʹ��˫ָ��,even���ż���±�,odd��������±�,�������һλ��x = nums[n-1],
//if x������,�ͺ�odd��ǵ����ֽ��н���,else ��even��ǵ����ֽ���,
//����֮�󽫶�Ӧָ��������һ����(ż)���±�λ��,ֱ������һ�������߽�,������(ż)���Ѿ��������
class Solution1
{
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int n = nums.size();
        int even = 0, odd = 1;
        while (even < n && odd < n)
        {
            if ((nums[n - 1] & 1) == 1)
            {
                swap(nums[odd], nums[n - 1]);
                odd += 2;
            }
            else
            {
                swap(nums[even], nums[n - 1]);
                even += 2;
            }
        }
        return nums;
    }
};