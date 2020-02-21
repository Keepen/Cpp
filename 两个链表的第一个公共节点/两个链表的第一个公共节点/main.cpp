#include <iostream>
using namespace std;

//������������Ѱ���������еĵ�һ�������ڵ�
//	˼·�����ϳ��������ߵ��Ͷ�����һ�����ȵ�λ�ã���ʼ����



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

