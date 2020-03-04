// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//斐波那契凤尾：
//	如果超过了6位数字：就只输出它的后六位
//	需要注意的是：如果超过了六位数字，但是后六位是0开头的，那么需要将这个0输出
//	判断一下，然后采用字符串输出




void solu() {
	int n;
	vector<int> v(100001, 0);
	v[0] = 1;
	v[1] = 1;
	int key = 0; bool flag = true;
	for (size_t i = 2; i < v.size(); ++i) {
		v[i] = v[i - 1] + v[i - 2];
		if (flag && v[i] > 999999) {
			key = i;
			flag = false;
		}
		v[i] %= 1000000;
	}
	while (cin >> n) {
		if (n < key) {
			cout << v[n] << endl;
			continue;
		}
		string s = "0000000";
		string tmp;
		int temp = v[n];
		while (temp) {
			tmp += temp % 10 + '0';
			temp /= 10;
		}
		string::iterator t = tmp.end() - 1;
		while (t != tmp.begin()) {
			s += *t;
			--t;
		}
		s += *t;
		string::iterator it = s.end() - 6;
		while (it != s.end()) {
			cout << *it;
			it++;
		}
		cout << endl;
	}
}


int main() {
	solu();
	return 0;
}