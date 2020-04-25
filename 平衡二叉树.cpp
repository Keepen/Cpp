#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
//问题描述：输入一颗二叉树，判断是否是平衡二叉树
//思路：
//	1.先求左右子树高度
//	2.做差值，<=1，并且左右子树分别都是平衡二叉树，则返回真


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