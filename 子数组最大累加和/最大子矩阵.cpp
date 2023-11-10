//https://leetcode.cn/problems/max-submatrix-lcci/description/
//https://www.bilibili.com/video/BV1pw411M7Du?t=4607.2

//ѹ������ķ�ʽ,
//�������0~0������,�ںϲ�֮���һά������ѡ��������������鼴��
//       0~1
//      ...
//       0~n-1
//       1~1
//       ...
//       1~n-1
//...
//����ѹ����������¼���ֵ
//ö�ٵĹ��̾���O(n^2)
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	vector<int> getMaxMatrix(vector<vector<int>>& matrix)
	{
		int n = matrix.size();
		int m = matrix[0].size();
		int maxVal = INT_MIN;
		int a = 0, b = 0, c = 0, d = 0;
		for (int up = 0; up < n; up++)
		{
			vector<int>nums(m);
			for (int down = up; down < n; down++)
			{
				int prev = INT_MIN;
				for (int l = 0, r = 0; r < m; r++)
				{
					nums[r] += matrix[down][r];
					if (prev < 0)
					{
						prev = nums[r];
						l = r;
					}
					else
						prev += nums[r];
					if (prev > maxVal)
					{
						maxVal = prev;
						a = up;
						b = l;
						c = down;
						d = r;
					}
				}
			}
		}
		return { a,b,c,d };
	}
};