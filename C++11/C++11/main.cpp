#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//有问题
//1.委派构造函数
#if 1
//委派构造函数
class Test {
	int m_a;
	char m_c;
public:
	Test():
		m_a(0),m_c('\0'){
	}
	Test(char c){
		Test();
		m_c = c;
	}
	
	void show() {
		cout << "m_a:" << m_a << endl;
		cout << "m_c" << m_c << endl;
	}
};
#endif

#if 0
class Test {
	int m_a;
public:
	Test() = default;	//将其声明为系统库默认声明的函数
	Test(const Test& a) = delete;
	Test(int a) :
		m_a(a) {

	}
};
#endif

#if 0
//2.右值引用
//	右值 -- 不能取地址的值
//	1) 纯右值 -- 常量
//	2）将亡值 -- 临时对象
//	右值引用做返回值时，与引用和指针相同，
class String {
	char* str;
public:
	static int count;
	String(char* s = "") {
		if (nullptr == str) {
			str = "";
		}
		str = new char[strlen(str) + 1];
		strcpy(str, s);
		++count;
	}

	//移动构造函数
	//C++11中，移动构造是第7个默认函数，但是只提供浅拷贝
	String(String&& s) :
		str(s.str) {
		s.str = nullptr;	//置空后，无法释放
	}

	String(const String& s):
		str(new char[strlen(s.str) + 1]){
		strcpy(str, s.str);
	}

	String& operator=(const String& s) {
		if (this != &s) {
			char* ptmp = new char[strlen(s.str) + 1];
			strcpy(ptmp, s.str);
			delete[] str;
			str = ptmp;
		}
		return *this;
	}
	~String() {
		if (str) {
			delete[] str;
		}
	}
};
int String::count = 0;
String getString(char* str) {
	return String(str);
}

#endif


#if 0
int func(int a) {
	a += 5;
	cout << &a << endl;
	//return static_cast<int&&>(a);
	return move(a);
}

#endif



int main() {



	//String s("hello");
	//String m(move(s));

	//int&& a = 1;
	//const int& aa = 1;
	//int&& k = func(6);
	//cout << &k;


	//返回值优化
	//String test(getString("bit"));

	Test t('a');
	t.show();


	return 0;
}