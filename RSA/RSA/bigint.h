#pragma once
#include <iostream>
#include <string>
#include <utility>
class BigInt {
public:
	BigInt(){}
	BigInt(const std::string& num);
	BigInt(const int num);

	BigInt operator+(BigInt& bi);
	BigInt operator-(BigInt& bi);
	BigInt operator*(BigInt& bi);
	BigInt operator/(BigInt& bi);
	BigInt operator%(BigInt& bi);
	friend std::ostream& operator<<(std::ostream& _cout, BigInt& bi);
private:
	std::string add(std::string s1, std::string s2);
	std::string sub(std::string s1, std::string s2);
	std::string mul(std::string s1, std::string s2);
	std::pair<std::string, std::string> dev(std::string s1, std::string s2);
	bool less(std::string& s1, std::string& s2);
	//通过字符串表示
	std::string _number;
};
