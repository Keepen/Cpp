#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
//将重复的数字只输出一次即可


void solu() {
	int n;
	while (cin >> n) {
		vector<int> ret(n);
		unordered_map<int, int> key;
		for (int i = 0; i < n; ++i) {
			cin >> ret[i];
			key[ret[i]]++;
		}
		sort(ret.begin(), ret.end());
		for (int i = 0; i < n; ++i) {
			if (key[ret[i]] > 1) {
				cout << ret[i] << endl;
				i += key[ret[i]] - 1;
				continue;
			}
			cout << ret[i] << endl;
		}
	}
}
int main() {
	solu();
	return 0;
}