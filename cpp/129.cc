/*
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
//	int sumNumbers(TreeNode* root) {
//		if (root == nullptr) {
//			return 0;
//		}
//		int sum = 0;
//		queue<TreeNode *> que;
//		que.push(root);
//		while (!que.empty()) {
//			TreeNode * node = que.front();
//			que.pop();
//			if (node->left == nullptr && node->right == nullptr) {
//				sum += node->val;
//				continue;
//			}
//			if (node->left) {
//				node->left->val = node->val * 10 + node->left->val;
//				que.push(node->left);
//			}
//			if (node->right) {
//				node->right->val = node->val * 10 + node->right->val;
//				que.push(node->right);
//			}
//		}
//		return sum;
//	}
//};
//


