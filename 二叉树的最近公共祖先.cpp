// 问题描述：
//  给定义二叉树，给定两个节点，求这两个节点的最近公共祖先
//  祖先可以是自己

// 非递归思路：
//  1.求出每个节点的路径（不带多余节点的路径）
//  2.比对两条路径，求第一个相同的节点

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    void getPath(TreeNode* root, TreeNode* dst, vector<TreeNode*>& ret){
        stack<TreeNode*> s;
        TreeNode* cur = root, *prev = nullptr;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                ret.push_back(cur);
                if(cur == dst){
                    return;
                }
                cur = cur->left;
            }
            cur = s.top();
            if(!cur->right || cur->right == prev){
                s.pop();
                ret.pop_back();
                prev = cur;
                cur = nullptr;
            }
            else{
                cur = cur->right;
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> left, right;
        getPath(root, p, left);
        getPath(root, q, right);
        int n = min(left.size(), right.size());
        /*for(int i = 0;i < left.size();++i){
            cout << left[i]->val << " ";
        }
        cout << endl;
        for(int i = 0;i < right.size();++i){
            cout << right[i]->val << " ";
        }
        cout << endl;*/
        TreeNode* last = nullptr;
        for(int i = 0;i < n;++i){
            if(left[i]->val != right[i]->val){
                return last;
            }
            last = left[i];
        }
        return last;
    }
};


void test(){

}


int main(){
    test();
    return 0;
}