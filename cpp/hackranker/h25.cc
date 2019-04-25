/*
 * https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
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

void matrixRotation(vector<vector<int>> matrix, int r) {
	int left = 0, right = matrix[0].size() -1, top = 0, bottom = matrix.size() -1 ;
	while (bottom > top && left < right) {
		int k = r % ( 2 * ((bottom - top) + (right - left)));
		queue<int> que;
		for (int c = left; c <= right; c++) {
			que.push(matrix[top][c]);
		}
		for (int row = top + 1; row <= bottom; row++) {
			que.push(matrix[row][right]);
		}
		for (int c = right - 1; c >= left; c--) {
			que.push(matrix[bottom][c]);
		}
		for (int row = bottom - 1; row > top; row--) {
			que.push(matrix[row][left]);
		}
		
		while (k) {
			que.push(que.front());
			que.pop();
			k--;
		}

		for (int c = left; c <= right; c++) {
			matrix[top][c] = que.front();
			que.pop();
		}
		for (int row = top + 1; row <= bottom; row++) {
			matrix[row][right] = que.front();
			que.pop();
		}
		for (int c = right - 1; c >= left; c--) {
			matrix[bottom][c] = que.front();
			que.pop();
		}
		for (int row = bottom - 1; row > top; row--) {
			matrix[row][left] = que.front();
			que.pop();
		}
		left += 1;
		right -= 1;
		bottom -= 1;
		top += 1;
	}
	for (auto vec : matrix) {
		for (auto k : vec) {
			cout << k << " ";
		}
		cout << endl;
	}


}