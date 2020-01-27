#include <iostream>
using namespace std;

//ɾ�������ظ��Ľڵ�
//	˼·����������ָ��pre, cur, next
//		1.���Ƚ���һ��αͷ�ڵ�ret, ret->next = pHead;������preֻ��ret
//		2.��������
//			1������������ظ��Ľڵ㣬�ƶ�nextָ��ֱ����������ͬ�Ľڵ�,
//				������pre->next = next; ����cur = next
//			2���ڵ㲻�ظ������б���ָ����Ƽ���
//			3)����next��ֵһ�������������ظ��ڵ㶼Ҫ���еĹ���
//		3.����ret->next����Ŀ��ڵ�



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