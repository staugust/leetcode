/*
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
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
//
// //Definition for binary tree with next pointer.
//struct TreeLinkNode {
//	int val;
//	TreeLinkNode *left, *right, *next;
//	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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
//		struct TreeLinkNode* next = root->left ? root->left : root->right;
//
//		while (next) {
//			if (node->left && node->right)
//			{
//				node->left->next = node->right;
//				TreeLinkNode * nt = nullptr;
//				TreeLinkNode * cur = node;
//				while (nt == nullptr && cur->next != nullptr) {
//					cur = cur->next;
//					nt = cur->left ? cur->left : cur->right;
//				}
//				if (nt) {
//					node->right->next = nt;
//				}
//				node = cur;
//			}
//			else if (!node->left && node->right) {
//				//left nullptr
//				TreeLinkNode * nt = nullptr;
//				TreeLinkNode * cur = node;
//				while (nt == nullptr && cur->next != nullptr) {
//					cur = cur->next;
//					nt = cur->left ? cur->left : cur->right;
//				}
//				if (nt) {
//					node->right->next = nt;
//				}
//				node = cur;
//			}
//			else if (!node->right && node->left) {
//				//right nullptr
//				TreeLinkNode * nt = nullptr;
//				TreeLinkNode * cur = node;
//				while (nt == nullptr && cur->next != nullptr) {
//					cur = cur->next;
//					nt = cur->left ? cur->left : cur->right;
//				}
//				if (nt) {
//					node->left->next = nt;
//				}
//				node = cur;
//			}
//			else {
//				// left & right all nullptr
//				node = node->next;
//			}
//
//			if (node->next == nullptr) {
//				// Goto next level
//				if (node->left && node->right)
//				{
//					node->left->next = node->right;
//				}
//				node = next;
//				TreeLinkNode * nt = nullptr;
//				TreeLinkNode * cur = node;
//				while (nt == nullptr && cur != nullptr) {
//					nt = cur->left ? cur->left : cur->right;
//					cur = cur->next;
//				}
//				next = nt;
//			}
//		}
//	}
//};