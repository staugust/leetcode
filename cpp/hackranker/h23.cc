/*
 * https://www.hackerrank.com/challenges/non-divisible-subset/problem
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

int nonDivisibleSubset(int k, vector<int> S) {
	map<int, int> mp;

	
	for (auto s : S) {
		mp[s % k] += 1;
	}
	int cnt = 0;
	if (mp[0] > 0) {
		cnt += 1;
	}
	if (k % 2 == 0) {
		if (mp[k / 2] > 0) {
			cnt += 1;
		}
	}

	for (int i = 1; i < (k + 1) / 2; i++) {
		cnt += mp[i] > mp[k - i] ? mp[i] : mp[k - i];
	}
	return cnt;
}