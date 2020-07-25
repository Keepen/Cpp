//问题描述：按之字打印二叉树
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
};

vector<vector<int>> Print(TreeNode* pRoot){
    vector<vector<int>> ret;
    if(pRoot == nullptr){
        return ret;
    }
    queue<TreeNode*> q;
    q.push(pRoot);
    int lev = 1;
    while(!q.empty()){
        TreeNode* node = q.front();
        int size = q.size();
        vector<int> tmp;
        while(size--){
            q.pop();
            tmp.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            node = q.front();
        }
        if(lev & 1){
            ret.push_back(tmp);
        }
        else{
            reverse(tmp.begin(), tmp.end());
            ret.push_back(tmp);
        }
        ++lev;
    }
    return ret;
}

int main(){
    return 0;
}
