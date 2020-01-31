#include <iostream>
using namespace std;

//思路：利用位运算
//	1.两数的 ^ 的结果就是本为和
//	2.两数的 & 的结果就是产生进位的位 -- 
//	3.利用循环，循环结束的条件就是进位是0 -- 每次将进位的位左移 1 位

class Solution {
public:
	int Add(int num1, int num2)
	{
		int tmp = 0;
		while (num2) {
			tmp = num1;
			num1 ^= num2;
			num2 &= tmp;
			num2 <<= 1;
		}
		return num1;
	}
};


int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		Solution s;
		cout << s.Add(a, b) << endl;
	}
	return 0;
}