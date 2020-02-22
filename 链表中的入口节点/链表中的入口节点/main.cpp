#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

#if 1
//˼·����ϣ����
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		unordered_map<ListNode*, int> key;
		ListNode* cur = pHead;
		while (cur) {
			if (key[cur] == 1) {
				return cur;
			}
			++key[cur];
			cur = cur->next;
		}
		return cur;
	}
};

int main() {
	return 0;
}



#endif


#if 0
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
#endif