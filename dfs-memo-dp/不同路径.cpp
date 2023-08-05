#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/unique-paths/submissions/
class Solution1//dp˼��: ��ĳһ��λ��Ϊ���,�����,��һ�ֵ��Ƶķ�ʽ,�Ե�����;
{
    int m;
    int n;
public:
    int uniquePaths(int _m, int _n)
    {
        m = _m, n = _n;
        return dfs(0, 0);
    }
    int dfs(int row, int col)
    {
        if (row == m - 1 && col == n - 1)
        {
            return 1;
        }
        int ret = 0;
        if (row + 1 < m)
            ret += dfs(row + 1, col);
        if (col + 1 < n)
            ret += dfs(row, col + 1);
        return ret;
    }
};
class Solution2
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n));
        //��ʼ����һ�к͵�һ��
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
//�����Ż�:���һ��,���һ��,�������Խ�����ĵ�һ�е�һ�еĳ�ʼ�����뵽����ѭ��������
//������,��Ҫ��һ�е�һ�а�����Ϊ1,����dp[0][1]=1����
class Solution3
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        //��ʼ����һ�к͵�һ��
        dp[0][1] = 1;
        for (int i = 1; i <=m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};
//int main()
//{
//    Solution1 s1;
//    Solution2 s2;
//    Solution3 s3;
//    cout << (s1.uniquePaths(23, 12) == s2.uniquePaths(23, 12)&&s1.uniquePaths(23,12)==s3.uniquePaths(23,12));
//    //���ڱ����ݹ�Ч�ʵ�,��������һ�ᷢ�ֽ�����ǶԵ�.
//}

//���仯����
class Solution4
{
    int m,n;
public:
//ѡ��i,jλ����Ϊ���,������,��ÿ��λ�ÿ���ѡ�������߻���������
//����: �������յ�ʱ,˵��ȷʵ�ҵ���һ��,return 1
//�ж�: ���־������г��ִ����ظ�ֵ�ļ���,���Կ��Բ��ö���ռ��¼�ظ������ֵ,�ﵽ��֦��Ŀ��
//->��Ϊ���仯����
//1. �������ռ� 2. �ڷ���֮ǰ��¼ 3. �ڽ���֮���Ȳ鿴�Ƿ��Ѿ�����
    int uniquePaths(int _m, int _n) 
    {
        m=_m,n=_n;
        vector<vector<int>> memo(m,vector<int>(n));
        return dfs(0,0,memo);
    }
    int dfs(int i,int j,vector<vector<int>>& memo)
    {
        //����֮���ȿ�һ��
        if(memo[i][j])
            return memo[i][j];
        
        if(i == m-1 && j==n-1)
        {
            memo[i][j]=1;
            return memo[i][j];
        }
        
        int ret=0;
        if(i < m-1)
            memo[i][j]+=dfs(i+1,j,memo);//������
        if(j < n-1)
            memo[i][j]+=dfs(i,j+1,memo);//������
        return memo[i][j];
    }
};

//���仯����->��̬�滮���Ż��汾,�����Ǹ��࿪һ�ж࿪һ�е����
class Solution5
{
public:
//��i,jλ��Ϊ�յ�,������,�Զ����µķ�ʽ
//��ΪҪ���Ƕ�ά�����е�m,n�±�,���Զ�ά����϶��ÿ�m+1,n+1��С��
//�ж�: ���־������д��ڴ������ظ�ֵ�ļ���,���Կ��Ը�Ϊ���仯����
//->���仯����,1. ���ռ� 2. ����ݹ�ʱ�ȿ�һ�� 3. ���ؽ��ʱ��¼һ��
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>memo(m+1,vector<int>(n+1));//1
        return dfs(m,n,memo);
    }
    int dfs(int i,int j, vector<vector<int>>&memo)
    {
        if(memo[i][j]) return memo[i][j];//2
        //�������Ǵ�1,1λ��������,�㶼����0�л��ߵ�0�п϶�û���������0
        if(i == 0 || j==0) 
        {
            return 0;//��Ϊmemo��������ֵ��ʼ������0
        }
        if(i==1 && j==1) 
        {
            memo[i][j]=1;
            return memo[i][j];//3
        }
        memo[i][j]=dfs(i-1,j,memo)+dfs(i,j-1,memo);//3
        return memo[i][j];
    }
};