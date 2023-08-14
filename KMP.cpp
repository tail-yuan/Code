#include<iostream>
#include<vector>
using namespace std;

//��ȡ[0,i]������ǰ׺�ͺ�׺���ƥ�䳤��.��Χ: ǰ׺[0,i-1] ��׺[1,i]
//next[cn]����[0,cn]ǰ׺�ͺ�׺ƥ�������ַ�����next[cn]��,���ַ�����ǰ׺��ʾ����[0,next[cn]-1]
//��ô��һ���ַ�����next[cn],����������Ҫ�ĺ�pos-1λ��ƥ����±�,���¸�ֵcn=next[cn],ѭ������
//ʵ����ǰ���Ĺ���,������ǰѰ��ƥ��.ֱ�������һ��Ϊֹ��û�ɹ��Ļ�,next[pos]=0;����[0,pos]��û����!
//ƥ�����cn+1��,next[pos]=cn+1,ǰ׺�ͺ�׺��cn+1����ô���ַ�ƥ��
class KMP
{
public:
	//O(M)�õ�next����,M=matchStr.size()
	vector<int> getNextArr(string& matchStr)
	{
		if (matchStr.size() == 1)return {};
		vector<int> next(matchStr.size());
		next[0] = -1;
		next[1] = 0; //ǰ׺[0,i-1]=>[0,0],��׺Ϊ[1,i]=>[1,1],ǰ׺��׺ƥ�䳤��Ϊ0
		int pos = 2;
		int cn=0;
		while (pos < matchStr.size())
		{
			if (matchStr[cn] == matchStr[pos-1])
			{
				next[pos] = ++cn;
				pos++;
			}
			else if (cn > 0)
				cn = next[cn];
			else
			{
				next[pos] = 0;
				pos++;
			}
		}
	}
	//KMP����: ����matchStr��str�е���ʼλ��Index��T����ΪO(N) N>M
	int getIndexOfStr(string& str, string& matchStr)
	{
		if (str.size() == 0 || matchStr.size() == 0 || str.size() < matchStr.size())
			return -1;
		int si = 0, mi = 0;
		vector<int> nextArr = getNextArr(matchStr);//O(M)
		while (si < str.size() && mi < matchStr.size()) //O(N)
		{
			if (str[si] == matchStr[mi])
				si++, mi++;
			else if (nextArr[mi] != -1)//������ǰ����
				mi = nextArr[mi];
			else
				si++;
		}
		return mi == matchStr.size() ? si - mi : -1;
	}
	//����뱩�����,����forѭ��,i,j����֮������,����ÿ��ƥ�䵽s[j]λ��ʧ��ʱ,j���˵�i+1��λ��,mi���˵�0λ������ƥ��
	//Ѱ���� next[mi] �� s[j]ƥ��,���忴next��������.
	//����siһֱ���Ҳ���ͷO(N),matchStrһֱ�����Ʋ���ͷO(M),T=O(N)
	//����ֵ: ���ѭ������mi�������ƥ��ɹ�,��ͷλ�þ���si-mi,����˵��ûƥ��ɹ�
};