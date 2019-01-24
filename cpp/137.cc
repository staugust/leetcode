/*
 * https://leetcode.com/problems/single-number-ii/
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

class Solution137 {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0;
		for (int i = 0; i < nums.size(); i++) {
			ones = (ones ^ nums[i]) & ~twos;
			twos = (twos ^ nums[i]) & ~ones;
		}
		return ones;
	}
};


