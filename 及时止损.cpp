#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int key(vector<int>&v, int pos, int m, int days) {
	int ret = 0;
	while (m--) {
		ret += days * v[pos];
		pos--;
	}
	return ret;
}


void solu() {
	int n, m, q;
	while (cin >> n >> m) {
		vector<int> v(n + 1, 0);
		for (size_t i = 1; i <= n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cin >> q;
		while (q--) {
			int ret = 0;
			int ques;
			cin >> ques;
			vector<int> vs(ques + 1, 0);
			for (int i = 1; i <= ques; ++i)
				vs[i] = v[i];
			int size = ques;
			int days = 1;
			while (ques > 0) {
				int tmp = ques >= m ? m : ques;
				ret += key(vs, size, tmp, days);
				ques -= m;
				days++;
				size -= m;
			}
			cout << ret << endl;
		}
	}
}


int main() {
	solu();
	return 0;
}