/*
 * https://www.hackerrank.com/challenges/manasa-and-stones/problem
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

vector<int> stones(int n, int a, int b) {
	set<int> st;
	for (int i = 0; i < n; i++) {
		st.insert(a * i + b * (n - 1 - i));
	}
	vector<int> vec;
	for (auto key : st) {
		vec.push_back(key);
	}
	sort(vec.begin(), vec.end());
	return vec;
}
