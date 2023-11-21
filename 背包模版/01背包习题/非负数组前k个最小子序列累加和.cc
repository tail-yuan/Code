
// ����һ������nums������n�����֣����ǷǸ���
// ����һ������k�������������������ۼӺ���С��ǰk���ۼӺ�
// �������ǰ����ռ���
// 1 <= n <= 10^5
// 1 <= nums[i] <= 10^6
// 1 <= k <= 10^5
// ע���������������01�����Ľⷨ�ǲ��еģ�ʱ�临�Ӷ�̫����. ��Ҫ��д��ά�� >> 10^7 10^8
// ��������֤
// ------------�ⷨ1:
// Ҳ����˵,���ǵõ����������е��ۼӺ�->nums[]��,���մ�С��������,��ȡ��ǰk�����ans[]����
// ------------�ⷨ2: ʹ��01�����ķ�ʽ
// dp[i][j]��ʾ: ��ǰi��������ѡ��,�ۼӺ�<=j��������һ���ж��ٸ�
// ���һ�ж���dp[n][0...sum]�ĸ���,Ȼ���ȡ0<=j<=k��Щ���������ans[]����
// ���Ķ�ά�� i=n,j=sum,j�Ĵ�С���������й�,ʱ�ո��Ӷȶ���Խ��
// ------------�ⷨ3: �ѵķ�ʽ��� https://www.bilibili.com/video/BV1NN41137jF?t=7664.8
// <A{},sumA>
// ÿ�ε����Ѷ�,��¼sumA,������num = nums[index+1]
// 1. num->A{} ->sumA'
// 2. ɾ��A{}��Ԫ��,Ȼ��num->A{} ->sumA ''
// ��sumA' sumA''->heap
//...
// codeʱֻ��Ҫ��¼���������һ��Ԫ�ص��±꼴�ɴ���ά�ֵ� ��������
//<�����±�,�ۼӺ�>
// ÿ������һ��,һ����Ҫ����K-1��,�ͻ��������,Ȼ�����µ���O(logK),ʱ�临�ӶȺ�K�й�. O(k*log(k)).
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class TopKMinimumSubsequenceSum
{
public:
    vector<int> Main2(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int num : nums)
            sum += num;
        // 1. dp[i][j]=dp[i-1][j]
        // 2. dp[i][j]=dp[i-1][j-nums[i]]
        // ���������ӵõ����յ��ܸ���
        vector<int> dp(sum + 1);
        dp[0] = 1; // �ۼӺ�<=0��,��ô���ǿռ�,Ҳ��һ��
        for (int num : nums)
        {
            for (int j = sum; j >= num; j--)
                dp[j] += dp[j - num];
        }
        vector<int> ans(k);
        int index = 0;
        for (int j = 0; j <= sum && index < k; j++)
        {
            for (int i = 0; i < dp[j] && index < k; i++)
                ans[index++] = j;
        }
        return ans;
    }

public:
    class Node
    {
    public:
        int right;
        int sum;

    public:
        Node(int r, int s)
            : right(r), sum(s)
        {
        }
    };
    struct Less
    {
        bool operator()(const Node &n1, const Node &n2)
        {
            return n1.sum>n2.sum;
        }
    };
    vector<int> Main3(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        priority_queue<Node, vector<Node>, Less> heap;
        heap.push(Node(0, 0));
        vector<int> ans(k);
        for (int i = 1; i < k; i++)
        {
            Node cur = heap.top();
            heap.pop();
            int right = cur.right;
            int sum = cur.sum;
            ans[i] = sum;
            if (i + 1 < nums.size())
            {
                heap.push(Node(right + 1, sum - nums[right] + nums[right + 1]));
                heap.push(Node(right + 1, sum + nums[right + 1]));
            }
        }
        return ans;
    }
};