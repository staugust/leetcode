/*
 * https://www.hackerrank.com/challenges/cut-the-sticks/problem
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


vector<int> cutTheSticks(vector<int> arr) {
	map<int, int> mp;
	for (auto k : arr) {
		mp[k] += 1;
	}
	vector<int> vec;
	int cnt = arr.size();
	while (!mp.empty()) {
		vec.push_back(cnt);
		auto it = mp.lower_bound(0);
		cnt -= it->second;
		mp.erase(it->first);
	}
	return vec;
}