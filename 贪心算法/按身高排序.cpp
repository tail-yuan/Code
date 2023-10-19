//https://leetcode.cn/problems/sort-the-people/submissions/475474672/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//һ.��ӳ���ϵ
//1. �����µ���Node,�ŵ������ṩ�ȽϹ���
//2. ��¼����ϣ����,�����������֮���ѯ��Ӧ����
//��.���±��������,ʹ����ߺ����ֵ�ӳ���ϵ���������仯,���޸�ԭ����
//1. �½��±�����index
//2. ����������д�ȽϷ���
class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int n = names.size();
        vector<int>index(n);
        for (int i = 0; i < n; i++)
            index[i] = i;
        sort(index.begin(), index.end(), [&heights](int i,int j)->bool{
            return heights[i] > heights[j];
        });
        vector<string>ret;
        for (int i = 0; i < n; i++)
        {
            ret.push_back(names[index[i]]);
        }
        return ret;
    }
};