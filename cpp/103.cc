/*
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == nullptr) {
			return {};
		}
		vector<vector<int>> res;
		vector<TreeNode *> nodes;
		nodes.push_back(root);
		bool leftToright = true;
		while (!nodes.empty()) {
			vector<int> vec(nodes.size());
			for (int i = 0; i < vec.size(); i++) {
				vec[i] = nodes[i]->val;
			}
			res.push_back(vec);
			leftToright = !leftToright;
			vector<TreeNode *> nn;
			if (leftToright) {
				for (auto it = nodes.rbegin(); it != nodes.rend(); it++) {
					if ((*it)->left != nullptr) {
						nn.push_back((*it)->left);
					}
					if ((*it)->right != nullptr) {
						nn.push_back((*it)->right);
					}
				}
			}
			else {
				for (auto it = nodes.rbegin(); it != nodes.rend(); it++) {
					if ((*it)->right != nullptr) {
						nn.push_back((*it)->right);
					}
					if ((*it)->left != nullptr) {
						nn.push_back((*it)->left);
					}
				}
			}
			nodes.swap(nn);
		}
		return res;
	}
};

*/