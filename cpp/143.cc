/*
 * https://leetcode.com/problems/reorder-list/
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
#include <stack>

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
	void reorderList(ListNode* head) {
		ListNode * p = head;
		if (p == nullptr) {
			return;
		}
		ListNode * q = head->next;
		if (q == nullptr) {
			return;
		}
		int k = 1;
		while (q && q->next) {
			p = p->next;
			q = q->next->next;
			k += 1;
		}
		if (q == nullptr) {
			k -= 1;
		}

		vector<ListNode *> stk(k);
		p = p->next;
		while (p) {
			stk[--k] = p;
			p = p->next;
		}
		ListNode * root = head;
		while (k < stk.size()) {
			p = stk[k++];
			p->next = root->next;
			root->next = p;
			root = p->next;
		}
		root->next = nullptr;
	}
};

*/