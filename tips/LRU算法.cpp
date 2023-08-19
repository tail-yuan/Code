#include<iostream>
#include<list>//˫����������
#include<unordered_map>
using namespace std;
//splice() �����Ĺ��ܿ����ܽ����£�
//1. splice(iterator position, list& x)���� x �е�����Ԫ���ƶ�����ǰ list �� position ֮ǰ��
//2. splice(iterator position, list& x, iterator i)���� x �е����� i ָ���Ԫ���ƶ�����ǰ list �� position ֮ǰ��
//3. splice(iterator position, list& x, iterator first, iterator last)���� x �з�Χ[first, last) �ڵ�����Ԫ���ƶ�����ǰ list �� position ֮ǰ��
//��Щ���������� O(1) ʱ�临�Ӷ�����ɣ���Ϊ std::list ��˫������ֻ��Ҫ�����ڵ��ָ�뼴��ʵ��Ԫ�ص��ƶ���������Ҫ����������һ���������ݵĸ��ơ�
//��ʹ�� splice() �����ǳ���Ч���ر��ʺ�������ҪƵ���ƶ�Ԫ�صĳ�����
class LRUCache 
{
private:
    size_t _cap;
    list<pair<int, int>> _LRUList;//<key,val>
    typedef list<pair<int, int>>::iterator iterator;//����ڵ�������ܷ���
    unordered_map<int, iterator> hashMap;//<key,iterator>
public:
    LRUCache(int capacity) 
        :_cap(capacity)
    {}

    int get(int key) 
    {
        auto ret = hashMap.find(key);
        if (ret != hashMap.end())
        {
            iterator it = ret->second;
            _LRUList.splice(_LRUList.begin(),_LRUList,it);
            return it->second;
        }
        else
            return -1;
    }

    void put(int key, int value) 
    {
        auto ret = hashMap.find(key);
        if (ret != hashMap.end())
        {
            //��Ҫ��ֵ���и���,Ȼ���ƶ���������ײ�
            auto it = ret->second;
            it->second = value;
            _LRUList.splice(_LRUList.begin(),_LRUList,it);
        }
        else
        {
            //�����ڵ�,һ�������ǿ����Ƿ�����,����LRU���ǽ�����β����̭
            if (_cap == _LRUList.size())
            {
                pair<int, int> back = _LRUList.back();
                _LRUList.pop_back();
                hashMap.erase(back.first);
            }
            //��������ͷ��λ��
            _LRUList.push_front({key,value});
            hashMap[key] = _LRUList.begin();
        }
    }
};