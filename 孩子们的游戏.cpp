#include <iostream>
#include <vector>
using namespace std;

//����������n�����ӣ���׼ֵm
//	���ӱ�ţ�0~n - 1
//	������ţ�0~m - 1
//	��ĳ�����ӱ�����m - 1�����֣�ʣ�µ��˼�����0��ʼ������
//	���ʣ�µ��˵ı���Ƕ���

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0) {
			return -1;
		}
		vector<int> tmp(n, 1);
		int cur = -1, count = n, i = 0;
		while (count != 1) {
			if (tmp[i])
				++cur;
			if (count == 1) {
				break;
			}
			else if (cur == m - 1) {
				tmp[i] = 0;
				--count;
				cur = -1;
			}
			++i;
			if (i == n) {
				i = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			if (tmp[i] > 0) {
				return i;
			}
		}
	}
};

void solu() {
	int n, m;
	while (cin >> n >> m) {
		Solution s;
		cout << s.LastRemaining_Solution(n, m) << endl;
	}
}

int main() {
	solu();
	return 0;
}