#include <iostream>
#include <vector>
using namespace std;
//问题描述：判断vector内是否是某二叉搜索树的后序遍历序列
//	思路：
//		1.二叉搜索树的性质：左 < 根 < 右
//		2.在这里需要注意的是：没有说是平衡的二叉搜索树，故只需要满足性质即可
//		3.由于是后序遍历--左右根，则只需要判定根前面的有没有发生畸变 
//			1）比根大突然小
//			2）比根小，比根大后又突然小


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
		cout << "请输入节点的数目：";
		cin >> n;
		if (n == 0) {
			break;
		}
		ret.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> ret[i];
		}
		Solution s;
		cout << "是否是某二叉搜索树的后序遍历序列：" << s.VerifySquenceOfBST(ret) << endl;
	}
}


int main() {
	test();
	return 0;
}