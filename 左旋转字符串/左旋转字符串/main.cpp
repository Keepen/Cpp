#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.size() < 2) {
			return str;
		}
		int count = n % str.size();
		string s1(str.begin(), str.begin() + count);
		string s2(str.begin() + count, str.end());
		return s2 + s1;
	}
};

void test() {
	string str;
	int n = 0;
	while (cin >> str >> n) {
		Solution s;
		cout << s.LeftRotateString(str, n);
	}
}

int main() {
	test();
	system("pause");
	return 0;
}