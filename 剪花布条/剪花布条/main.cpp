// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

//����������ĸ��s1���Ӵ�s2
//	��ĸ���в����ж��ٸ��Ӵ�



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