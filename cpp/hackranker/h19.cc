/*
 * https://www.hackerrank.com/challenges/library-fine/problem
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

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
	
	if (y1 == y2) {
		if (m1 == m2) {
			if (d1 <= d2) {
				return 0;
			}
			else {
				return (d1 - d2) * 15;
			}
		}
		else if (m1 > m2) {
			return (m1 - m2) * 500;
		}
		else {
			return 0;
		}
	}
	else if (y1 > y2) {
		return 10000;
	}
	else {
		return 0;
	}
}