/*
 * https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
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
#include <stack>

using namespace std;

//greedy dfs
int jumpingOnClouds(vector<int> c) {
	int k = 0;
	int prev = 0;
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == 1) {
			k += (i - 1 - prev) / 2 + (i - 1 - prev) % 2;
			prev = i - 1;
		}
	}
	k += (c.size() - 1 - prev) / 2 + (c.size() - 1 - prev) % 2;
	return k;
}

