/*
 * https://www.hackerrank.com/challenges/utopian-tree/problem
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

int utopianTree(int n) {
	int h = 0;
	for (int i = 0; i <= n; i++) {
		if (i % 2 == 0) {
			h += 1;
		}
		else {
			h *= 2;
		}
	}
	return h;
}
