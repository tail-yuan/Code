//https://leetcode.cn/problems/di-string-match/
//̰��: �����I,��ô�ͽ���С��ֵ��������,�����D����,�ͽ����ֵ�ŵ�����
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	vector<int> diStringMatch(string s)
	{
		int right = s.size(), left = 0;
		vector<int>ret;
		for (char ch : s)
		{
			if (ch == 'I')
				ret.push_back(left++);
			else
				ret.push_back(right--);
		}
		ret.push_back(left);
		return ret;
	}
};