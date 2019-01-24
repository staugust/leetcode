/*
 * https://leetcode.com/problems/subsets-ii/
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

class Solution90 {
public:

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.size() < 1) {
			return {};
		}
		sort(nums.begin(), nums.end());
		vector<vector<int>> res = { {}, {nums[0]} };
		int dp = 1;
		for (int k = 1; k < nums.size(); k++) {
			if (nums[k] == nums[k - 1]) {
				int sz = res.size() - 1;
				for (int i = 0; i<dp ; i++) {
					vector<int> tmp(res[sz - i]);
					tmp.push_back(nums[k]);
					res.push_back(tmp);
				}
			}
			else {
				dp = res.size();
				for (int i = 0; i < dp; i++) {
					vector<int> vec(res[i]);
					vec.push_back(nums[k]);
					res.push_back(vec);
				}
			}
		}
		return res;
	}
};