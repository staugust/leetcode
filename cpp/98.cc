/*
 * https://leetcode.com/problems/validate-binary-search-tree/
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
	void inOrder(vector<int> & v , TreeNode * root) {
		if (root == nullptr) {
			return;
		}
		inOrder(v, root->left);
		v.push_back(root->val);
		inOrder(v, root->right);
	}

	bool isValidBST(TreeNode* root) {
		vector<int> vals;
		inOrder(vals, root);
		for (int i = 1; i < vals.size(); i++) {
			if (vals[i] <= vals[i - 1]) {
				return false;
			}
		}
		return true;
	}
};
*/