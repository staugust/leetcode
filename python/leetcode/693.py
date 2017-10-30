# https://leetcode.com/problems/binary-number-with-alternating-bits/description/



class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        n = abs(n)
        x = n & 0x1
        while n:
            n = n >> 1
            if x == n & 0x1:
                return False
            else:
                x = n & 0x1
        return True
