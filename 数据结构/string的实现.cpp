#include<iostream>
#include<assert.h>
#include<ostream>
namespace yuanwei
{
	class string
	{
	public:
		//ȫȱʡ���캯��<=>Ĭ�Ϲ��캯��
		string(const char* str = "")
			:_size(sizeof(str))
			, _capc(_size)
		{
			_str = new char[sizeof(str) + 1];
			strcpy(_str, str);
		}
		////���
		string(const string& str)
		{
			string tmp(str._str);//����Ĭ�Ϲ��캯��,��Ϊtmp�ռ仹δ����.
			Swap(tmp);
		}
		void Swap(string& s2)
		{
			std::swap(_size, s2._size);
			std::swap(_capc, s2._capc);
			std::swap(_str, s2._str);
		}
		string& operator=(const string& s)
		{
			/*if (&s != this)
			{
				delete[] _str;
				_str = new char[sizeof(s) + 1];
				strcpy(_str,s._str);
				_size = s._size;
				_capc = s._capc;
				return *this;
			}*/
			if (&s != this)
			{
				string tmp(s);
				Swap(tmp);
			}
			return *this;
		}
		string& operator=(string s) //�βα������һ�ݿ���
		{
			if (&s != this)
			{
				Swap(s);
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capc = 0;
		}
	public:
		// iterator
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
	public:
		// modify
		void push_back(char c)
		{
			if (_size == _capc)
			{
				_capc = _capc == 0 ? 10 : _capc * 2;
			}
			_str[_size] = c;
			_size++;
			_str[_size] = '\0';
		}
		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		void append(const char* str)
		{
			//�����㹻�Ŀռ� reserve
			size_t len = sizeof(str);
			if (_size + len > _capc)
			{
				reserve(_size + len);//����_capc
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		void swap(string& s)
		{
			Swap(s);
		}
		const char* c_str()const
		{
			return _str;
		}
	public:
		// capacity

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capc;
		}

		bool empty()const
		{
			return _size == 0;
		}
		void reserve(int newCap)
		{
			if (newCap > _capc)
			{
				char* tmp = new char[newCap + 1];
				strcpy(tmp, _str);
				_capc = newCap;
				_str = tmp;
				delete[] tmp;
			}
		}
		void resize(int n, char ch = '\0')//����ѿռ��ʼ��Ϊɶ
		{
			if (n <= _size)
				_str[n] = ch;
			else
			{
				if (n > _capc)//����һ���
				{
					reserve(n);
				}
				else
				{
					//[_size,n]��ʼ��Ϊch
					memset(_str + _size, ch, n - _size);
					_size = n;
					_str[_size] = '\0';
				}
			}
		}
	public:
		// access

		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
	public:
		//relational operators

		bool operator<(const string& s)
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator==(const string& s)
		{
			return strcmp(_str, s.c_str()) == 0;
		}

		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s)
		{
			return !(*this < s);
		}

		bool operator>=(const string& s)
		{
			return *this > s || *this == s;
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
	public:
		// ���ش�posλ�ÿ�ʼ,c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const
		{
			int ret = -1;
			for (int i = pos; i < _size; i++)
			{
				if (_str[i] == c)
				{
					ret = i;
					break;
				}
			}
			return ret;
		}
		// ��posλ�ÿ�ʼ,�����Ӵ�s��string�е�һ�γ��ֵ�λ�� ������ʽ or KMP 
		size_t find(const char* s, size_t pos = 0) const
		{
			size_t ret = -1;
			for (int i = pos; i < _size; i++)
			{
				int j = i;
				for (; j < sizeof(s); j++)
				{
					if (_str[i] != _str[j])
						break;
				}
				//һ��������ѭ��iλ�ÿ�ʼ����,һ���ǽ���
				if (j == sizeof(s))
				{
					ret = j; break;
				}
			}
			return ret;
		}

		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��

		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capc)
				reserve(_capc == 0 ? 10 : _capc * 2);
			int end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			_size++;
			_str[_size] = '\0';
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = sizeof(str);
			if (_size + len > _capc)
				reserve(_size + len);
			size_t end = _size + len;
			while (end - len > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��

		string& erase(size_t pos, size_t len)
		{
			assert(pos < _size);
			if (len == 0 || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);//����pos����
				_size -= len;
			}
			return *this;
		}
	public:
		//��Ԫ����
		friend std::istream& operator>>(std::istream in, string& str);
		friend std::ostream& operator<<(std::ostream& out, const string& str);
	public:
		//��ֵ����
		//�ƶ�����
		string(string&&s)
			:_str(nullptr)
		{
			swap(s);//�����ٹ���һ������tmp,��һ�����
		}
		//�ƶ���ֵ
		string& operator=(string&& s)
		{
			swap(s);//�����ٹ���һ������tmp,��һ�����
			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capc;
	};
	std::ostream& operator<<(std::ostream& out, string& str)
	{
		for (auto c : str)
			out << c << " ";
		return out;
	}
	std::istream& operator>>(std::istream& in, string& str)
	{
		str.clear();
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			str += ch;
			ch = in.get();
		}
		return in;
	}
}
