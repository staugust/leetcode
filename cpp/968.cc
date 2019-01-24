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

class Solution968 {
public:
	int res = 0;
	int minCameraCover(TreeNode* root) {
		return (dfs(root) < 1 ? 1 : 0) + res;
	}

	int dfs(TreeNode* root) {
		int left = root->left ? dfs(root->left) : 2,
			right = root->right ? dfs(root->right) : 2;
		if (left == 0 || right == 0) {
			res++;
			return 1;
		}
		return left == 1 || right == 1 ? 2 : 0;
	}
};
