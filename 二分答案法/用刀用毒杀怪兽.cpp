//������ɱ����������޵ĳ�ʼѪ����һ������hp��
//����ÿһ�غϵ����Ͷ�ɱ����ֵcuts��poisons
//��i�غ�����õ�������������غϻ�ֱ����ʧcuts[i]��Ѫ�������к���Ч��
//��i�غ�����ö�ɱ����������غϲ�����ʧѪ��������֮��ÿ�غ϶���ʧpoisons[i]��Ѫ��
//������ѡ������ж�ɱЧ����
//��֮��Ļغ϶��������������cuts��poisons�����ȶ���n��������һ�����Խ���n�غ�
//ÿһ�غ���ֻ��ѡ�񵶿����߶�ɱ�е�һ������
//�������n���غ���û��ֱ��ɱ�����ޣ���ζ�����Ѿ��޷����µ��ж���
//���ǹ���������ж�Ч���Ļ�����ô������Ȼ�᲻ͣ��Ѫ��ֱ��Ѫ���ľ����ǻغ�����
//���� ���� ���ٻغϹ��޻�����
//���ݷ�Χ : 1 <= n <= 10^5; 1 <= hp <= 10^9; 1 <= cuts[i]��poisons[i] <= 10^9
//��ʵ���㷨������

//���ִ𰸷�
//���ٸ��غϹ��޻������з�Χ��,[1,hp+1],���ܵ�һ���Ϳ����˾�һ�غ�,��������Ѫ���ľ�����һ�غ�����,����ÿ�ص��˺�����1
//��ô����hp/1+1�غ�����.
//Ҫ�������Խ�ٵĻغ�������,Ҫ���Խ��.x�غϾ��ù�����,��Ȼx+1�غ�Ҳ����.
//func()һ����Ҫ����mid�غ���,��֤�ù��������ܲ��ܴ��.һ��������mid�غ�������,����غ�������
//���غ���mid-indexȷ��֮��,������غ�������ѡ��������ߵķ�ʽ,�ǵ�ɱ���Ƕ�ɱ.

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int getTurns(vector<int>&cuts,vector<int>&poision,int hp)
	{
		int l = 1, r = hp + 1;
		int ans = 0;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (func(cuts, poision,hp, mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		return ans;
	}
	bool func(vector<int>& cuts, vector<int>& posions, int hp, int limit)
	{
		int m = cuts.size();
		int n = min(m, limit);
		for (int i = 0, j = 1; i < n; i++, j++)
		{
			hp -= max((long long)cuts[i], (long long)(limit - j) * posions[i]);
			if (hp <= 0)
				return true;
		}
		return false;
	}
};