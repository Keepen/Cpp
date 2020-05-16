#define _CRT_SECURE_NO_WARNINGS
//模拟实现一个string类
#include <iostream>
#include <string.h>
using namespace std;

class String {
private:
	char* _str;
	size_t _capacity;
	size_t _size;	
public:
	size_t npos = -1;
	typedef char* iterator;
	typedef const char* const_iterator;
	String() :
		_size(0),
		_capacity(0){
		_str = '\0';
	}

	String(const String& s) {
		_size = s._size;
		_capacity = s._capacity;
		_str = new char[s._capacity];
		memcpy(_str, s._str, s._size);
	}

	//1.reserve
	void Reserve(size_t n) {
		size_t newC = (_capacity == 0) ? 15 : _capacity * 2;
		while (newC < n) {
			newC *= 2;
		}
		_capacity = newC;
		if (newC == 15) {
			_str = new char[newC];
			return;
		}
		char* news = new char[newC];
		strcpy(news, _str);
		delete[] _str;
		_str = news;
	}

	//2.resize
	void Resize(size_t n, char c = '\0') {
		if (n < _size) {
			_size = n;
			_str[_size] = '\0';
			return;
		}
		if (n > _capacity) {
			Reserve(n);
		}
		for (size_t i = _size; i < n; ++i) {
			_str[i] = c;
		}
		_str[n] = '\0';
	}

	//3.pushback
	void PushBack(char c) {
		if (_size == _capacity) {
			Reserve(_capacity);
		}
		_str[_size] = c;
		_size++;
	}

	//4.begin()迭代器
	iterator begin() {
		return _str;
	}

	//5.end()迭代器
	iterator end() {
		if (_str) {
			return _str + _size;
		}
		return nullptr;
	}

	//6.const迭代器
	const_iterator begin() const {
		return _str;
	}

	//7.const end
	const_iterator end()const {
		if (_str) {
			return _str + _size;
		}
		return nullptr;
	}

	//8.+= 的重载
	//	1)+=一个字符
	String& operator+=(char c) {
		if (_size == _capacity) {
			Reserve(_size);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
		return *this;
	}

	//	2)+=一个字符串
	String& operator+=(const char* c) {
		size_t len = strlen(c);
		if (_size + len >= _capacity) {
			Reserve(_size + len);
		}
		strcpy(_str + _size, c);
		_size += len;
		_str[_size] = '\0';
		return *this;
	}

	//	3)+=一个对象
	String& operator+=(const String& s) {
		if (_size + s._size >= _capacity) {
			Reserve(_size + s._size);
		}
		strcpy(_str + _size, s._str);
		_size += s._size;
		_str[_size] = '\0';
		return *this;
	}

	//9.Insert
	//	1)在pos位置，插入一个字符
	String& insert(size_t pos, char c) {
		if (_size >= _capacity) {
			Reserve(_size);
		}
		_size++;
		for (size_t i = _size; i > pos; --i) {
			_str[i] = _str[i - 1];
		}
		_str[pos] = c;
		//_size++;
		return *this;
	}

	//	2)在pos位置插入一个字符串
	String& insert(size_t pos, const char* s) {
		size_t len = strlen(s);
		if (_size + len >= _capacity) {
			Reserve(len + _capacity);
		}
		_size += len;
		for (size_t i = _size - 1; i > pos; --i) {
			_str[i] = _str[i - len];
		}
		strncpy(_str + pos, s, len);
		return *this;
	}

	//	3)在pos位置处插入一个对象
	String& insert(size_t pos, const String& s) {
		if (_size + s._size >= _capacity) {
			Reserve(_size + s._size);
		}
		_size += s._size;
		for (size_t i = _size - 1; i > pos; --i) {
			_str[i] = _str[i - s._size];
		}
		strncpy(_str + pos, s._str, s._size);
		return *this;
	}

	//10.Erase
	//	1)在pos位置擦除一个字符
	void Erase(size_t pos) {
		if (pos < _size) {
			while (pos < _size) {
				_str[pos++] = _str[pos + 1];
			}
			_size--;
		}
	}

	//	2)在pos位置擦除n个字符
	void Erase(size_t pos, size_t n) {
		if (pos < _size) {
			while (pos < _size) {
				_str[pos++] = _str[pos + n];
			}
			_size -= n;
		}
	}

	//11.重载输出运算符 <<
	friend ostream& operator<<(ostream& _cout, const String& s) {
		const_iterator it = s.begin();
		cout << s._size << endl;
		//cout << s._str[s.end() - 1] << endl;
		while (it != s.end()) {
			_cout << *it;
			++it;
		}
		return _cout;
	}

	//12.find
	//	1）查找一个字符
	size_t find(char c) {
		for (size_t i = 0; i < _size; ++i) {
			if (_str[i] == c) {
				return i;
			}
		}
		return npos;
	}

	//	2）查找一个字符串
	size_t find(const char* s) {
		char* pos = strstr(_str, s);
		if (pos) {
			return pos - _str;
		}
		return npos;
	}

	//	3）查找一个对象
	size_t find(const String& s) {
		char* pos = strstr(_str, s._str);
		if (pos) {
			return pos - _str;
		}
		return npos;
	}
	//14.+的重载
	//	1）+一个字符
	String operator+(const char c) {
		String tmp = *this;
		tmp += c;
		return tmp;
	}

	//	2）+一个字符串
	String operator+(const char* s) {
		String tmp = *this;
		tmp += s;
		return tmp;
	}

	//	3）+一个对象
	String operator+(const String& s) {
		String tmp = *this;
		tmp += s;
		return tmp;
	}
	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}

	size_t size() {
		return _size;
	}
	void Print() {
		for (size_t i = 0; i < _size; ++i) {
			cout << _str[i];
		}
	}
};

void test() {
	String s;
	s += "aaaaa";
	s += "123456789";
	s.PushBack('Q');
	s.PushBack('W');
	
	s.insert(4, 'e');
	//s.Print();
	//cout << s._size << endl;
	//s.insert(2, "hello");
	//s.Print();
	//cout << endl;
	//String s1;
	//s1 += "ABCDEFG";
	//s1.insert(2, s);
	//s1.Print();
	s.Erase(4);
	s.Erase(0, 5);
	cout << s.size() << endl;
	cout << s << endl;
	String tmp = s + 'D';
	cout << tmp.size() << endl;
	cout << tmp << endl;

	cout << s.find("345") << endl;
	String s1;
	s1 += "QW";
	cout << s.find(s1) << endl;
}


int main() {
	test();
	return 0;
}