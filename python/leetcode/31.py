# https://leetcode.com/problems/next-permutation/description/

class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        it = len(nums) - 1
        while it != 0:
            if nums[it -1] < nums[it]:
                # find the one
                for i in range(len(nums)-1, it - 1, -1):
                    if nums[i] > nums[it - 1]:
                        break
                nums[it - 1], nums[i] = nums[i], nums[it - 1]
                for i in range(it, (it + len(nums)) // 2):
                    nums[i], nums[len(nums) - 1 + it - i] = nums[len(nums) - 1 + it - i],nums[i]
                break
            it = it - 1
        if it == 0:
            nums.reverse()

"""
    This is the best solution
"""
class Solution2(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # find the first increase
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i == -1:
            nums.reverse()
        else:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1

            nums[i], nums[j] = nums[j], nums[i]
            nums[i + 1:] = nums[len(nums) - 1:i:-1]
