# https://leetcode.com/problems/search-for-a-range/description/
# Search for a Range
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = []
        idx = self.findOnce(nums, target, 0, len(nums) - 1)
        if idx == -1:
            res = [-1, -1]
        else:
            while idx > -1 and nums[idx] == target:
                idx = idx - 1
            idx = idx + 1
            res.append(idx)

            while idx < len(nums) and nums[idx] == target:
                idx = idx + 1
            res.append(idx -1)
        return res

    def findOnce(self, nums, target, s, e):
        if e < s:
            return -1
        mid = (e + s) // 2
        if e == s:
            return s if nums[s] == target else -1
        elif nums[mid] > target:
            return self.findOnce(nums, target, s, mid - 1)
        elif nums[mid] == target:
            return mid
        else:
            return self.findOnce(nums, target, mid + 1, e)
