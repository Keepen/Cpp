// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//�ռ����б�
//	���룺
//		1.����n -- ��n���˵�����
//		2.����n���˵�����
//	��� -- �ԡ�, �����������������", " ���ʱ������������������



void solu() {
	int n;
	string sm;
	sm += '"';
	while (cin >> n) {
		vector<string> v;
		bool flag = true;
		while (n--) {
			string name;
			getline(cin, name);
			size_t pos = name.find(',');
			size_t ps = name.find(' ');
			if (pos != string::npos || ps != string::npos) {
				name += sm;
				string tmp = sm;
				tmp += name;
				name = tmp;
			}
			v.push_back(name);
			if (flag) {
				v.clear();
				flag = false;
				n++;
			}
		}
		for (size_t i = 0; i < v.size(); ++i) {
			cout << v[i];
			if (i != v.size() - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}
}



int main() {
	solu();
	return 0;
}
