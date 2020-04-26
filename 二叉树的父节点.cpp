//问题描述：满二叉树编号从1开始
//	输入：节点编号x，深度d
//	输出：该节点在d层的父节点

#include <iostream>
#include <math.h>
using namespace std;

int lev(int i) {
	if (i <= 1) {
		return 1;
	}
	int tmp = 1, l = 1;
	while (tmp < i) {
		tmp += pow(2, l);
		++l;
	}
	return l;
}

void solu() {
	int n, d;
	while (cin >> n >> d) {
		int cur_lev = lev(n);	//表示当前编号的层数
		if (d > cur_lev) {
			cout << -1 << endl;
			continue;
		}
		if (d == 1) {
			cout << 1 << endl;
		}
		int ret = n;
		while (cur_lev > d && ret > 0) {
			ret /= 2;
			--cur_lev;
		}
		cout << ret << endl;
	}
}

int main() {
	solu();
	return 0;
}
