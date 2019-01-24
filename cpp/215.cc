/*
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
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

class Solution215 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.empty()) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};