/*
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
 

class Solution108 {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size());	
	}
private:
	///construct a tree with elements in nums from h (inclusive) to t(exclusive)
	TreeNode * sortedArrayToBST(vector<int> nums, int h, int t) {
		if (t <= h) {
			return nullptr;
		}
		int mid = (t + h) / 2;
		TreeNode * root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, h, mid);
		root->right = sortedArrayToBST(nums, mid + 1, t);
		return root;
	}
};

int main() {
	Solution s;
	vector<int> vec = { -10,-3,0,5,9 };
	TreeNode * root = s.sortedArrayToBST(vec);
	std::cout << root->val << std::endl;
	return 0;
}


*/