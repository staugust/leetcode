# https://leetcode.com/problems/reshape-the-matrix/description/

class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if len(nums) == 0 or r * c != len(nums) * len(nums[0]):
            return nums
        tmp = []
        for n in nums:
            tmp = tmp + n
        res = []
        for i in range(r):
            res.append(tmp[c *i: c * i + c])
        return res

