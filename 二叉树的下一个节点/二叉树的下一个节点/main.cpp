#include <iostream>
using namespace std;

//中序遍历的下一个结果：
//	思路：
//		1.如果有右子树，返回右子树的最左节点
//		2.没有右子树，找到该节点不是其父节点的左孩子的父节点


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode* cur = pNode;
		if (pNode->right) {
			cur = pNode->right;
			if (!cur->left) {
				return cur;
			}
			while (cur->left && cur->left->left) {
				cur = cur->left;
			}
			return cur->left;
		}
		else {
			if (cur->next && cur == cur->next->left) {
				return cur->next;
			}
			while (cur) {// && cur == cur->next->right){
				if (cur->next && cur == cur->next->left) {
					return cur->next;
				}
				cur = cur->next;
			}
			return cur;
		}
	}
};


int main() {
	return 0;
}