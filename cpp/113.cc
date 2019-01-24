/*
 * https://leetcode.com/problems/path-sum-ii/
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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (!root) return {};
		vector<vector<int>> bag;
		vector<int> acc;
		helper(root, bag, acc, 0, sum);
		return bag;
	}
	void helper(TreeNode *root, vector<vector<int>>& bag, vector<int>& acc, int curSum, int target) {
		if (!root->left && !root->right) {
			if (curSum + root->val == target) {
				acc.emplace_back(root->val);
				bag.emplace_back(acc);
				acc.pop_back();
			}
			return;
		}
		acc.emplace_back(root->val);
		if (root->left) helper(root->left, bag, acc, curSum + root->val, target);
		if (root->right) helper(root->right, bag, acc, curSum + root->val, target);
		acc.pop_back();
	}

};

*/