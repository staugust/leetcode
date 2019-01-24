/*
 *
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

 
// //Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// 
//class BSTIterator {
//public:
//
//	queue<int> vec;
//
//	void dfs(TreeNode * root) {
//		if (root == nullptr) {
//			return;
//		}
//		dfs(root->left);
//		vec.push(root->val);
//		dfs(root->right);
//	}
//
//	BSTIterator(TreeNode* root) {
//		dfs(root);
//	}
//
//	/** @return the next smallest number */
//	int next() {
//		int k = vec.front();
//		vec.pop();
//		return k;
//	}
//
//	/** @return whether we have a next smallest number */
//	bool hasNext() {
//		return !(vec.empty());
//	}
//};
//

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


