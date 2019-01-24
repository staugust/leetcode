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
#include <stack>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution971 {
public:
	int pos = 0;
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		if (root == NULL) return {};
		if (voyage[pos] != root->val) return { -1 };
		vector<int> res;
		if (root->left != NULL && root->left->val != voyage[pos + 1]) {
			if (root->right == NULL) return { -1 };
			else if (root->right->val != voyage[pos + 1]) return { -1 };
			else {
				res.push_back(root->val);
				TreeNode* temp = root->left;
				root->left = root->right;
				root->right = temp;
			}
		}
		pos++;
		vector<int> l = flipMatchVoyage(root->left, voyage);
		vector<int> r = flipMatchVoyage(root->right, voyage);
		if ((l.size() == 1 && l[0] == -1) || (r.size() == 1 && r[0] == -1)) return { -1 };
		for (int i = 0; i < l.size(); i++) res.push_back(l[i]);
		for (int i = 0; i < r.size(); i++) res.push_back(r[i]);
		return res;
	}
};