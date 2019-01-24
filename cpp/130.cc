/*
 * https://leetcode.com/problems/surrounded-regions/
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


class Solution130 {
public:
	int R;
	int C;
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		R = board.size(); C = board[0].size();
		if (R <= 2 || C <= 2) return;

		for (int i = 0; i < R; ++i) { helper(board, i, 0); helper(board, i, C - 1); }
		for (int j = 1; j < C - 1; ++j) { helper(board, 0, j); helper(board, R - 1, j); }

		for (auto &n : board) { for (auto &c : n) c = c == '#' ? 'O' : 'X'; }

	}
	inline void helper(vector<vector<char>>& board, const int i, const int j) {
		if (board[i][j] != 'O') return;
		board[i][j] = '#';
		if (i > 0) helper(board, i - 1, j);
		if (i < R - 1) helper(board, i + 1, j);
		if (j > 0) helper(board, i, j - 1);
		if (j < C - 1) helper(board, i, j + 1);
	}
};