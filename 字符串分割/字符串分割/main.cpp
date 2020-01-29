#include <iostream>
#include <string>
#include <vector>
using namespace std;

//������������������ַ�������8��һ����зָ����8���ĺ��油0
//		�����ŵ��ַ�������



void solu() {
	string s;
	vector<string> v;
	while (cin >> s) {
		if (s.size() == 1 && s[0] == '#') {
			break;
		}
		else if (s.size() < 8) {
			string tmp(s.begin(), s.end());
			int left = 8 - s.size();
			while (left--) {
				tmp += '0';
			}
			v.push_back(tmp);
		}
		else if (s.size() == 8) {
			string tmp(s.begin(), s.end());
			v.push_back(tmp);
		}
		else {
			int sz = 0, left = s.size();
			while (left > 8) {
				string tmp(s.begin() + sz, s.begin() + sz + 8);
				v.push_back(tmp);
				sz += 8;
				left -= 8;
			}
			int ret = 8 - left;
			string tmp(s.begin() + sz, s.end());
			while (ret--) {
				tmp += '0';
			}
			v.push_back(tmp);
		}
	}
	for (auto& e : v) {
		cout << e << endl;
	}
}

int main() {
	solu();
	return 0;
}