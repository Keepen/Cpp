#include <iostream>
#include <map>
using namespace std;

//map的迭代器失效的问题：删除map中val值为5的倍数的元素
//	直接删除，会导致迭代器直接指向end，
//	正确的做法是，先让迭代器自增指向下一个，再删除原来的目标


void print(map<int, int>& m) {
	map<int, int>::iterator it = m.begin();
	while (it != m.end()) {
		cout << (*it).second << " ";
		++it;
	}
	cout << endl;
}

void deleteVal(map<int, int>&m, int n) {
	map<int, int>::iterator it = m.begin();
	//for (; it != m.end(); it++) {
	//	if ((*it).second % 5 == 0) {
	//		m.erase(it);
	//	}
	//}
	while (it != m.end()) {
		if ((*it).second % 5 == 0) {
			m.erase(it++);
		}
		else {
			++it;
		}
	}
}



void solu() {
	map<int, int> m;
	for (int i = 1; i < 16; ++i) {
		m[i] = i;
	}
	print(m);

	deleteVal(m, 5);
	print(m);
}


int main() {
	solu();
	return 0;
}