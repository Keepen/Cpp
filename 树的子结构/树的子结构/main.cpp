#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
//问题描述：判断两棵二叉树A，B ；B是否是A一棵子树
//	思路：
//		1.利用string保存两棵二叉树的先序遍历的结果
//		2.判断B的先序遍历是否是A的子串即可

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	void first(TreeNode* root, string& s) {
		if (!root) {
			return;
		}
		s += root->val;
		first(root->left, s);
		first(root->right, s);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot1 || !pRoot2) {
			return false;
		}
		string s1, s2;
		first(pRoot1, s1);
		first(pRoot2, s2);
		if (s1.find(s2) != string::npos) {
			return true;
		}
		return false;
	}
};


void test() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	TreeNode f(6);
	TreeNode g(7);
	a.left = &b; a.right = &c;
	b.left = &d; b.right = &e;
	c.left = &f; c.right = &g;
	
	TreeNode b1(2);
	TreeNode d1(4);
	TreeNode e1(5);
	b1.left = &d1; b1.right = &e1;

	Solution s;
	cout << s.HasSubtree(&a, &b1);
}


int main() {
	test();
	return 0;

}