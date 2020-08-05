

//问题描述：
//  判断以额二叉树是否是对称的 -- 是否与其镜像是相同的

#include <iostream>
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
    bool isMirror(TreeNode* left, TreeNode* right){
        if(left == nullptr){
            return right == nullptr;
        }
        if(right == nullptr){
            return false;
        }
        if(left->val != right->val){
            return false;
        }
        return isMirror(left->right, right->left) &&
            isMirror(left->left, right->right);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == nullptr){
            return true;
        }
        return isMirror(pRoot->left, pRoot->right);
    }

};

int main(){
    return 0;
}