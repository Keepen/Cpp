#include <iostream>
using namespace std;

//删除所有重复的节点
//	思路：三个遍历指针pre, cur, next
//		1.首先建立一个伪头节点ret, ret->next = pHead;并且让pre只想ret
//		2.遍历链表：
//			1）如果碰到了重复的节点，移动next指针直到遇到不相同的节点,
//				并且让pre->next = next; 再让cur = next
//			2）节点不重复，所有遍历指针后移即可
//			3)更新next的值一定是无论有无重复节点都要进行的工作
//		3.返回ret->next就是目标节点



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (!pHead || !pHead->next) {
			return pHead;
		}
		ListNode* ret = new ListNode(0);
		ret->next = pHead;
		ListNode* pre = ret;
		ListNode* cur = pHead;
		ListNode* next = cur->next;
		while (cur && next) {
			if (cur->val == next->val) {
				while (next && next->val == cur->val) {
					next = next->next;
				}
				pre->next = next;
				cur = next;
			}
			else {
				pre = cur;
				cur = next;
			}
			next = next->next;
		}
		pHead = ret->next;	
		return pHead;
	}
};

void print(ListNode* head) {
	ListNode* cur = head;
	while (cur) {
		cout << cur->val;
		if (cur->next) {
			cout << "->";
		}
		cur = cur->next;
	}
	cout << endl;
}

void test() {
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(3);
	ListNode n5(4);
	ListNode n6(4);
	ListNode n7(5);
	n1.next = &n2; n2.next = &n3;
	n3.next = &n4; n4.next = &n5;
	n5.next = &n6; n6.next = &n7;
	print(&n1);
	Solution s;
	ListNode* ret = s.deleteDuplication(&n1);
	print(ret);
}

int main() {
	test();
	return 0;
}