#include <iostream>
#include <queue>
using namespace std;

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
	int TreeDepth(TreeNode* pRoot)
	{
		if (!pRoot) {
			return 0;
		}
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return (left > right ? left : right) + 1;
	}

	//�ǵݹ飺���ò������
	int depth(TreeNode* pRoot) {
		if (!pRoot) {
			return 0;
		}
		queue<TreeNode*> q;
		q.push(pRoot);
		int level = 0;
		while (!q.empty()) {
			int len = q.size();		//���ڶ����ڵ�Ԫ����Ŀ���ǵ�ǰ�����Ľڵ���Ŀ
			level++;
			while (len--) {
				TreeNode* top = q.front();
				q.pop();
				if (top->left) {
					q.push(top->left);
				}
				if (top->right) {
					q.push(top->right);
				}
			}
		}
		return level;
	}
};


int main() {
	system("pause");
	return 0;
}