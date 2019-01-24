/*
 * https://leetcode.com/problems/subsets/
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

class Solution78 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res = { {} };
		for (int i = 0; i < nums.size(); i++) {
			vector<vector<int>> nv;
			for (auto & v : res) {
				auto vec(v);
				vec.push_back(nums[i]);
				nv.push_back(vec);
			}
			for (auto & vec : nv) {
				res.push_back(vec);
			}
		}
		return res;
	}
};