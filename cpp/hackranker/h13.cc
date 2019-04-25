/*
 * https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
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

int isBeautiful(int num, int k) {
	int rev = 0;
	int org = num;
	while (num) {
		rev = rev * 10 + num % 10;
		num = num / 10;
	}

	return (rev - org) % k;
}

int beautifulDays(int i, int j, int k) {
	int cnt = 0;
	for (int it = i; it <= j; it++) {
		if (isBeautiful(it, k) == 0) {
			cnt++;
		}
	}
	return cnt;
}