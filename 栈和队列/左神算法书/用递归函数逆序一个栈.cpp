#include<iostream>
#include<stack>
using namespace std;

class ReverseStack
{
public:
	void reverseStack(stack<int>& st)
	{
		if (st.empty())
			return;
		else
		{
			int i = getAndRemoveLastElement(st);
			reverseStack(st);
			st.push(i);
		}
	}
	//��ȡ���Ƴ�ջ��Ԫ��,�ݹ麯����return ��һֱ��last,��empty()֮ǰ�������ջ��Ԫ�ط���
	int getAndRemoveLastElement(stack<int>& st)
	{
		int result = st.top(); st.pop();
		if (st.empty())
			return result;
		else
		{
			int last = getAndRemoveLastElement(st);
			st.push(result);
			return last;
		}
	}
};
int main()
{
	ReverseStack s;
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	s.reverseStack(st);
	return 0;
}