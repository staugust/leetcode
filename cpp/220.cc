/*
 * https://leetcode.com/problems/contains-duplicate-iii/
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


class Solution220 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		vector<long> vec(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			vec[i] = long(nums[i]);
		}

		long target = t;
		for (int i = 0; i < vec.size(); i++) {
			for (int j = i+1; j <= k+i && j < vec.size(); j++) {
				if (abs(vec[i] - vec[j]) <= target) {
					return true;
				}
			}
		}
		return false;
	}
};

