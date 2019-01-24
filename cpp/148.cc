/*
 * https://leetcode.com/problems/sort-list/
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

/*
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * mergeList(ListNode * p1, ListNode * p2) {
		if (p1 && p2) {
			ListNode * root = nullptr;
			if (p1->val < p2->val) {
				root = p1;
				p1 = p1->next;
			}
			else {
				root = p2;
				p2 = p2->next;
			}
			ListNode * cur = root;
			while (p1 && p2) {
				if (p1->val < p2->val) {
					cur->next = p1;
					p1 = p1->next;
				}
				else {
					cur->next = p2;
					p2 = p2->next;
				}
				cur = cur->next;
			}
			if (p1) {
				cur->next = p1;
			}
			else if(p2){
				cur->next = p2;
			}
			else {
				cur->next = nullptr;
			}
			return root;
		}
		else if (p1) {
			return p1;
		}
		else if (p2) {
			return p2;
		}
		else {
			
		}
		return nullptr;
	}
	ListNode* sortList(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		if (head->next == nullptr) {
			return head;
		}
		ListNode * p = head;
		ListNode * q = head->next;
		while (q && q->next) {
			p = p->next;
			q = q->next->next;
		}
		auto p2 = sortList(p->next);
		p->next = nullptr;
		auto p1 = sortList(head);
		return mergeList(p1, p2);
	}
};

int main() {
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(2);
	ListNode * l3 = new ListNode(3);
	ListNode * l4 = new ListNode(4);
	l4->next = l2;
	l2->next = l1;
	l1->next = l3;
	Solution s;
	ListNode * p = s.sortList(l4);
	cout << p->val << endl;

	return 0;
}

*/