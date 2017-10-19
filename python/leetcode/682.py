# https://leetcode.com/problems/baseball-game/description/

class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        res = []
        for c in ops:
            if c == 'C':
                res.pop(len(res) -1)
            elif c == 'D':
                res.append(res[len(res) - 1] * 2)
            elif c == '+':
                res.append(res[len(res) - 1] + res[len(res) - 2])
            else:
                res.append(int(c))
        return sum(res)


if __name__ == "__main__":
    s = Solution()

    print(s.calPoints(["5","-2","4","C","D","9","+","+"]))