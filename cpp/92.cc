/*
 *
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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* new_head = new ListNode(0);
		new_head->next = head;
		ListNode* pre = new_head;
		for (int i = 0; i < m - 1; i++)
			pre = pre->next;
		ListNode* cur = pre->next;
		for (int i = 0; i < n - m; i++) {
			ListNode* move = cur->next;
			cur->next = move->next;
			move->next = pre->next;
			pre->next = move;
		}
		return new_head->next;
	}
};

*/