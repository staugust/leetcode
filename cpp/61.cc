/*
 * https://leetcode.com/problems/rotate-list/
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

static auto _ = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution61 {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode * h = head;

		queue<ListNode *> que;
		while (head != nullptr) {
			que.push(head);
			head = head->next;
			if (que.size() > k + 1) {
				que.pop();
			}
		}
		k = k % que.size();
		if ( 0 == k) {
			return h;
		}
		else {
			while (que.size() > k + 1) {
				que.pop();
			}
			que.front()->next = nullptr;
			que.pop();
			que.back()->next = h;
			return que.front();
		}
	}
};