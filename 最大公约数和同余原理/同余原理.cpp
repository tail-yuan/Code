//��һ�����ʽ������ȡ��ֵʱ,�����м�ֵ��������ĳ���,�Ϳ�������ͬ��ԭ��
//��string����ƴ����ʱ,���λ������,������㲻��ĳ���.
// ��Ϊint����,longlong�����ڵײ㶼�ǹ̶�λ��,int->32λ,longlong64λ,���Լ�����O(1)
// ����ÿ���м�����kλ,��ô�����������ʱ�临�Ӷ���+-��O(k),*/��O(k^2)
// ����Խ��Խ��
//��������ͬ��ԭ��ʽ: 
// (a+b)%m = (a%m + b%m )%m
// (a*b)%m = (a%m * b%m )%m
// (a-b)%m = (a%m - b%m +m)%m
// 
class Solution
{
	//����((a + b)* (c - d) + (a * c - b * d)) % mod �ķǸ����
public:
	int f2(long long a, long long b, long long c, long long d, int mod) 
	{
		int o1 = (int)(a % mod); // a
		int o2 = (int)(b % mod); // b
		int o3 = (int)(c % mod); // c
		int o4 = (int)(d % mod); // d
		int o5 = (o1 + o2) % mod; // a + b
		int o6 = (o3 - o4 + mod) % mod; // c - d
		int o7 = (int)(((long long)o1 * o3) % mod); // a * c
		int o8 = (int)(((long long)o2 * o4) % mod); // b * d
		int o9 = (int)(((long long)o5 * o6) % mod); // (a + b) * (c - d)
		int o10 = (o7 - o8 + mod) % mod; // (a * c - b * d)
		int ans = (o9 + o10) % mod; // ((a + b) * (c - d) + (a * c - b * d)) % mod
		return ans;
	}
};
