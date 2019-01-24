/*
 * https://leetcode.com/problems/binary-tree-inorder-traversal/
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

	void inOrder(TreeNode * root, vector<int> & vec) {
		if (root == nullptr) {
			return;
		}
		inOrder(root->left, vec);
		vec.push_back(root->val);
		inOrder(root->right, vec);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> vec;
		inOrder(root, vec);
		return vec;
	}
};

*/