#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//������
//1.ί�ɹ��캯��
#if 1
//ί�ɹ��캯��
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
	Test() = default;	//��������Ϊϵͳ��Ĭ�������ĺ���
	Test(const Test& a) = delete;
	Test(int a) :
		m_a(a) {

	}
};
#endif

#if 0
//2.��ֵ����
//	��ֵ -- ����ȡ��ַ��ֵ
//	1) ����ֵ -- ����
//	2������ֵ -- ��ʱ����
//	��ֵ����������ֵʱ�������ú�ָ����ͬ��
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

	//�ƶ����캯��
	//C++11�У��ƶ������ǵ�7��Ĭ�Ϻ���������ֻ�ṩǳ����
	String(String&& s) :
		str(s.str) {
		s.str = nullptr;	//�ÿպ��޷��ͷ�
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


	//����ֵ�Ż�
	//String test(getString("bit"));

	Test t('a');
	t.show();


	return 0;
}