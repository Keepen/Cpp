// 问题描述：二叉树的右视图
// 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

// 示例：

// 输入: [1,2,3,null,5,null,4]
// 输出: [1, 3, 4]
// 解释:
 
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* front = nullptr;
        int size = 0;
        while(!q.empty()){
            size = q.size();
            while(size--){
                front = q.front();
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ret.push_back(front->val);    //每层遍历完的时候
        }
        return ret;
    }
};

int main(){
    return 0;
}