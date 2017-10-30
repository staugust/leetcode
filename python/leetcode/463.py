# https://leetcode.com/problems/island-perimeter/description/

class Solution(object):

    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        r = len(grid)
        c = len(grid[0])
        t = 0
        x = 0
        for row in range(r):
            for cell in range(c):
                if grid[row][cell] == 1:
                    t += 1
                    if row != 0:
                        x += grid[row - 1][cell]
                    if row != r - 1:
                        x += grid[row + 1][cell]
                    if cell != 0:
                        x += grid[row][cell - 1]
                    if cell != c - 1:
                        x += grid[row][cell + 1]
        return t * 4 - x

class Solution(object):
    def islandPerimeter(self, grid):
        """
        calculate row, and column
        using zip to transform matrix, genius
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        for g in (grid, zip(*grid)):
            for row in g:
                temp = 0
                for block in row:
                    if block == 1:
                        temp = 2
                    else:
                        res += temp
                        temp = 0
                res += temp
        return res




if __name__ == "__main__":
    x = [[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
    for i in (x,zip(*x)):
        for row in i:
            print(row)