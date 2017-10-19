# https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp = {}
        res = 0
        for i in nums:
            if i not in mp:
                left = mp[i - 1] if i - 1 in mp else 0
                right = mp[i+1] if i + 1 in mp else 0
                s = left + right + 1
                mp[i] = s
                mp[i - left] = s
                mp[i + right] = s
                res = res if res > s else s
        return res