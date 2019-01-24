/*
 * https://leetcode.com/problems/number-of-islands/
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

class Solution200 {
public:
	int numIslands(vector<vector<char>>& grid) {
		int cnt = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1') {
					cnt++;
				}
				mark(grid, i, j, cnt);
			}
		}
		return cnt;
	}


	void mark(vector<vector<char>> & grid, int i, int j, int & cnt) {
		if (grid[i][j] == '1') {
			grid[i][j] = '#';
			if (i > 0) {
				//grid{i - 1]{j] = grid{i - 1]{j] == '0' ? '0' : '#';
				mark(grid, i - 1, j, cnt);
			}
			if (j > 0) {
				//grid{i]{j-1] = grid{i]{j-1] == '0' ? '0' : '#';
				mark(grid, i, j-1, cnt);

			}
			if (i < grid.size() - 1) {
				//grid{i + 1]{j] = grid{i + 1]{j] == '0' ? '0' : '#';
				mark(grid, i +1, j, cnt);

			}
			if (j < grid[0].size()-1) {
				//grid{i]{j + 1] = grid{i]{j + 1] == '0' ? '0' : '#';
				mark(grid, i , j+1, cnt);

			}
		}
	}
};
//
//int main() {
//	vector<vector<char>> grid = {
//		{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}
//	};
//
//	Solution s;
//
//	int res = s.numIslands(grid);
//	cout << res << endl;
//
//
//	return 0;
//}