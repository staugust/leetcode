/*
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		if (inorder.empty())
			return NULL;
		int pre = -1;
		return buildTree2(preorder, pre, inorder, inorder.begin(), inorder.end());

	}

	TreeNode* buildTree2(vector<int>& preorder, int& preind, vector<int>& inorder, vector<int>::iterator inxs, vector<int>::iterator inxe) {
		if (inxs >= inxe)
			return NULL;

		preind++;
		auto it = new TreeNode(preorder[preind]);
		auto p = find(inxs, inxe, preorder[preind]);
		it->left = buildTree2(preorder, preind, inorder, inxs, p);
		it->right = buildTree2(preorder, preind, inorder, p + 1, inxe);
		return it;

	}
};

*/