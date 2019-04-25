/*
 * https://www.hackerrank.com/challenges/bomber-man/problem
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

vector<string> bomberMan(int n, vector<string> grid) {
	// 5s is the same with 1s
	if (n == 1) {
		return grid;
	}
	n = (n-1) % 4 + 1;
	vector<string> vec;
	for (int i = 0; i < grid.size(); i++) {
		vec.push_back(string(grid[0].size(), 'O'));
	}
	if (n % 2 == 0) {
		return vec;
	}
	
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 'O') {
				vec[i][j] = '.';
				if (i - 1 >= 0) {
					vec[i - 1][j] = '.';
				}
				if (i + 1 < grid.size()) {
					vec[i + 1][j] = '.';
				}
				if (j - 1 >= 0) {
					vec[i][j - 1] = '.';
				}
				if (j + 1 < grid[0].size()) {
					vec[i][j + 1] = '.';
				}
			}
		}
	}
	if (n == 3) {
		return vec;
	}
	//n == 1, in this case, it's the same 
	vector<string> res;
	for (int i = 0; i < grid.size(); i++) {
		res.push_back(string(grid[0].size(), 'O'));
	}
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (vec[i][j] == 'O') {
				res[i][j] = '.';
				if (i - 1 >= 0) {
					res[i - 1][j] = '.';
				}
				if (i + 1 < grid.size()) {
					res[i + 1][j] = '.';
				}
				if (j - 1 >= 0) {
					res[i][j - 1] = '.';
				}
				if (j + 1 < grid[0].size()) {
					res[i][j + 1] = '.';
				}
			}
		}
	}
	return res;
}

//int main() {
//	vector<string> grid = {
//		".......",
//		"...O...",
//		"....O..",
//		".......",
//		"OO.....",
//		"OO.....",
//	};
//
//	vector<string> res = bomberMan(5, grid);
//	for (auto s : res) {
//		cout << s << endl;
//	}
//
//	return 0;
//}