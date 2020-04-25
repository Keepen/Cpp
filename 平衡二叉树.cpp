#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
//��������������һ�Ŷ��������ж��Ƿ���ƽ�������
//˼·��
//	1.�������������߶�
//	2.����ֵ��<=1���������������ֱ���ƽ����������򷵻���


struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
};


class Solution {
public:
	int dep(TreeNode* pRoot) {
		if (pRoot == nullptr) {
			return 0;
		}
		int left = dep(pRoot->left) + 1;
		int right = dep(pRoot->right) + 1;
		return max(left, right);
	}
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == nullptr) {
			return true;
		}
		return (abs(dep(pRoot->left) - dep(pRoot->right)) <= 1) &&
			IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}
};


int main() {
	return 0;
}