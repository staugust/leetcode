/*
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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


//Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution230 {
//public:
//
//	void inOrder(TreeNode * root, vector<int> & vec, int k) {
//		if (root == nullptr) {
//			return;
//		}
//		inOrder(root->left, vec, k);
//		vec.push_back(root->val);
//		if (vec.size() >= k) {
//			return;
//		}
//		inOrder(root->right, vec, k);
//	}
//
//	int kthSmallest(TreeNode* root, int k) {
//		vector<int> vec;
//		inOrder(root, vec, k);
//		return vec[k - 1];
//	}
//};