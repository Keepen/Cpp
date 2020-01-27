#include <iostream>
using namespace std;

//�����������һ�������
//	˼·��
//		1.�����������������������������ڵ�
//		2.û�����������ҵ��ýڵ㲻���丸�ڵ�����ӵĸ��ڵ�


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode* cur = pNode;
		if (pNode->right) {
			cur = pNode->right;
			if (!cur->left) {
				return cur;
			}
			while (cur->left && cur->left->left) {
				cur = cur->left;
			}
			return cur->left;
		}
		else {
			if (cur->next && cur == cur->next->left) {
				return cur->next;
			}
			while (cur) {// && cur == cur->next->right){
				if (cur->next && cur == cur->next->left) {
					return cur->next;
				}
				cur = cur->next;
			}
			return cur;
		}
	}
};


int main() {
	return 0;
}