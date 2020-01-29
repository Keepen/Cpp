#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
//问题描述：将输入的16进制数字转换为10进制数字输出
//	例：0x10 --》 16


void solu() {
	string s;
	unordered_map<char, int> key;
	for (int i = 0; i < 10; ++i) {
		key[i + '0'] = i;
	}
	key['A'] = 10;
	key['B'] = 11;
	key['C'] = 12;
	key['D'] = 13;
	key['E'] = 14;
	key['F'] = 15;
	while (cin >> s) {
		string::iterator it = s.end() - 1;
		int ret = 0, count = 1;
		while (it != (s.begin() + 1)) {
			ret += key[*it] * count;
			count *= 16;
			--it;
		}
		cout << ret << endl;
	}
}

int main() {
	solu();
	return 0;
}