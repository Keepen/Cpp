#include <iostream>
using namespace std;

//������������Ѱ�����л�����ڽڵ�
//	˼·������˼·
//		����ָ�룬��ָ�����



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
