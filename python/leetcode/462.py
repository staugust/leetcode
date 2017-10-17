# https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

import numpy as np

class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        arr = sorted(nums)
        median = arr[len(arr) // 2]
        sum = 0
        for x in arr:
            sum = sum + abs(x - median)
        return sum


# 1 2 90 92
# 2: 1 + 88 + 90
# 90: 89 + 88 + 2