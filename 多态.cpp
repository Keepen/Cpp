#include <iostream>
using namespace std;

//��̬�����ǲ�ͬ������Ϊ��ͬ
//��̬��ʵ�֣�
//1.���ڼ̳й�ϵ
//2.���麯��
//3.������õĺ������������Ƕ�������/ָ��


//class Person {
//public:
//	//�����ɴ��麯������ʱ�������һ�������࣬
//	//ֻ���൱��һ���ӿڣ���ʵ�֣��ӿڵ�ʵ�����������ڲ�ʵ��
//	//virtual void BuyTicket() = 0;
//	virtual void BuyTicket() {
//		cout << "ȫƱ������" << endl;
//	}
//
//	virtual void fun1(){}
//
//	void fun2(){}
//
//	virtual ~Person(){
//		cout << "~Person()" << endl;
//	}
//	int _a = 0;
//};
//
//class Student :public Person {
//public:
//	virtual void BuyTicket() {
//		cout << "��Ʊ��" << endl;
//	}
//	virtual void fun1(){}
//
//	virtual ~Student() {
//		cout << "~Student()" << endl;
//	}
//};
//
//class Teacher :public Person {
//public:
//	virtual void BuyTicket() {
//		cout << "ȫƱ��" << endl;
//	}
//
//	virtual ~Teacher() {
//		cout << "~Teacher()" << endl;
//	}
//
//};
//
//void Buy(Person& p) {
//	p.BuyTicket();
//}

//void test1() {
//	Teacher t;
//	Student s;
//	Buy(t); 
//	Buy(s);
//}

//typedef void(*VFPTR)();

//void test2() {
//	Person p;
//	Student s;
//	
//	
//	Buy(p);
//	Buy(s);
//
//	//&p					ȡ����ĵ�ַ
//	//(int*)&p				������ĵ�ַת����int*���ͣ�
//	//*(int*)&p				ֻ��ǰ�ĸ��ֽڣ��õ��麯����ָ��
//	//(VFPTR*)*(int*)&p		���麯����ָ��ת���ɺ���ָ������
//	//*(VFPTR*)*(int*)&p	�����麯����ĵ�һ��Ԫ�أ�����һ������ָ��
//
//	VFPTR p1 = *(VFPTR*)*(int*)&p;
//	p1();
//
//	//Person *s = new Student;
//	//Person *t = new Teacher;
//
//	//s->BuyTicket();
//	//t->BuyTicket();
//
//	//delete s;
//	//delete t;
//
//
//	//VFPTR p1 = *((VFPTR*)(*((int*)&p)));
//	//p1();
//}


//class A {
//public:
//	virtual void print() override {}
//};
//
//class B :public A{
//public:
//
//}
//test3() {
//
//}


//��̳��µĶ�̬

class A {
public:
	virtual void fun1() {}
	virtual void fun2(){}
	int _a;
};

class B {
public:
	virtual void fun3(){}
	virtual void fun4(){}
	int _b;
};
	
class Dest :public A, public B {
public:
	virtual void dest2(){}
	virtual void fun1() {}
	virtual void fun4() {}
	virtual void dest() {}
	int _dest;
};



typedef void(*VFPTR)();
void test4() {
	A a1;
	B b1;
	Dest d1;	
}


//class test {
//public:
//	virtual void tests(){}
//};
//
//void test5() {
//	test t1;
//}



int main() {
	//test1();
	//test2();
	//test3();
	test4();
	//test5();
	system("pause");
	return 0;
}