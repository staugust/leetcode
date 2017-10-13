
class Position(object):
    def __init__(self, ix=0, iy=0, other=None):
        if other is None:
            self.x = ix
            self.y = iy
        else:
            self.x = other.x
            self.y = other.y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return self.x << 16 & self.y

    def move(self, s):
        res = Position(other=self)
        if s == 'L':
            res.x = res.x - 1
        elif s == 'R':
            res.x = res.x + 1
        elif s == 'U':
            res.y = res.y + 1
        elif s == 'D':
            res.y = res.y - 1
        else:
            pass
        return res


class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        print(moves.count("L"))

        return moves.count("L") ==  moves.count("R") and moves.count("U") ==  moves.count("D")





if __name__ == "__main__":
    s = Solution()
    moves = "LDRRLRUULR"

    print(moves)
    print(s.judgeCircle(moves))