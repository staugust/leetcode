/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
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

class Solution80 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		if (nums.size() == 1) {
			return 1;
		}

		int k = 1;
		int it = 2;
		int prev = nums[0];
		while (it < nums.size()) {
			if (nums[it] != nums[k -1]) {
				nums[++k] = nums[it];
			}
			it++;
		}
		nums.resize(k + 1);
		return k + 1;
	}
};