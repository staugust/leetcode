/*
 * https://leetcode.com/problems/search-a-2d-matrix-ii/
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
//auto Augusto = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution240 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		int col = matrix[0].size() - 1;
		int row = 0;
		while (col >= 0 && row <= matrix.size() - 1) {
			if (target == matrix[row][col]) {
				return true;
			}
			else if (target < matrix[row][col]) {
				col--;
			}
			else if (target > matrix[row][col]) {
				row++;
			}
		}
		return false;
			
	}
};