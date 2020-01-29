#include <iostream>
#include <string>
using namespace std;

void solu() {
	string str;
	while (getline(cin, str)) {
		string::iterator it = str.end() - 1;
		int ret = 0;
		while (it != str.begin() && *it != ' ') {
			++ret;
			--it;
		}
		if (it == str.begin()) {
			ret++;
		}
		cout << ret;
	}
}


int main() {
	solu();
	return 0;
}