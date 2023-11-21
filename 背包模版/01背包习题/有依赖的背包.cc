//https://www.nowcoder.com/discuss/556481400451379200
//https://www.luogu.com.cn/problem/P1064#submit
//
// 1. �������Ʒ�����������͸���,���򸽼�֮ǰ�����ȹ�������.
// 2. ÿ���������Դ�0~2������,ÿ�����������Լ����������������и���
// 3. ÿ����Ʒ����������,�۸�vi,pi(��Ҫ��),qi(�������)
//  if qi==0,�����������Լ�������Ҳ�����Ǳ��˵�����
// ����: �ڹ涨��Ǯ��n��,��Ҫ�������Ʒ�õ����������.����=Sum(vi*pi),�����������.

// �����͸���֮��,��ѡ���ʱ���ϰ���ԵĶ���Ʒ�����ж�,Ȼ���ԴӸ����������Ƶ�,���������Ƶ�,���ǻ��������
// ����,����ֱ�Ӵ�����ʼ����
// ����һ��"����"�ĵ�����һ��������Ʒ,������Ʒ������Ϊ����,�����Եõ�һ���µ���Ʒ����<������Ʒ>
// ��ô�Ϳ���ֱ��������µ������н���01�����������,����i��"������Ʒ"Ҫ���ǲ�Ҫ������
// Ȼ��ѡ��ĳһ��������Ʒ֮��,�������ĸ�������follows��,��ÿһ����������01������������,Ҫ��1?��2?��1+2?
// dp[i][j]:��1...i��������Ʒ��ѡ��,�ڻ��Ѳ�����jʱ,�ܹ���õ��������
// 1. ���ǿ����ٷ�װһ��"������Ʒ"���� 2. ��ԭ��Ʒ������,ר�����������Ʒ����չ������
// ���´��������2

#include <iostream>
#include <vector>
using namespace std;
class DependentKnapsack
{
private:
    int n, m; // n�����Ǯ��,m���ж��ټ���Ʒ
    // ��Ϊ�±��Ǵ�1λ�ÿ�ʼ�洢,���Զ࿪һ���ռ�
    vector<int> cost;            // ��¼��Ʒ�۸�
    vector<int> val;             // ��¼������Ʒ�ܹ������ļ�ֵ
    vector<bool> isRoot;         // true:��ǰ��Ʒ������,false:��ǰ��Ʒ�Ǹ���
    vector<int> fans;            // ��¼ÿ����Ʒ�ĸ�������
    vector<vector<int>> follows; // ��¼������Ʒ���
private:
    void init()
    {
        cost = vector<int>(m + 1);
        val = vector<int>(m + 1);
        isRoot = vector<bool>(m + 1);
        fans = vector<int>(m + 1);
        follows = vector<vector<int>>(m + 1, vector<int>(2));
    }
public:
    int Main()
    {
        cin >> n >> m;
        init();
        for (int i = 1, v = 0, p = 0, q = 0; i <= m; i++)
        {
            cin >> v >> p >> q;
            cost[i] = v;
            val[i] = v * p;
            isRoot[i] = q == 0;
            if (q != 0) // q����i����Ʒ���������
                follows[q][fans[q]++] = i; // �������Ķ�Ӧλ�÷���i��,��ע���ۼ�fans[q]
        }
        return func();
    }
    int func1()
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // dp[0][...]: ��ѡ����Ʒʱ�ܹ���õ��������=0
        int p = 0; // ��һ��������Ʒ�ı��,��ʵ����"������Ʒ"�����i-1λ��
        for (int i = 1,fan1=0,fan2=0; i <= m; i++)
        {
            if (isRoot[i])
            {
                for (int j = 0; j <= n; j++)
                {
                    // ������1: ���������Ʒ��Ҫ
                    dp[i][j] = dp[p][j];
                    // ������2: ���������ƷҪ
                    if (j - cost[i] >= 0)
                        dp[i][j] = max(dp[i][j], dp[p][j - cost[i]] + val[i]);
                    // ѡ�����������Ʒ֮��,չ�����۸���Ҫ��Ҫ
                    // fan1 : ����и�1��Ʒ����Ÿ�fan1�����û�У�fan1 == -1
                    // fan2 : ����и�2��Ʒ����Ÿ�fan2�����û�У�fan2 == -1
                    fan1 = fans[i] >= 1 ? follows[i][0] : -1;
                    fan2 = fans[i] >= 2 ? follows[i][1] : -1;
                    if (fan1 != -1 && j - cost[i] - cost[fan1] >= 0)
                        dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan1]] + val[i] + val[fan1]);
                    if (fan2 != -1 && j - cost[i] - cost[fan2 >= 0])
                        dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan2]] + val[i] + val[fan2]);
                    if (fan1 != -1 && fan2 != -1 && j - cost[i] - cost[fan1] - cost[fan2] >= 0)
                        dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan1] - cost[fan2]] + val[i] + val[fan1] + val[fan2]);
                }
            }
            p = i;
        }
        return dp[p][n]; // ��ʱ���ص������һ��������Ʒp
    }
    // �ռ�ѹ���汾: ��������һ��"������Ʒ"�����: ��j��,j-cost[0],j-cost[1],j-cost[0]-cost[1]��;
    // ����ֱ�Ӵ���������и��¼���
    int func()
    {
        vector<int> dp(n + 1);
        for (int i = 1, fan1 = 0, fan2 = 0; i <= m; i++)
        {
            if (isRoot[i])
            {
                for (int j = n; j >= cost[i]; j--)
                {
                    dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
                    fan1 = fans[i] >= 1 ? follows[i][0] : -1;
                    fan2 = fans[i] >= 2 ? follows[i][1] : -1;
                    if (fan1 != -1 && j - cost[i] - cost[fan1] >= 0)
                        dp[j] = max(dp[j], dp[j - cost[i] - cost[fan1]] + val[i] + val[fan1]);
                    if (fan2 != -1 && j - cost[i] - cost[fan2] >= 0)
                        dp[j] = max(dp[j], dp[j - cost[i] - cost[fan2]] + val[i] + val[fan2]);
                    if (fan1 != -1 && fan2 != -1 && j - cost[i] - cost[fan1] - cost[fan2] >= 0)
                        dp[j] = max(dp[j], dp[j - cost[i] - cost[fan1] - cost[fan2]] + val[i] + val[fan1] + val[fan2]);
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    DependentKnapsack d;
    cout << d.Main() << endl;
    return 0;
}
