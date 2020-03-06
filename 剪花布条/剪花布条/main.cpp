// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

//问题描述：母串s1，子串s2
//	在母串中查找有多少个子串



void solu() {
	string s1, s2;
	while (cin >> s1 >> s2) {

		size_t pos = 0;
		int ret = 0;
		string tmp(s1);
		pos = tmp.find(s2);
		size_t place = pos;
		while (pos != string::npos) {
			++ret;
			pos += s2.size();
			place += pos;
			if (place >= s1.size()) {
				break;
			}
			tmp = string(tmp.begin() + pos, tmp.end());
			pos = tmp.find(s2);
		}
		cout << ret << endl;
	}
}



int main() {
	solu();
	return 0;
}