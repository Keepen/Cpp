#include <iostream>
using namespace std;

//��������������������������

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