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


//Definition for a binary tree node.
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution965 {
public:
	bool isEqual(TreeNode * p, int val) {
		if (p == nullptr) {
			return true;
		}
		if (p->val != val) {
			return false;
		}

		return isEqual(p->left, val) && isEqual(p->right,val);
	}

	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		int val = root->val;
		return isEqual(root->left, val) && isEqual(root->right, val);
	}
};

*/