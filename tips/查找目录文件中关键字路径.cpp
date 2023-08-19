#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution
{
private:
    unordered_map<string, vector<string>>hashMap;
public:
    void createTree(vector<string>& content)
    {
        string root = content[0];
        for (int i = 1; i < content.size(); i++)
        {
            string str = content[i];
            char ch = str[1];
            if (ch != '-')
            {
                hashMap[root].push_back(str);
            }
            else//�������Ŀ¼ʱ������Ӧ��һ��Ŀ¼
            {
                string index = hashMap[root].back();
                hashMap[index].push_back(str);
            }
        }
    }
    //ÿ���ڵ㶼����ͬ��������,
    //�Ȳ鿴�Լ��Ƿ����key�ؼ���,����,path+=str,������; ���ߺ��ӽڵ����
    //Ȼ���ٱ����Լ���vector��ÿ���ڵ��Ƿ����
    //��֦: 
    //void dfs(string str,string path)
    //{
    //    //if (isCon(str)) ���ֻ�а���key�ķ�Ҷ�ӽڵ���ܴ�ӡ
    //    //    path += str;
    //    path += str;//����·��ȫ����ӡ��
    //    if (hashMap[str].size() == 0)//��Ҷ�ӽڵ�
    //    {
    //        ans.push_back(path);
    //        return;
    //    }
    //    for (auto s : hashMap[str])
    //    {
    //        //if(isCon(s)) ��֧��������ֱ�Ӳ����˾ʹ���
    //        //    dfs(s, path+s);
    //        dfs(s, path);
    //    }
    //    //�ָ��ֳ�
    //    for (int i = 0; i < str.size(); i++)
    //        path.pop_back();
    //}
    bool dfs(string str, string path)
    {
        path += str;
        if (hashMap[str].size() == 0 && isCon(str))//��Ҷ�ӽڵ㲢�Ұ���key
        {
            ans.push_back(path);
            return true;
        }
        bool ret= false;
        for (auto s : hashMap[str])
        {
            ret=dfs(s, path);
        }
        //�Ӹ�·������,���ֲ�û�н��,����·����ӵ�strĿ¼�ּ�ɾ��
        if (!ret)
        {
            for (int i = 0; i < str.size(); i++)
                path.pop_back();
        }
    }
    bool isCon(string& s)
    {
        char* tmp = new char[s.size() + 1];
        strcpy(tmp, s.c_str());
        char* pos =strstr(tmp, key.c_str());
        if (pos == nullptr)
            return false;
        return true;
    }
    vector<string> find(string& keyword)
    {
        key = keyword;
        string root = "/root";
        string path;
        bool tmp = dfs(root, path);
        if (tmp)
        {
            vector<string>ret;
            for (int i = 0; i < ans.size(); i++)
            {
                if (!ans[i].empty())
                    ret.push_back(ans[i]);
            }
            return ret;
        }
        else
        {
            return {};
        }
    }
private:
    vector<string>ans;
    string key;
};
int main()
{
    std::string keyword;
    std::cin >> keyword; // ��ȡ�ؼ���
    int count = 0;
    std::cin >> count;
    std::vector<std::string> contents; // ÿ�е�����
    for (int i = 0; i < count; ++i) {
        std::string tmp;
        std::cin >> tmp;
        contents.push_back(tmp);
    }
    Solution s;
    s.createTree(contents);
    vector<string>ans = s.find(keyword);
    if (ans.size() == 0)
        cout << "No Files Found" << endl;
    else
    {
        for (auto e : ans)
        {
            cout << e << endl;
        }
    }
    return 0;
}
