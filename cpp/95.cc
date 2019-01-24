/*
 * https://leetcode.com/problems/unique-binary-search-trees-ii/
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
	
	vector<TreeNode *> generate(const vector<int> & vec, int head, int tail) {
		vector<TreeNode *> trs;
		for (int i = head; i < tail; i++) {
			for (auto & tl : generate(vec, head, i)) {
				for (auto & tr : generate(vec, i + 1, tail)) {
					trs.push_back(new TreeNode(vec[i]));
					trs.back()->left = tl;
					trs.back()->right = tr;
				}
			}
		}
		if (trs.empty()) {
			trs.push_back(nullptr);
		}
		return trs;
	}

	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) {
			return {};
		}
		vector<int> vals(n);
		for (int i = 1; i < n + 1; i++) {
			vals[i - 1] = i;
		}
		return generate(vals, 0, n);
	}
};

*/