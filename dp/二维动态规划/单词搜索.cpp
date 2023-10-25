//https://leetcode.cn/problems/word-search/description/
#include<iostream>
#include<vector>
using namespace std;
//������,������: ����(i,j)λ��,�������ַ���,����ȥƥ��word��indexλ���ַ�,ѡ��һ��֮��,
// ����dfs()�ܹ���ѡ�����λ�õĻ�����,�����ҵ�����ƥ����ַ���,����ֵ��bool,
// false����ѡ�е��������,true����ƥ��word�ɹ�.
//���нڵ���Ϊ���(i,j)��������һ��,�ӵ�һ���ַ���ͬ��λ�ÿ�ʼƥ��,�ڻ�ûtrueʱ��Ϊfalse.
//�ݹ����:���պϷ��ķ�����,�ҵ�word��β�����ҳɹ���
//��֦: ��ѡ�е���һ��λ�ú�word[index]�Ƿ�ƥ��,��ƥ��ľ�û��Ҫ��������;
//ע��: ���ܻ�ͷ��,�����ö�ά����visited���,ĳһ���ڵ��Ƿ�������·���Ѿ��ù���||�޸�ԭʼ�����ֵ
//����: �ָ��ֳ�.
//�ڲ���4������ʱ,�����ظ�����,����ʹ��visi������,����ʹ�ø���ԭ����ֵ�ķ�ʽ

//�����������ֵ�Ĳ�ֹ�������±�,https://www.bilibili.com/video/BV1WQ4y1W7d1?t=3377.6
//���������������ά��״̬�ı仯������,�������޷��ÿɱ�����Ķ�ά��洢������ߵı仯,�����޷�����Ϊdp
//������������������С,���������1<n,m<7,ֱ�ӱ���չ������.
class Solution 
{
    int n, m;
    bool visi[7][7];
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])//�ҵ���һ���ַ�ƥ���,��֦
                {
                    visi[i][j] = true;
                    if (dfs(board, i, j, word, 1))
                        return true;
                    visi[i][j] = false;//�ָ��ֳ�,���������ʼû��!
                }
            }
        }
        return false;
    }
    int dx[4] = { 0,0,1,-1 };
    int dy [4] = {1,-1,0,0};
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int index)
    {
        if (index == word.size())
            return true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x < n && x >= 0 && y < m && y >= 0 && !visi[x][y] && board[x][y] == word[index])
            {
                visi[x][y] = true;
                if (dfs(board, x, y, word, index + 1))
                    return true;
                visi[x][y] = false;
            }
        }
        return false;
    }
};