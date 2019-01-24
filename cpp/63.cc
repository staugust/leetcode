/*
 * https://leetcode.com/problems/unique-paths-ii/
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

class Solution63 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		int R = obstacleGrid.size() - 1, C = obstacleGrid[0].size() - 1;

		if (obstacleGrid.empty() || obstacleGrid[R][C] == 1) return 0;

		vector<vector<int>> grid = obstacleGrid;

		for (int i = 0; i <= R; ++i) {
			for (int j = 0; j <= C; ++j) {
				if (grid[i][j] == 1) grid[i][j] = -1;
				if ((i == 0 && j == 0) && grid[i][j] != -1) grid[i][j] = 1;
			}
		}

		for (int i = 0; i <= R; ++i) {
			for (int j = 0; j <= C; ++j) {
				if (grid[i][j] == -1 || i == 0 && j == 0) continue;
				grid[i][j] = (i == 0 || grid[i - 1][j] == -1 ? 0 : grid[i - 1][j]) +
					(j == 0 || grid[i][j - 1] == -1 ? 0 : grid[i][j - 1]);
			}
		}
		return grid[R][C];
	}
};
