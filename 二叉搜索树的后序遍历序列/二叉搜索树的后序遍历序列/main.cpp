#include <iostream>
#include <vector>
using namespace std;
//�����������ж�vector���Ƿ���ĳ�����������ĺ����������
//	˼·��
//		1.���������������ʣ��� < �� < ��
//		2.��������Ҫע����ǣ�û��˵��ƽ��Ķ�������������ֻ��Ҫ�������ʼ���
//		3.�����Ǻ������--���Ҹ�����ֻ��Ҫ�ж���ǰ�����û�з������� 
//			1���ȸ���ͻȻС
//			2���ȸ�С���ȸ������ͻȻС


class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		size_t size = sequence.size();
		if (!size) {
			return false;
		}
		int root = sequence[size - 1];
		int left = 0, right = 0;
		int count = 0;
		while (left < size) {
			if (sequence[left] > root) {
				++count;
			}
			if (count > 0 && sequence[left] < root) {
				return false;
			}
			++left;
		}
		return true;
	}
};

void test() {
	vector<int> ret;
	int n;
	while (1) {
		cout << "������ڵ����Ŀ��";
		cin >> n;
		if (n == 0) {
			break;
		}
		ret.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> ret[i];
		}
		Solution s;
		cout << "�Ƿ���ĳ�����������ĺ���������У�" << s.VerifySquenceOfBST(ret) << endl;
	}
}


int main() {
	test();
	return 0;
}