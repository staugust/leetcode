/*
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

	TreeNode* buildTree2(vector<int>& preorder, int& preind, vector<int>& inorder, vector<int>::iterator inxs, vector<int>::iterator inxe) {
		if (inxs >= inxe)
			return NULL;

		preind--;
		auto it = new TreeNode(preorder[preind]);
		auto p = find(inxs, inxe, preorder[preind]);
		it->right = buildTree2(preorder, preind, inorder, p+1, inxe);
		it->left = buildTree2(preorder, preind, inorder, inxs, p);
		return it;

	}
	   
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty())
			return NULL;
		int pre = inorder.size();
		return buildTree2(postorder, pre, inorder, inorder.begin(), inorder.end());
	}
};
*/