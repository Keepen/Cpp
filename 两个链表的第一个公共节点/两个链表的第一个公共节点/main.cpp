#include <iostream>
using namespace std;

//问题描述：找寻两个链表中的第一个公共节点
//	思路：将较长的链表走到和短链表一样长度的位置，开始遍历



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		int count1 = 0, count2 = 0;
		while (p1 || p2) {
			if (p1) {
				count1++;
				p1 = p1->next;
			}
			if (p2) {
				count2++;
				p2 = p2->next;
			}
		}
		int num = count1 - count2;
		p1 = pHead1;
		p2 = pHead2;
		if (num < 0) {
			while (num) {
				p2 = p2->next;
				++num;
			}
		}
		else {
			while (num) {
				p1 = p1->next;
				--num;
			}
		}
		while (p1 && p2) {
			if (p1->val == p2->val) {
				return p1;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		return nullptr;
	}
};

int main() {
	return 0;
}

