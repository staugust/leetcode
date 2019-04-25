/*
 * https://www.hackerrank.com/challenges/migratory-birds/problem
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

int migratoryBirds(vector<int> arr) {
	map<int, int> mp;
	for (auto k : arr) {
		mp[k] += 1;
	}
	int mx = 0;
	for (auto pr : mp) {
		if (mx < pr.second) {
			mx = pr.second;
		}
	}
	int tp = 10;
	for (auto pr : mp) {
		if (pr.second == mx && tp < pr.first) {
			tp = pr.first;
		}
	}
	return tp;
}