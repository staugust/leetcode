# https://leetcode.com/problems/combination-sum/description/
# Combination Sum



class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        candidates = sorted(candidates)
        if len(candidates) == 0 or target < candidates[0]:
            return [[]]
        elif target == candidates[0]:
            return [[target]]
        else:
            pass

if __name__ == "__main__":
    x = [ i for i in range(10)]
    x.reverse()
    print(sorted(x))