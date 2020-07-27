//问题描述：
//  链表中是否带环，带环 -- 找到环的入口节点
//  不带环 -- 返回nullptr

//思路：
//  1.计算环的长度
//  2.快慢指针，快指针先走环长度步，慢指针(从头)再和快指针一起走，直到两者相遇

#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* cur = head, *pre = head;
        int len = 1;
        while(cur){
            pre = pre->next;
            if(cur->next == nullptr){
                return nullptr;
            }
            cur = cur->next->next;
            if(cur == pre){
                ListNode* tmp = pre->next;
                while(tmp != pre){
                    ++len;
                    tmp = tmp->next;
                }
                cur = head;
                while(len--){
                    cur = cur->next;
                }
                pre = head;
                while(cur != pre){
                    pre = pre->next;
                    cur = cur->next;
                }
                return pre;
            }
        }
        return nullptr;
    }
};

int main(){
    return 0;
}