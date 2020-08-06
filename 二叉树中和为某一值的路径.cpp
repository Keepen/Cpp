//问题描述：
//  输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
//  路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

//思路：dfs

#include <iostream>
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
    vector<int> path;
    vector<vector<int>> res;
    void find(TreeNode* root, int num){
        if(root == nullptr){
            return;
        }
        path.push_back(root->val);
        if(!root->left && !root->right && num == root->val){
            res.push_back(path);
        }
        else{
            if(root->left){
                find(root->left, num - root->val);
            }
            if(root->right){
                find(root->right, num - root->val);
            }
        }
        path.pop_back();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        find(root, expectNumber);
        return res;
    }
};

int main(){
    return 0;
}