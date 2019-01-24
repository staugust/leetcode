/*
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
////Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	void flatten(TreeNode* root) {
//		TreeNode *cur = root, *pred;
//		while (cur) {
//			if (cur->left) {
//				pred = cur->left;
//				while (pred->right) pred = pred->right;
//				pred->right = cur->right;
//				cur->right = cur->left;
//				cur->left = nullptr;
//			}
//			cur = cur->right;
//		}
//	}
//};
