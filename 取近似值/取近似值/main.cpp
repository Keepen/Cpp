#include <iostream>
using namespace std;

//问题描述：将浮点数四舍五入

int main() {
	double k;
	while (cin >> k) {
		int x = (int)k;
		double ret = k - x;
		if (ret * 2 >= 1) {
			cout << x + 1 << endl;
			continue;
		}
		cout << x << endl;
	}
	return 0;
}