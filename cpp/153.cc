/*
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
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

class Solution153 {
public:
	int findMin(vector<int>& nums) {
		int h = 0, t = nums.size() - 1;
		int mid;
		while (h < t) {
			mid = (h + t) / 2;
			if (nums[h] > nums[t]) {
				if (nums[mid] >= nums[h]) {
					h = mid + 1;
				}
				else {
					t = mid;
				}
			}
			else {
				return nums[h];
			}
		}
		return nums[h];
	}
};