/*
 * https://leetcode.com/problems/triangle/
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


class Solution120 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) {
			return 0;
		}
		if (triangle.size() == 1) {
			return triangle[0][0];
		}
		for (int i = 1; i < triangle.size(); i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				if (j == 0) {
					triangle[i][0] = triangle[i][0] + triangle[i - 1][0];
				}
				else if (triangle[i-1].size() == j) {
					triangle[i][j] = triangle[i][j] + triangle[i - 1][triangle[i-1].size() -1];
				}
				else {
					triangle[i][j] = triangle[i][j] + (triangle[i - 1][j] > triangle[i - 1][j-1] ? triangle[i - 1][j-1] :triangle[i - 1][j]);
				}
			}
		}

		int mn = triangle[triangle.size() - 1][0];
		for (int j = 1; j < triangle[triangle.size() - 1].size(); j++) {
			mn = mn < triangle[triangle.size() - 1][j] ? mn : triangle[triangle.size() - 1][j];
		}
		return mn;
	}
};