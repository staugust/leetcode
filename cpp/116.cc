/*
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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


////Definition for binary tree with next pointer.
//struct TreeLinkNode {
// int val;
// TreeLinkNode *left, *right, *next;
// TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
//};
//
//class Solution {
//public:
//	void connect(struct TreeLinkNode *root) {
//		// Rule 1. node->left->next  = node->right
//		// Rule 2. node->right->next = node->next->left
//
//		if (root == NULL) return;
//
//		struct TreeLinkNode* node = root;
//		struct TreeLinkNode* next = root->left;
//
//		while (next) {
//			node->left->next = node->right;
//
//			if (node->next) {
//				// Goto next subtree
//				node->right->next = node->next->left;
//				node = node->next;
//			}
//			else {
//				// Goto next level
//				node = next;
//				next = next->left;
//			}
//		}
//	}
//};