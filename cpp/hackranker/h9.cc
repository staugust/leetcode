/*
 * https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
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
// Notice that balls of type i may stored in container j
// 
string organizingContainers(vector<vector<int>> container) {
	int N = container.size();
	vector<int> bvec;
	vector<int> cvec;
	for (int i = 0; i < N; i++) {
		int balls = 0; // balls of type i
		int calls = 0; // balls in container i
		for (int j = 0; j < N; j++) {
			balls += container[j][i];
		}
		for (int j = 0; j < N; j++) {
			calls += container[i][j];
		}
		bvec.push_back(balls);
		cvec.push_back(calls);
	}
	sort(bvec.begin(), bvec.end());
	sort(cvec.begin(), cvec.end());
	for (int i = 0; i < N; i++) {
		if (bvec[i] != cvec[i]) {
			return "Impossible";
		}
	}
	return "Possible";
}