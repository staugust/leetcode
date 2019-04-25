/* 
 * https://leetcode.com/problems/majority-element-ii/
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


class Solution229 {
public:
	vector<int> majorityElement(vector<int>& nums) {
		if (nums.empty()) {
			return {};
		}
		vector<int> res;
		int canA = nums[0];
		int canB = nums[0];
		int ca = 0;
		int cb = 0;

		for (auto num : nums) {
			if (num == canA) {
				ca++;
				continue;
			}
			if (num == canB) {
				cb++;
				continue;
			}
			if (ca == 0) {
				canA = num;
				ca = 1;
				continue;
			}
			if (cb == 0) {
				canB = num;
				cb = 1;
				continue;
			}
			ca--;
			cb--;
		}

		ca = 0;
		cb = 0;
		for (auto num : nums) {
			if (canA == num) {
				ca++;
			}
			else if (canB == num) {
				cb++;
			}
		}
		if (ca > nums.size() / 3) {
			res.push_back(canA);
		}
		if (cb > nums.size() / 3) {
			res.push_back(canB);
		}
		return res;
	}
};