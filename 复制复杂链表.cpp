//问题描述：
//  拷贝一个带随机指针的链表

//思路：
//  1.将拷贝的节点尾插到原链表的每一个节点之后
//  2.拷贝random指针
//  3.断链，提取拷贝的链表


// Definition for a Node.

#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        //1.先拷贝
        Node* cur = head;
        while(cur){
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        //2.置random
        cur = head;
        while(cur){
            if(cur->random){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        //3.断链
        Node* phead = head->next;
        cur = head;
        while(cur){
            Node* copy = cur->next;
            cur->next = copy->next;
            if(copy->next)
                copy->next = copy->next->next;
            cur = cur->next;
        }
        return phead;
    }
};

int main(){
    return 0;
}