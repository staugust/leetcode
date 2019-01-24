/*
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
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

class Solution81 {
public:
	bool search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;

		while (left <= right)
		{
			while (left <= right && nums[left] == nums[left + 1])
			{
				left++;
			}

			while (left <= right && nums[right] == nums[right - 1])
			{
				right--;
			}

			int mid = left + (right - left) / 2;

			if (nums[left] == target || nums[right] == target || nums[mid] == target)
			{
				return true;
			}

			if (nums[left] < nums[mid])
			{
				if (nums[left] < target && nums[mid] > target)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else
			{
				if (nums[mid] < target && nums[right] > target)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}

		return false;
	}
};