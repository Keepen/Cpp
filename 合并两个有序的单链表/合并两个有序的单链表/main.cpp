#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

struct list_node {
	int val;
	struct list_node * next;
};


list_node * input_list(void)
{
	int n, val;
	list_node * phead = new list_node();
	list_node * cur_pnode = phead;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &val);
		if (i == 1) {
			cur_pnode->val = val;
			cur_pnode->next = NULL;
		}
		else {
			list_node * new_pnode = new list_node();
			new_pnode->val = val;
			new_pnode->next = NULL;
			cur_pnode->next = new_pnode;
			cur_pnode = new_pnode;
		}
	}
	return phead;
}


list_node * merge_list(list_node * head1, list_node * head2)
{
	//////在下面完成代码
	if (!head1)
		return head2;
	if (!head2)
		return head1;
	list_node* p1 = head1, *p2 = head2;
	list_node* ret = new list_node;
	list_node* tmp = ret;
	list_node* head = nullptr;
	bool flag = true;
	while (p1 && p2) {
		if (p1->val < p2->val) {
			tmp->next = p1;
			p1 = p1->next;
			if (flag) {
				head = tmp->next;
				flag = false;
			}
		}
		else {
			tmp->next = p2;
			p2 = p2->next;
			if (flag) {
				head = tmp->next;
				flag = false;
			}
		}
		tmp = tmp->next;
	}
	while (p1) {
		tmp->next = p1;
		tmp = tmp->next;
		p1 = p1->next;
	}

	while (p2) {
		tmp->next = p2;
		tmp = tmp->next;
		p2 = p2->next;
	}
	return head;
}

void print_list(list_node * head)
{
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	puts("");
}


int main()
{
	list_node * head1 = input_list();
	list_node * head2 = input_list();
	list_node * new_head = merge_list(head1, head2);
	print_list(new_head);
	return 0;
}