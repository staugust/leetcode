/*
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/
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
//	string smallestFromLeaf(TreeNode* root) {
//		if (root == nullptr) return "";
//		string l = smallestFromLeaf(root->left) + (char)(root->val + 'a');
//		string r = smallestFromLeaf(root->right) + (char)(root->val + 'a');
//		if (root->left == nullptr) return r;
//		if (root->right == nullptr) return l;
//		if (l.compare(r) < 0) return l;
//		else return r;
//	}
//};