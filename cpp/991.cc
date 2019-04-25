/*
 * https://leetcode.com/problems/broken-calculator/
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

class Solution991 {
public:
	int brokenCalc(int X, int Y) {
		if (X < Y) {
			int k = 0;
			while (X < Y) {
				k += Y % 2;
				k += 1;
				Y = (Y+1) / 2;
			}
			return k + X - Y;

		}
		else {
			return X - Y;
		}
	}
};