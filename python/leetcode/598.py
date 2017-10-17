# https://leetcode.com/problems/range-addition-ii/description/

class Solution(object):
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        for lst in ops:
            m = m if m < lst[0] else lst[0]
            n = n if n < lst[1] else lst[1]
        return m * n