/*
 * https://leetcode.com/problems/minimum-path-sum/
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

class Solution64 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int R = grid.size();
		int C = grid[0].size();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (i == 0 || j == 0) {
					if (i == 0 && j == 0) {
						continue;
					}
					else if (i == 0) {
						grid[i][j] += grid[i][j - 1];
					}
					else {
						grid[i][j] += grid[i - 1][j];
					}
				}
				else{
					grid[i][j] += (grid[i][j - 1] < grid[i - 1][j] ? grid[i][j - 1] : grid[i-1][j] );
				}
			}
		}
		return grid[R - 1][C - 1];

	}
};