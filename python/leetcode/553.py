# https://leetcode.com/problems/optimal-division/description/

class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if len(nums) == 1:
            return "{}".format(nums.pop(0))
        elif len(nums) == 2:
            return "{}/{}".format(nums.pop(0),nums.pop(0))
        else:
            s = "{}/({}".format(nums.pop(0),nums.pop(0))
            for num in nums:
                s = s + "/{}".format(num)
            s = s + ")"
            return s
