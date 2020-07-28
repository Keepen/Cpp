//问题描述：
//  从尾到头打印链表

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

  struct ListNode {
      int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        if(head == nullptr){
            return ret;
        }
        ListNode* cur = head;
        while(cur){
            ret.push_back(cur->val);
            cur = cur->next;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(){
    return 0;
}