#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	pair<int,int> getMaxCount(vector<int>& arr)
	{
		int n = arr.size();
		int cur = arr[0], count = 1;
		for (int i = 1; i < arr.size(); i++)
		{
			if (cur == arr[i])
				count++;
			else if (cur > arr[i])
				continue;
			else if (cur < arr[i])
			{
				cur = arr[i];
				count = 1;
			}
		}
		return { cur,count };
	}
};

int main()
{
	Solution s;
	vector<int> ret ={2, 2, 1, 3, 2, 3, 1};
	auto ans= s.getMaxCount(ret);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}