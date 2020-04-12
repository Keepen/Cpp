#include <iostream>
using namespace std;

//������������һ�Ŷ���������ת����һ��˫����������

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
	TreeNode* last = nullptr;
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr) {
			return nullptr;
		}

		TreeNode* head = Convert(pRootOfTree->left);
		if (head == nullptr) {
			head = pRootOfTree;
		}

		pRootOfTree->left = last;
		if (last) {
			last->right = pRootOfTree;
		}
		last = pRootOfTree;
		Convert(pRootOfTree->right);
		return head;
	}
};

int main() {
	return 0;
}



