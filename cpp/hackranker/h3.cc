/*
 * https://www.hackerrank.com/challenges/sherlock-and-squares/problem
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

int squares(int a, int b) {
	int low = sqrt(a) - 1;
	while (low * low < a) {
		low += 1;
	}
	int high = sqrt(b) + 1;
	while (high * high > b) {
		high -= 1;
	}
	return high - low + 1;
}