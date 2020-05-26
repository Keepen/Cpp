//#define _SCL_SECURE_NO_WARNINGS
#include "rsa.h"
#include "bigint.h"
#include <fstream>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using std::cin;
using std::cout;
using std::endl;

void test() {
	RSA rsa;
	Key key = rsa.getallKey();
	
	cout << "keys:" << endl;
	cout << key._ekey << "  " << key._dkey << " " << key._pkey << endl;

	DataType original = 2;
	DataType rnum = rsa.ecrept(original, key._ekey, key._pkey);
	DataType decout = rsa.decrept(rnum, key._dkey, key._pkey);
	cout << "original : " << original << endl;
	cout << "ecrept:" << rnum << endl;
	cout << "de : " << decout << endl;
}

void testFile() {
	//std::ifstream fin("test.txt");
	////文本形式打开，按照空格 / 换行，读取数据
	//char c;
	//int a;
	//double d;
	//fin.read(&c, 1);
	//cout << fin.gcount() << endl;
	//fin >> a;
	//cout << fin.gcount() << endl;
	//fin >> d;
	//cout << fin.gcount() << endl;
	//cout << "a : " << a << "c : " << c << " d: " << d << endl;

	//std::ifstream fin2("test.txt", std::ifstream::binary);
	//char buf[100] = { 0 };
	//fin2.read(buf, 100);
	//cout << fin2.gcount() << endl;
	//cout << buf << endl;

	//std::ofstream fout2("test2.txt", std::ofstream::binary);
	struct A {
		int a; float b; char c;
	};
	//A aa;
	//aa.a = 1; aa.b = 1.2; aa.c = 'K';
	//fout2.write((char*)&aa, sizeof(A));
	//fout2.close();
	std::ifstream fin3("test2.txt", std::ifstream::binary);
	A bb;
	fin3.read((char*)&bb, sizeof(A));
	cout << bb.a << "  " << bb.b << "  " << bb.c << endl;
}


void testRSA() {
	RSA rsa;

	rsa.ecrept("test.txt", "test.ecrept.txt");
	rsa.dcrept("test.ecrept.txt", "test.decrept.txt");
}

void testA() {
	RSA rsa;
	
	DataType a = 11;
	cout << "original: " << a << endl;
	Key key = rsa.getallKey();
	DataType de = rsa.ecrept(a, key._ekey, key._pkey);
	cout << "ecr : " << de << endl;
	cout << "de : " << rsa.decrept(de, key._dkey, key._pkey) << endl;
}

void testBigint() {
	BigInt bi;
	int a = 111111;
	int b = 9999;
	cout << a / b << "  " << a % b << endl;
	std::string aaa = "12345";
	std::string bbb = "23456";
	BigInt aa = aaa;
	BigInt bb = bbb;
	cout << aa << endl;
}

void testBoost() {
	boost::multiprecision::cpp_int ci;
	ci = 1024;
	std::string num = "123432";
	//ci = num;
	boost::multiprecision::cpp_int ci2(num);
	cout << ci2 << endl;

	boost::multiprecision::int1024_t cpp1024(num);
	cout << cpp1024 << endl;

	boost::multiprecision::int1024_t cpp1024_2 = boost::multiprecision::int1024_t(1) << 1023;
	cout << "for : 0 ~ 1 << 1023 :" << endl;
	for (boost::multiprecision::int1024_t i = 0; i < cpp1024; ++i) {

	}
	cout << " for is over!!!" << endl;
}

void BoostRandom() {
	boost::random::mt19937 gen(time(NULL));
	//boost::random::uniform_int_distribution<DataType> dist(0, 100);
	for (int i = 0; i < 100; ++i) {
		//DataType num = dist(gen);
		cout << gen() << endl;
	}
}



int main() {
	//testA();
	//testFile();
	testRSA();
	//testBigint();
	//testBoost();

	//BoostRandom();
	return 0;
}