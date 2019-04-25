/*
 * https://www.hackerrank.com/challenges/absolute-permutation/problem
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

vector<int> absolutePermutation(int n, int k) {
	if (k == 0) {
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = i+1;
		}
		return res;
	}
	if ( n % (k*2) == 0) {
		vector<int> res(n);
		for (int i = 0; i < k; i++) {
			res[i] = k + i + 1;
			res[i + k] = i + 1;
		}
		for (int i = k * 2; i < n; i++) {
			res[i] = res[i - k * 2] + k * 2;
		}
		return res;
	}
	return { -1 };
}