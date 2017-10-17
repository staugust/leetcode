# https://leetcode.com/problems/assign-cookies/description/

class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g = sorted(g)
        s = sorted(s)
        output = 0
        gval = 0
        for i in range(len(s)):
            if g[gval] <= s[i]:
                output += 1
                gval += 1
                if gval == len(g):
                    break
        return output