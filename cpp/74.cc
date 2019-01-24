/*
 * https://leetcode.com/problems/search-a-2d-matrix/
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

class Solution74 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		int s = 0;
		int e = matrix.size() * matrix[0].size() -1;
		while (s <= e) {
			int mid = (s + e) / 2;
			int c = mid % matrix[0].size();
			int r = mid / matrix[0].size();
			if (matrix[r][c] == target) {
				return true;
			}
			else if (matrix[r][c] < target) {
				s = mid + 1;
			}
			else{
				e = mid - 1;
			}
		}
		return false;
	}
};
auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
