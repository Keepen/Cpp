// 问题描述：
//  给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）中，
//  按结点数值大小顺序第三小结点的值为4。

#include <iostream>
#include <stack>
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
    vector<TreeNode*> v;
    void mid(TreeNode* pRoot){
        if(pRoot == nullptr){
            return;
        }
        mid(pRoot->left);
        v.push_back(pRoot);
        mid(pRoot->right);
    }
    
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot){
            return nullptr;
        }
        mid(pRoot);
        int len = v.size();
        if(k > len || k < 1){
            return nullptr;
        }
        return v[k - 1];
    }
};

TreeNode* KthNode(TreeNode* pRoot, int k) {
    if (!pRoot || k < 1) {
        return nullptr;
    }
    stack<TreeNode*> s;
    int count = 0;
    s.push(pRoot);
    TreeNode* top = s.top();
    cout << s.top()->val << " ";
    while (!s.empty()) {
        while (top && top->left) {
            s.push(top->left);
            top = top->left;
        }
        ++count;
        top = s.top();
        s.pop();
        if (count == k) {
            return top;
        }
        top = top->right;
        if(top){
            s.push(top);
        }
    }
    return nullptr;
}

void test(){
    TreeNode n1(8);TreeNode n2(6);
    TreeNode n3(10);TreeNode n4(5);
    TreeNode n5(7);TreeNode n6(9);
    TreeNode n7(11);
    n1.left = &n2;n1.right = &n3;
    n2.left = &n4;n2.right = &n5;
    n3.left = &n6;n3.right = &n7;
    TreeNode* node = KthNode(&n1, 5);
    cout << node->val << endl;
}

int main(){
    test();
    return 0;
}