/*
 * https://leetcode.com/problems/sort-colors/
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

class Solution75 {
public:
	void sortColors(vector<int>& nums) {
		int i = 0, n = nums.size(), reds = -1;
		while (i < n) {
			if (nums[i] > 1) {
				nums[i] = nums[n - 1];
				nums[n - 1] = 2;
				n--;
			}
			else if (nums[i] < 1) {
				nums[i] = nums[reds + 1];
				nums[reds + 1] = 0;
				reds++;
				i++;
			}
			else {
				i++;
			}
		}
	}
};