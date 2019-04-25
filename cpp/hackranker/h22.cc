/*
 * https://www.hackerrank.com/challenges/circular-array-rotation/problem
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

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
	int sz = a.size();
	vector<int> vec;
	for (auto q : queries) {
		int idx = (q - k) % sz;
		if (idx < 0) {
			idx += sz;
		}
		vec.push_back(a[idx]);
	}
	return vec;
}