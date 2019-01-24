/*
 * https://leetcode.com/problems/binary-tree-preorder-traversal/
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
	vector<int> preorderTraversal(TreeNode* root) {
		if (root == nullptr) {
			return {};
		}
		vector<int> vec;
		vec.push_back(root->val);
		stack<TreeNode *> stk;
		TreeNode * prev = nullptr;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode * p = stk.top();
			if (p->left && p->right) {
				if (prev == p->left) {
					vec.push_back(p->right->val);
					stk.push(p->right);
				}
				else if (prev == p->right) {
					prev = p;
					stk.pop();
				}
				else {
					vec.push_back(p->left->val);
					stk.push(p->left);
				}
			}
			else if (p->left) {
				if (prev == p->left) {
					prev = p;
					stk.pop();
				}
				else {
					vec.push_back(p->left->val);
					stk.push(p->left);
				}
			}
			else if (p->right) {
				if (prev == p->right) {
					prev = p;
					stk.pop();
				}
				else {
					vec.push_back(p->right->val);
					stk.push(p->right);
				}
			}
			else {
				prev = p;
				stk.pop();
			}
		}
		return vec;
	}
};

*/