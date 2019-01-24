/*
 * https://leetcode.com/problems/house-robber-ii/
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


class Solution213 {
public:
	int rob(vector<int>& nums) {
		int ans = nums.size() < 1 ? 0 : nums[0];
		for (int off = 0; off < 2; off++) {
			int taken = 0, nottaken = 0;
			for (int i = off; i - off + 1 < nums.size(); i++) {
				int new_taken = max(taken, nottaken + nums[i]);
				int new_nottaken = max(taken, nottaken);
				taken = new_taken;
				nottaken = new_nottaken;
			}
			ans = max(ans, max(taken, nottaken));
		}
		return ans;
	}
};

//int main() {
//	Solution s;
//
//	vector<int> vec = { 1,1,7,1,1,7 };
//
//	cout << s.rob(vec) << endl;
//
//
//	return 0;
//}