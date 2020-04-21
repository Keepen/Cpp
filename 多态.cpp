#include <iostream>
using namespace std;

//多态：就是不同对象，行为不同
//多态的实现：
//1.存在继承关系
//2.有虚函数
//3.对其调用的函数参数必须是对象引用/指针


//class Person {
//public:
//	//声明成纯虚函数，此时该类就是一个抽象类，
//	//只是相当于一个接口，不实现，接口的实现在其子类内部实现
//	//virtual void BuyTicket() = 0;
//	virtual void BuyTicket() {
//		cout << "全票！！！" << endl;
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
//		cout << "半票！" << endl;
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
//		cout << "全票！" << endl;
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
//	//&p					取对象的地址
//	//(int*)&p				将对象的地址转换成int*类型，
//	//*(int*)&p				只读前四个字节，拿到虚函数表指针
//	//(VFPTR*)*(int*)&p		将虚函数表指针转换成函数指针类型
//	//*(VFPTR*)*(int*)&p	读出虚函数表的第一个元素，即第一个函数指针
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


//多继承下的多态

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