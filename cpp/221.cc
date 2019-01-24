/*
 * https://leetcode.com/problems/maximal-square/
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


class Solution221 {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) {
			return 0;
		}
		int mx = '0';
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] > '0') {
					if (i == 0 || j == 0) {
						mx = mx > matrix[i][j] ? mx : matrix[i][j];
						continue;
					}
					int bf = matrix[i - 1][j - 1];
					int row = matrix[i - 1][j];
					int col = matrix[i][j - 1];
					matrix[i][j] = min(bf, min(row, col)) + 1;
					mx = mx > matrix[i][j] ? mx : matrix[i][j];
				}
			}
		}
		return (mx-'0') * (mx - '0');
	}
};

//
//int main() {
//	Solution s;
//
//	//vector<vector<char>> matrix = {{'0', '1', '0', '0', '1', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1'}, {'0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '0', '1', '0', '0', '1'}, {'0', '0', '0', '0', '0', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '1', '0', '1', '1', '1', '1', '1', '0', '0', '1', '1'}, {'0', '1', '0', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1'}, {'0', '0', '0', '1', '1', '0', '1', '1', '1', '0', '0', '0', '1', '1', '1'}, {'1', '1', '1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '1', '0', '0'}, {'0', '1', '0', '1', '0', '0', '1', '1', '1', '1', '0', '0', '0', '0', '1'}, {'0', '1', '0', '0', '0', '1', '0', '1', '1', '0', '1', '0', '0', '1', '1'}, {'0', '0', '0', '1', '1', '0', '0', '1', '0', '1', '0', '0', '0', '1', '0'}, {'1', '1', '1', '0', '1', '0', '0', '1', '1', '1', '0', '1', '0', '0', '0'}, {'0', '0', '0', '1', '1', '0', '1', '1', '0', '1', '1', '0', '1', '1', '0'}, {'0', '0', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '0', '0'}};
//	vector<vector<char>> matrix = { {'0', '0'}, {'0','0'} };
//	cout << s.maximalSquare(matrix) << endl;
//
//
//	return 0;
//}