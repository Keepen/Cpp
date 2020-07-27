//问题描述：
//  返回链表中倒数第K个节点

//思路：
//  快慢指针：快指针先走K步，慢指针再走知道快指针走到链表尾部


#include <iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* pre = head, *cur = head;
        int m = k;
        while(m--){
            cur = cur->next;
        }
        while(cur){
            pre = pre->next;
            cur = cur->next;
        }
        return pre;
    }
};

int main(){
    return 0;
}