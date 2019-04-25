/*
 * https://leetcode.com/problems/distribute-coins-in-binary-tree/
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

//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//
//class Solution {
//public:
//	int res = 0;
//	int distributeCoins(TreeNode* root) {
//		dfs(root);
//		return res;
//	}
//	int dfs(TreeNode* root) {
//		if (!root) return 0;
//		int left = dfs(root->left), right = dfs(root->right);
//		res += abs(left) + abs(right);
//		return root->val + left + right - 1;
//	}
//
//};