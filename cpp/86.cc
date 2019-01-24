/*
 * https://leetcode.com/problems/partition-list/
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
	ListNode* partition(ListNode* head, int x) {
		ListNode lt(0), * pl = &lt;
		ListNode gt(0), * pg = &gt;
		ListNode * tmp = head;
		while (tmp) {
			if (tmp->val >= x) {
				pg->next = tmp;
				pg = pg->next;
			}
			else {
				pl->next = tmp;
				pl = pl->next;
			}
			tmp = tmp->next;
		}
		pl->next = gt.next;
		pg->next = nullptr;
		return lt.next;
	}
};

*/