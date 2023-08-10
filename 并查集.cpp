#include<vector>
using namespace std;
////���鼯
//��ʼÿ��Ԫ�ض��Ƕ�����Element<>,����Union������,��Bָ��A,A��ΪB�ĸ���Ԫ��,��Cָ��D
// A��Ϊ�Լ���B�Ĵ���Ԫ��,D��Ϊ�Լ���C��,��ΪAB��CD�Ĵ���Ԫ�ز�ͬ,������Ϊ���߲���ͬһ����
//Union A Cʱ,��sizeС�ļ��ϵĴ���Ԫ��Cָ��A,��ʱA�����ĸ��Ĵ���Ԫ��,��ͬһ������
//���ܻ����������Ȼ���������⵼��O()����O(1)
//��ô�Ż�:ĳһԪ��x�����Ҵ���Ԫ��ʱ,���������ҹ����������ĵĸ��׵�parentָ��,����ΪA(����Ԫ��)
//ʹ�ø��ӱ��,Ч�ʸ���.
//��ƽ=>O(1) �������findHead�����ƽ�N,���߳���N��ʱ.
//ʹ������ķ�ʽʵ�ֲ��鼯
class UnionFindSet
{
public:
	UnionFindSet(int size)
		:ufSet(size, -1)
	{}
	size_t FindRoot(int x)
	{
		while (ufSet[x] > 0)
			x = ufSet[x];
		return x;
	}
	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 != root2)
		{
			ufSet[root1] += ufSet[root2];
			ufSet[root2] = root1;
		}
	}
	size_t getCount()
	{
		size_t count = 0;
		for (size_t i = 0; i < ufSet.size(); i++)
		{
			if (ufSet[i] < 0) count++;
		}
		return count;
	}
private:
	std::vector<int> ufSet;
};

void TestUFS()
{
	UnionFindSet u(10);

	u.Union(0, 6);
	u.Union(7, 6);
	u.Union(7, 8);

	u.Union(1, 4);
	u.Union(4, 9);

	u.Union(2, 3);
	u.Union(2, 5);
	printf("%d\n", u.getCount());
}
//int main()
//{
//	TestUFS();
//	return 0;
//}