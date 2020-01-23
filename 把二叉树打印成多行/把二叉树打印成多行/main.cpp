#include <iostream>
#include <queue>
#include <vector>
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> ret;
		queue<TreeNode*> q;
		if (!pRoot) {
			return ret;
		}
		q.push(pRoot);
		ret.push_back(vector<int>(1, pRoot->val));
		while (!q.empty()) {
			int len = q.size();
			vector<int> tmp;
			while (len--) {
				TreeNode* top = q.front();
				q.pop();
				if (top->left) {
					q.push(top->left);
					tmp.push_back(top->left->val);
				}
				if (top->right) {
					q.push(top->right);
					tmp.push_back(top->right->val);
				}
			}
			if (tmp.size()) {
				ret.push_back(tmp);
			}
		}
		return ret;
	}
};


int main() {
	system("pause");
	return 0;
}