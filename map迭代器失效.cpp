#include <iostream>
#include <map>
using namespace std;

//map�ĵ�����ʧЧ�����⣺ɾ��map��valֵΪ5�ı�����Ԫ��
//	ֱ��ɾ�����ᵼ�µ�����ֱ��ָ��end��
//	��ȷ�������ǣ����õ���������ָ����һ������ɾ��ԭ����Ŀ��


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