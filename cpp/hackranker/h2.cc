/*
 * https://www.hackerrank.com/challenges/append-and-delete/problem
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

string appendAndDelete(string s, string t, int k) {	
	if (k >= s.size() + t.size()) {
		return "Yes";
	}
	int idx= 0;
	for (; idx < s.size() && idx < t.size(); idx++) {
		if (s[idx] != t[idx]) {
			break;
		}
	}
	if (idx == 0) {
		return k >= s.size() + t.size() ? "Yes" : "No";
	}
	else {
		int steps = t.size() + s.size() - idx * 2;
		return (k >= steps && (k - steps) % 2 == 0) ? "Yes" : "No";	
	}
}


