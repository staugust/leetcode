/*
 * https://leetcode.com/problems/binary-tree-right-side-view/
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
//	vector<int> rightSideView(TreeNode* root) {
//		vector<int> v;
//		std::queue<TreeNode*> q;
//		if (!root) return v;
//		q.push(root);
//		int numInThisRow = 1;
//		while (q.size() > 0)
//		{
//			TreeNode* node = q.front();
//			q.pop();
//			if (node->left) q.push(node->left);
//			if (node->right) q.push(node->right);
//			if (--numInThisRow == 0)
//			{
//				v.push_back(node->val);
//				numInThisRow = q.size();
//			}
//
//		}
//		return v;
//
//	}
//};