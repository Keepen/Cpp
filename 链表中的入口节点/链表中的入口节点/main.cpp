#include <iostream>
using namespace std;

//问题描述：找寻链表中环的入口节点
//	思路：断链思路
//		快慢指针，慢指针断链



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead->next) {
			return nullptr;
		}
		ListNode* previous = pHead, *front = pHead->next;
		while (front) {
			previous->next = nullptr;
			previous = front;
			front = front->next;
		}
		return previous;
	}
};

int main() {
	return 0;
}
