//https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb
#include <iostream>
#include<vector>
using namespace std;
//vector�ײ�ʹ�õľ���new,�����ڶ�������ռ�,���ÿ���ջ�������.
//���Ը��������Լ�new,Ч����һ����.
//Ч����cout << printf(),��������cout��ȫ������
void func(vector<int>&arr)
{
	int n = arr.size();
	vector<int>st = vector<int>(n);
	vector<vector<int>>ans = vector<vector<int>>(n, vector<int>(2));
	int r = 0;
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		while (r > 0 && arr[st[r - 1]] >= arr[i])
		{
			cur = st[--r];
			ans[cur][0] = r > 0 ? st[r - 1] : -1;
			ans[cur][1] = i;
		}
		st[r++] = i;
	}
	while (r > 0)
	{
		cur = st[--r];
		ans[cur][0] = r > 0 ? st[r - 1] : -1;
		ans[cur][1] = -1;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if (ans[i][1] != -1 && arr[i] == arr[ans[i][1]])
			ans[i][1] = ans[ans[i][1]][1];
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n",ans[i][0],ans[i][1]);
		//cout << ans[i][0] << " " << ans[i][1] << endl;ʱ��̫��,���ǵ���printf()
	}
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	func(arr);
	return 0;
}


//class Solution
//{
//    static const int MAXN = 1000001;
//    int* st;
//    int** ans;
//    int n;
//public:
//    Solution()
//    {
//        st = new int[MAXN];
//        ans = new int* [MAXN];
//        for (int i = 0; i < MAXN; i++)
//            ans[i] = new int[2];
//        for (int i = 0; i < MAXN; i++)
//        {
//            st[i] = 0;
//            for (int j = 0; j < 2; j++)
//                ans[i][j] = 0;
//        }
//    }
//    ~Solution()
//    {
//        delete[] st;
//        for (int i = 0; i < MAXN; i++)
//            delete[] ans[i];
//    }
//public:
//    void func(vector<int>&arr)
//    {
//        n = arr.size();
//        int r = 0;
//        int cur = 0;
//        for (int i = 0; i < n; i++)
//        {
//            //��Ҫ����ջ��
//            while (r > 0 && arr[st[r - 1]] >= arr[i])
//            {
//                cur = st[--r];
//                ans[cur][0] = r > 0 ? st[r - 1] : -1;
//                ans[cur][1] = i;
//            }
//            st[r++] = i;
//        }
//        //st�п���ʣ��Ԫ��,�������㻷��
//        while (r>0)
//        {
//            cur = st[--r];
//            ans[cur][1] = -1;
//            ans[cur][0] = r > 0 ? st[r - 1] : -1;
//        }
//        //��������,��Ϊ�Ǵ������ҽ���,������������Сֵһ������ȷ��,
//        //��������ظ�ֵ��ɴ���,Ҳ���Ҳ��������,������ֺ��Լ����,��ֱ�ӵ������Ĵ𰸼���
//        //ע����Ҫ�Ӻ���ǰ������������
//        for (int i = n - 2; i >= 0; i--)
//        {
//            if (ans[i][1] != -1 && arr[ans[i][1]] == arr[i])
//                ans[i][1] = ans[ans[i][1]][1];
//        }
//    }
//public:
//    void print()
//    {
//        for (int i = 0; i < n; i++)
//        {
//            cout << ans[i][0] << " " << ans[i][1] << endl;
//        }
//    }
//};
//int main()
//{
//    int n = 0;
//    cin >> n;
//    Solution s;
//    vector<int>arr(n);
//    for (int i = 0; i < n; i++)
//        cin >> arr[i];
//    s.func(arr);
//    s.print();
//}