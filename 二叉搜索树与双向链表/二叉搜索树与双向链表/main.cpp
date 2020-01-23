#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//将二叉搜索树抓换成排序链表
//	思路：中序遍历，将节点放在队列内


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
	TreeNode* Convert(TreeNode* pRootOfTree) {
		vector<TreeNode*> v;	//用来存储中序遍历的结果
		stack<TreeNode*> s;
		
	}
};


int main() {
	system("pause");
	return 0;
}