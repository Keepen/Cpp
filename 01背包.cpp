#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solu() {
	int n, Max;
	while (cin >> n >> Max) {
		vector<int> w(n + 1, 0);
		vector<int> v(n + 1, 0);
		vector<vector<int>> ret(n + 1, vector<int>(Max + 1, 0));
		
		for (int i = 1; i <= n; ++i) {
			int tmp;
			cin >> tmp;
			w[i] = tmp;
		}
		for (int i = 1; i <= n; ++i) {
			int tmp;
			cin >> tmp;
			v[i] = tmp;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= Max; ++j) {
				if (j < w[i])
					ret[i][j] = ret[i - 1][j];
				else {
					ret[i][j] = max(ret[i - 1][j], ret[i - 1][j - w[i]] + v[i]);
				}
			}
		}
		cout << ret[n][Max] << endl;
	}
}

int main() {
	solu();
	return 0;
}