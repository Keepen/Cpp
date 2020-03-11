#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//输入：多个创建目录
//输出：按字典序输出，递归创建层级目录的命令


void solu() {
	int n;
	while (cin >> n) {
		vector<string> dir_list;
		bool flag = true;
		while (n--) {
			string tmp;
			getline(cin, tmp);
			if (flag) {
				++n;
				flag = false;
				continue;
			}
			dir_list.push_back(tmp);
		}
		sort(dir_list.begin(), dir_list.end());
		size_t size = dir_list.size();
		vector<string> ret;
		if (size > 1) {
			for (size_t i = 1; i < size; ++i) {
				while (i < dir_list.size() && dir_list[i].find(dir_list[i - 1]+'/') != string::npos) {
					++i;
				}
				ret.push_back(dir_list[i - 1]);
			}
			size_t rsize = ret.size();
			if (ret[rsize - 1] != dir_list[size - 1]) {
				ret.push_back(dir_list[size - 1]);
			}
		}
		else if (size == 1) {
			cout << "mkdir -p " << dir_list[0] << endl << endl;
			continue;
		}
		for (size_t i = 0; i < ret.size(); ++i) {
			cout << "mkdir -p " << ret[i] << endl;
		}
		cout << endl;
	}
}


int main() {
	solu();
	return 0;
}