//问题描述：
//	将一个数字分解成多个质因数之积
// write your code here cpp

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isSim(int a) {
	if (a == 1)
		return false;
	else if (a < 4)
		return true;
	else {
		for (int i = 2; i <= pow(a, 0.5); ++i) {
			if (a % i == 0) {
				return false;
			}
		}
	}
	return true;
}

void solu() {
	int a;
	while (cin >> a) {
		vector<int> key;
		int tmp = a;
		int i = 2;
		while (tmp != 1) {
			if (tmp % i == 0 && isSim(i)) {
				key.push_back(i);
				tmp /= i;
				i = 2;
			}
			else {
				++i;
			}

		}
		cout << a << " = ";
		for (size_t i = 0; i < key.size(); ++i) {
			cout << key[i];
			if (i < key.size() - 1) {
				cout << " * ";
			}
		}
		cout << endl;
	}
}

int main() {
	solu();
	return 0;
}