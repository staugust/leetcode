/*
 * https://leetcode.com/problems/maximum-binary-tree-ii/
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
//		if (root == nullptr)
//			return new TreeNode(val);
//		//here U must ensure the seq never chagne , How to do it ? U must carefully consider this question.
//		else if (val > root->val)
//		{
//			TreeNode * retv = new TreeNode(val);
//			retv->left = root;
//			return retv;
//		}
//
//		root->right = insertIntoMaxTree(root->right, val);
//		return root;
//	}
//};