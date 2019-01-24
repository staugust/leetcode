/*
 * https://leetcode.com/problems/count-complete-tree-nodes/
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
//class Solution {
//public:
//	int countNodes(TreeNode* root) {
//		if (root == nullptr) {
//			return 0;
//		}
//		int res = 1;		
//		res += countNodes(root->left);
//		res += countNodes(root->right);
//		return res;
//	}
//};