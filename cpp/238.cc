/*
 * https://leetcode.com/problems/product-of-array-except-self/
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

class Solution238 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> matrix(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++) {
			matrix[i] = matrix[i - 1] * nums[i - 1];
		}
		int c = 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			c = c * nums[i + 1];
			matrix[i] *= c;
		}
		return matrix;
	}
};