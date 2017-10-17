# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        num = set(numbers)
        mp = {}
        x, y = 0,0
        for i in range(len(numbers)):
            mp[numbers[i]] = i
        for n in num:
            if (target - n) in num:
                x, y = mp[n] -1 if target == n * 2 else mp[n], mp[target - n]
                break
        return min(x,y) + 1,max(x,y) + 1
