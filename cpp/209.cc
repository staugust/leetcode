/*
 * https://leetcode.com/problems/minimum-size-subarray-sum/
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

class Solution209 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int mn = nums.size() + 1;
		int sum = 0;
		int h = 0;
		int t = 0;
		for(; t < nums.size(); t++) {
			if(sum >=s){
				while (sum >= s) {
					sum -= nums[h++];
				}
				mn = mn < (t - h + 1) ? mn : t - h + 1;
			}
			sum += nums[t];
		}
		while (sum >= s) {
			sum -= nums[h++];
		}
		mn = mn < (t - h + 1) ? mn : t - h + 1;
		return mn == nums.size() + 1 ? 0 : mn;
	}
};
//
//int main() {
//	Solution s;
//
//	int t = 7;
//	vector<int> nums = {2, 3, 1, 2, 4, 3};
//	cout << s.minSubArrayLen(t, nums) << endl;
//
//
//	return 0;
//}