#include <iostream>
using namespace std;

//˼·������λ����
//	1.������ ^ �Ľ�����Ǳ�Ϊ��
//	2.������ & �Ľ�����ǲ�����λ��λ -- 
//	3.����ѭ����ѭ���������������ǽ�λ��0 -- ÿ�ν���λ��λ���� 1 λ

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