#include<iostream>
#include<vector>
#include<string>
using namespace std;

//һ�����鴮�����硰283691235�����зָҪ��ֳ������ַ�Χ[3, 135]
//���磺28 3 6 9 12 3 5
//��ӡ���еĽ��

// dfs() ÿһ�����ֶ���Ϊͷ�����
// ������: ������: ������indexλ��ʱ,�����Ա�����index+1���ַ����.
// ��֦: �����ַ�Χ��֪,���ֵĴ�С���ᳬ����λ��,���Ե�ƴ�õ���path.size()==3ʱ�Ϳ��Է���
// ����: �ָ��ֳ�,ʹ���βο����ķ�ʽ,�ڷ��ص�ʱ����Զ���ɻָ��Ĳ���
// ����: ÿ�ε���һ���ڵ�,���ж����Ƿ��ڷ�Χ֮��,��path.size()==3ʱ�Ϳ���ֱ�ӷ���
class Solution
{
	vector<int> ret;
	int n;
	int low, high;
public:
	vector<int> getNums(string& str)
	{
		n = str.size();
		low = 3, high = 135;
		string path = "";
		dfs(str, path, 0);
		return ret;
	}
	void dfs(string& str, string path, int index)
	{
		if (path.size() > 3)return;
		//<=3�Ϳ����ж��Ƿ�������������
		if (path.size() >= 1)
		{
			int num = stoi(path);
			if (num >= low && num <= high)
				ret.push_back(num);
		}
		//path.size()<=3
		for (int i = index; i < n; i++)
		{
			dfs(str, path + str[i], i+1);
		}
	}
};
int main()
{
	Solution s;
	string str = "2836";
	vector<int>ret = s.getNums(str);
	for (auto e : ret)
		cout << e << " ";
}