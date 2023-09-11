
//����: ��Χ����˺��е��ַ�����ֻ���ܱ��,�������ֵ�����,���Կ����û�������
//ʹ�ù�ϣ��ͳ���ַ������ʹ�Ƶ

#include<iostream>
#include<unordered_map>
using namespace std;
class Solution
{
public:
	int lengthOfLongestSubstringKDistinct(string s, int k)
	{
		if (s.size() == 0 || k < 1)return 0;

		int l = 0, r = 0;
		unordered_map<char, int>hashMap;
		int ans = 1;
		while (r < s.size())
		{
			if (hashMap.size() <= k)
			{
				hashMap[s[r]]++;
				r++;
			}
			else//��ʱr�������ַ�����> kλ��,
			{
				int len = r - l;
				ans = max(ans, len);
				//���󴰿�ֱ���ַ�����<=k,
				while (hashMap.size() > k)
					hashMap[s[l++]]--;
				r++;
			}
		}
		return ans;
	}
};