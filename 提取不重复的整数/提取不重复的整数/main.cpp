#include <iostream>
#include <vector>
using namespace std;

//��������������һ���������������ִӺ���ǰ��λ�����������ͬ������ֻ�����һ��


void solu() {
	int n;
	while (cin >> n) {
		int arr[10] = { 0 };
		int tmp = n;
		vector<int> ans;
		while (tmp) {
			arr[tmp % 10]++;
			if (arr[tmp % 10] == 1) {
				ans.push_back(tmp % 10);
			}
			tmp /= 10;
		}
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i];
		}
		cout << endl;
	}
}

int main() {
	solu();
	return 0;
}