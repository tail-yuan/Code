#include<iostream>
#include<vector>
using namespace std;

//Manacher�㷨��������ַ���������Ӵ��ĳ���,��ʱ�临�ӶȽ���O(N)\
// ��������ν�����Ĵ�iλ���������������뾶�Ĺ��̽��м���,ֱ��ȷ��ֵ.
//1. ������������ַ�.���ż�������м�����,���²��Ҷ�ʧ���������
//2. ���pArr����,pArr[i]��¼��iΪ���Ļ��ĵ����뾶ֵ
//3. ʱ�̸���pR(����չ���ұߵ����ұ߽�)�Լ�����index
//����pArr����ʱ,pR�����������λ��,pR-1�����Ѿ�����������
//1. ���i>pR-1,������iΪ������������
//2. ���i<pR-1,����i�Ѿ�������,�͸��������������pArr[i]��ֵ
//	 ǰ����,i��indexΪ���ĶԳƵĵ�i',i'�뾶pArr[i']�;�����߾���(==i�����ұ߾���)pR-iȡ��Сֵ����������ֵĸ���,
//	 ʵ���Ż�.
//��������������ڿ�����Ŀ���,�����޷�ֱ��ȷ��ֵ,�����Լ�����.����������i'�Ļ���֮�Ͽ�ʼ����,pArr[i]
// ����ǰ����i'�趨��ֵ,ֻ������ʱ�Կ�����
//��������г��ָ��ӿ��ҵı߽�ʱ,Ҫ����pR,���ĵ�index
class Solution2
{
public:
	int isPalindrome(string& s)
	{
		if (s.size() == 0)return 0;
		string str = opt(s);
		int n = str.size();
		vector<int>pArr(n);
		int index = -1, pR = -1;
		int retMaxLen = 1;
		for (int i = 0; i < n; i++)
		{
			int i_ = 2 * index - i;
			pArr[i] = pR > i ? min(pArr[i_], pR - i) : 1;
			while (i + pArr[i] < n && i - pArr[i] >= 0)//��������������,����ע��߽�
			{
				if (str[i - pArr[i]] == str[i + pArr[i]])
					pArr[i]++;
				else
					break;
			}
			if (i + pArr[i] > pR)
			{
				pR = i + pArr[i];
				index = i;
			}
			retMaxLen = max(retMaxLen, pArr[i]);//����һ��pArr[i]�ͼ�¼���ֵ
		}
		return retMaxLen - 1;
	}
	string opt(string & str)
	{
		int n = str.size();
		string tmp;
		char gap = '#';
		int index = 0;
		for (int i = 0; i < 2 * n + 1; i++)
		{
			if ((i % 2) == 0)//ż��λ
				tmp.push_back(gap);
			else
				tmp.push_back(str[index++]);
		}
		//cout << tmp << endl;��������ַ�û����
		return tmp;
	}
};
int main()
{
	string str = "12345";
	Solution2 s;
	s.isPalindrome(str);
	return 0;
}





//�þ�������,��һ�Ŷ�ά���¼���������յ������������,Ȼ���ڱ��м�¼�
//dp[i][j]��ʾ�ַ���[i,j]�����Ƿ��ǻ����Ӵ�,
//1. s[i]==s[j],1. i==j һ���ַ�true 2. i+1==j �����ַ�true 3. i+1<j �ö��ַ�,��С����dp[i+1][j-1]
//2. s[i]!=s[j]�߽綼����ͬ�϶�����
//��ʼ��: ��ΪԼ���õ�i<j,����ֻ��Ҫ�������ά��,����i=i��б�ߴ����±����ֻ��һ���ַ�,true
//���˳��: i������i+1,j������j-1,���Դ�������,��������
//����ֵ: ��¼���ֵ,���Ա����߼�¼
class Solution1
{
public:
	int isPalindrome(string& str)
	{
		int n = (int)str.size();
		vector<vector<int>>dp(n, vector<int>(n));
		int ret = 1;
		int len = 1, begin = 0;//����Ⱥ���ʼλ��
		for (int i = n-1;i>=0; i--)
		{
			for (int j = i; j < n; j++)
			{
				if (str[i] == str[j])
					dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
				if (dp[i][j] && j - i + 1 > len)
					len = j - i + 1, begin = i;
			}
		}
		return len;
		//return str.substr(begin,len);����������Ӵ�
	}
};