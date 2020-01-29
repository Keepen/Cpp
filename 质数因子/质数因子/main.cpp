#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool isPrime(int number) {
	if (number == 2) {
		return true;
	}
	for (int i = 2; i <= pow(number, 0.5); ++i) {
		if (number % i == 0)
			return false;
	}
	return true;
}

void solu() {
	long k;
	while (cin >> k) {
		if (k < 4) {
			cout << k << " ";
			continue;
		}
		vector<int> ret;
		while (k != 1) {
			for (int i = 2; i <= k; ++i) {
				if (k % i == 0) {
					if (isPrime(i)) {
						ret.push_back(i);
						k /= i;
					}
				}
			}
		}
		sort(ret.begin(), ret.end());
		for (auto& e : ret) {
			cout << e << " ";
		}
	}
}

int main() {
	solu();
	return 0;
}
