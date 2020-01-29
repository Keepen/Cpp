#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void solu() {
	string str;
	while (cin >> str) {
		unordered_map<char, int> ret;
		for (auto& e : str) {
			ret[e]++;
		}
		char key;
		cin >> key;
		if (key >= 'A' && key <= 'Z') {
			int ans = ret[key] + ret[key + 32];
			cout << ans;
			continue;
		}
		else if (key >= 'a' && key <= 'z') {
			int ans = ret[key] + ret[key - 32];
			cout << ans;
			continue;
		}
		cout << ret[key];
	}
}

int main() {
	solu();
	return 0;
}