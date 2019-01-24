/*
 * https://leetcode.com/problems/find-peak-element/
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

class Solution162 {
public:
	int findPeakElement(vector<int>& nums) {
		bool ascending = true;
		for (int i = 0; i < nums.size() - 1; i++) {
			bool order = nums[i] > nums[i + 1]; //true if descending
			if (order && ascending) {
				return i;
			}
			ascending = !order;
		}
		if (ascending) {
			return nums.size() - 1;
		}
		return -1;
	}
};