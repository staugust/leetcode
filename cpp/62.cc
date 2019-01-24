/*
 * https://leetcode.com/problems/unique-paths/
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

class Solution62 {
public:
	int uniquePaths(int m, int n) {
		long res = 1;
		if (m == 1 || n == 1) {
			return 1;
		}
		int t = m + n - 2;
		int c = m - 1 > n - 1 ? n - 1 : m - 1;
		for (int i = 1; i <= c; i++) {
			res *= t;
			t -= 1;
		}
		for (int i = 1; i <= c; i++) {
			res /= i;
		}
		return res;
	}
};
