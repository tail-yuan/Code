#pragma once
namespace yuanwei
{
	//������ʾĳһλ�����Ƿ���ֹ�01��ʾ
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			bits.resize(N/8+1);
			//��8bitΪһ����λ��������,Ҳ����һ��int
			//������ҪN>32λ�ı��ʱ,�Ͷ����뼸��int ����
		}
		void set(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			bits[i] |= (1<<j);
		}
		void reset(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			bits[i] &=~(1<<j)
		}
		bool test(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			return bits[i] & (1 << j)
		}
	private:
		std::vector<char> bits;
	};
	
}
//������һ�������Ƿ���ֹ�����,�������ű�����ʾ
template<size_t N>
class TwoBitSet
{
public:
	void Set(size_t N)
	{
		if (!bs1.test(N) && !bs2.test(N))//00
			bs2.set(N);
		else if (!bs1.test(N) && bs2.test(N))
		{
			bs1.set(N);
			bs2.reset(N);
		}
	}

private:
	yuanwei::bitset<N> bst1;
	yuanwei::bitset<N> bst2;
};