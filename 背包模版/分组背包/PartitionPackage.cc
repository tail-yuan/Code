// ����һ������m��ʾ��������������n������ɹ���ѡ
// ÿ���������Լ������(��������)����ֵ(�������)�����(����)
// ͬһ�������Ʒֻ����ѡ1����������ѡ��Ʒ������ܺͲ��ܳ�����������
// ��ô��ѡ�����ܴﵽ��ֵ��󣬷������ļ�ֵ
// �������� : https://www.luogu.com.cn/problem/P1757

// dp[i][j]��ʾ��[1...i]����,ÿ��ֻ��ѡ��1����Ʒ,����������jʱ,�ܹ���ȡ��������ֵ
// i����Ų�������Ʒ���
// 1. i����Ʒһ������ѡ,dp[i][j]=dp[i-1][j]
// 2. i����Ʒѡ��,��ôѡ��һ����? ȫ��һ��,�õ�ѡ���ĸ��ܹ���ȡ���������
//  dp[i][j]=dp[i-1][j-a]+val[a]
// ʱ�临�Ӷ�: ��ĸ���*(��1+��2+��3+...)����Ʒ�ܸ���

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class PartitionedKnapsack
{
    vector<vector<int>> arr;
    int n, m; // m����������,n������Ʒ�ĸ���
private:
    void init()
    {
        // arr[i][0] i����Ʒ�����
        // arr[i][1] i����Ʒ�ļ�ֵ
        // arr[i][2] i����Ʒ�����
        arr = vector<vector<int>>(n + 1, vector<int>(3));
    }
    struct Compare
    {
        bool operator()(vector<int> &a1, vector<int> &a2)
        {
            return a1[2] < a2[2]; // ��������
        }
    };
    // �ϸ�λ������,��άdp����
    int func1()
    {
        // 1. ��������,��Ϊdp[i][j]����ľ���[1...i]����ѡ��
        int teams = 1; // ע���ʼ��һ����1,����ԭ�������Ĳ��Ծ���
        for (int i = 2; i <= n; i++)
        {
            if (arr[i][2] != arr[i - 1][2])
                teams++;
        }
        // 2. dp������������
        vector<vector<int>> dp(teams + 1, vector<int>(m + 1));
        // dp[0][...]: ��0����ѡ��,Ҳ���ǲ�ѡ��,��ô�õ�������ֵ�϶�����0
        for (int i = 1, start = 1, end = 2; start <= n; i++)
        {
            // 2.1 ʹ��[start,end),����ʶ��ͬ����Ԫ�ؽ���ö������
            while (end <= n && arr[end][2] == arr[start][2])
                end++;
            for (int j = 0; j <= m; j++)
            {
                // 2.1.1 i����Ʒһ������ѡ
                dp[i][j] = dp[i - 1][j];
                // 2.1.2 i����Ʒ��Ҫѡ��,�涨ֻ��ѡһ��,��ô����ѡ���ĸ���Ʒ��ȡ�ļ�ֵ���? ö��һ��
                for (int k = start; k < end; k++)
                {
                    if (j - arr[k][0] >= 0)
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[k][0]] + arr[k][1]);
                }
            }
            start = end;
            end++;
        }
        return dp[teams][m];
    }
    //�ռ�ѹ���汾,��Ϊ�������������,����Ϊ�˱���������ݱ�����,���Դ���������и���
    int func()
    {
        // ��Ϊ���ٶ�������,��������ĸ�����û�б�Ҫ��
        vector<int> dp(m + 1);
        for (int start = 1, end = 2; start <= n;)
        {
            while (end <= n && arr[end][2] == arr[start][2])
                end++;
            for (int j = m; j >= 0; j--)
            {
                for (int k = start; k < end; k++)
                {
                    if (j - arr[k][0] >= 0)
                        dp[j] = max(dp[j], dp[j - arr[k][0]] + arr[k][1]);
                }
            }
            start = end;
            end++;
        }
        return dp[m];
    }

public:
    int Main()
    {
        cin >> m >> n;
        init();
        for (int i = 1; i <= n; i++)
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        sort(arr.begin(), arr.end(), Compare()); // ������Ž��д�С��������,����һ����ŵĶ�����һ����
        return func();
    }
};

int main()
{
    PartitionedKnapsack p;
    cout << p.Main() << endl;
    return 0;
}