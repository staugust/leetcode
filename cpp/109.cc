/*
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
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

 
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	void _sortedListToBST(TreeNode **bst, ListNode *head, ListNode *tail) {
		if (head == tail) return;
		struct ListNode *p = head, *pMid = head;
		while (p != tail && p->next && p->next != tail) {
			p = p->next->next;
			pMid = pMid->next;
		}
		*bst = new TreeNode(pMid->val);
		_sortedListToBST(&(*bst)->left, head, pMid);
		_sortedListToBST(&(*bst)->right, pMid->next, tail);
	}

	TreeNode* sortedListToBST(ListNode* head) {
		TreeNode *bst = NULL;
		_sortedListToBST(&bst, head, NULL);
		return bst;
	}
};

*/