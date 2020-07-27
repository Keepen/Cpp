//问题描述：
//  判断两条单链表是否相交，
//  相交 -- 返回相交的位置
//  不相交 -- 返回nullptr

//思路：
//  判断是否相交 -- 遍历两条链表看最后一个节点是否相同
//  相交的位置：让长链表先走到和短链表一样长的位置，最后再一起走
//  判断两个指针指向是否相同

#include <iostream>
#include <math.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        
        ListNode* cur1 = headA, *cur2 = headB;
        int lenA = 1, lenB = 1;
        while(cur1->next){
            cur1 = cur1->next;
            ++lenA;
        }
        while(cur2->next){
            cur2 = cur2->next;
            ++lenB;
        }
        int n = abs(lenA - lenB);
        if(cur1 == cur2){
            cur1 = headA;
            cur2 = headB;
            if(lenA >= lenB){
                while(n--)
                    cur1 = cur1->next;
            }
            else{
                while(n--){
                    cur2 = cur2->next;
                }
            }
            while(cur1 != cur2){
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        }
        return nullptr;
    }
};

int main(){
    return 0;
}