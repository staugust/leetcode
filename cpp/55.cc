/*
 * https://leetcode.com/problems/jump-game/
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

class Solution55 {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() < 2) {
			return true;
		}
		int mx = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (mx <= 0) {
				return false;
			}
			if (mx + i >= nums.size()) {
				return true;
			}
			mx = mx - 1;
			mx = mx > nums[i] ? mx : nums[i];
		}
		return mx >= 0;
	}
};


int main_55() {
	vector<int> input = { 0, 1};
	Solution55 s;
	std::cout << s.canJump(input) << std::endl;
	return 0;
}