/*
 * https://www.hackerrank.com/challenges/3d-surface-area/problem
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

int surfaceArea(vector<vector<int>> A) {
	int cnt = 0;
	int m = A.size();
	int n = A[0].size();

	for (int i = 0; i < m; i++) {
		cnt += A[i][0];
		cnt += A[i][n - 1];
	}
	for (int j = 0; j < n; j++) {
		cnt += A[0][j];
		cnt += A[m - 1][j];
	}
	cnt += m * n * 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if(i > 0){
				cnt += abs(A[i][j] - A[i - 1][j]);
			}
			if (j > 0) {
				cnt += abs(A[i][j] - A[i][j - 1]);
			}
		}
	}
	return cnt;
}

