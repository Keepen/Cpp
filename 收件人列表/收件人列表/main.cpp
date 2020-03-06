// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//收件人列表：
//	输入：
//		1.数字n -- 有n个人的名字
//		2.输入n个人的名字
//	输出 -- 以“, ”间隔，若名字中有", " 输出时该名字用引号括起来



void solu() {
	int n;
	string sm;
	sm += '"';
	while (cin >> n) {
		vector<string> v;
		bool flag = true;
		while (n--) {
			string name;
			getline(cin, name);
			size_t pos = name.find(',');
			size_t ps = name.find(' ');
			if (pos != string::npos || ps != string::npos) {
				name += sm;
				string tmp = sm;
				tmp += name;
				name = tmp;
			}
			v.push_back(name);
			if (flag) {
				v.clear();
				flag = false;
				n++;
			}
		}
		for (size_t i = 0; i < v.size(); ++i) {
			cout << v[i];
			if (i != v.size() - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}
}



int main() {
	solu();
	return 0;
}
