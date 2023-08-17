#include<iostream>
#include<vector>
using namespace std;
//���鼯�Ľ���:
//1. ������±��Ӧ������Ԫ�صı��
//2. ���������Ϊ���������Ŵ���������ִ���ü�����Ԫ�ظ���
//3. ���������Ϊ�Ǹ����������Ԫ��˫���������е��±�

//���鼯һ����Խ��һ�����⣺
//1. ����Ԫ�������ĸ�����: ���������ʾ���ι�ϵ����һֱ�ҵ���(����������Ԫ��Ϊ������λ��)
//2. �鿴����Ԫ���Ƿ�����ͬһ������: 
//		���������ʾ�����ι�ϵ����һֱ�ҵ����ĸ����������ͬ������ͬһ�����ϣ�������
//3. ���������Ϲ鲢��һ������,�����������е�Ԫ�غϲ�,��һ���������Ƹĳ���һ�����ϵ�����
//4. ���ϵĸ���.�������飬������Ԫ��Ϊ�����ĸ�����Ϊ���ϵĸ�����

class UnionFind
{
private:
	vector<int> ufs;
public:
	//1. �����ṩ������������Ԫ��֮��Ĺ�ϵ��!
	UnionFind(int n)
		:ufs(n, -1)
	{}
	int FindRoot(int index)
	{
		//��ǰ�ҵĹ����з��ֻ�û������,Ҳ����˵����û����
		while (ufs[index]>=0)
			index = ufs[index];
		return index;
	}
	//���ϵĹ���ֻ��Ҫ�����ϵ�ͷָ����һ�����ϵ�ͷ����,ע����Ŀ���ۼ���
	bool Union(int x1,int x2)
	{
		//1. ����ͷ
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		//2. �����һ�ҵ�,�Ͳ��úϲ�
		if (root1 == root2)
			return false;
		//3. ����һ�ҵ�,����root2���ϸ����ۼӵ�root1��,Ȼ����root2ָ��root1
		ufs[root1] += ufs[root2];
		ufs[root2] = root1;
		return true;
	}
	int Count()
	{
		int count = 0;
		for (int i = 0; i < ufs.size(); i++)
			if (ufs[i] < 0)
				count++;
		return count;
	}
	bool IsOneSet(int x, int y)
	{
		return FindRoot(x) == FindRoot(y);
	}
};