/*
 * https://www.hackerrank.com/challenges/between-two-sets/problem
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

int gcd(int x, int y) {
	if (x < y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	while (x % y) {
		int tmp = x % y;
		x = y;
		y = tmp;
	}
	return y;
}

int gcm(int x, int y) {
	return x * y / gcd(x, y);
}

int getTotalX(vector<int> a, vector<int> b) {
	int gm = a[0];
	for (int i = 1; i < a.size(); i++) {
		gm = gcm(gm, a[i]);
	}
	int gd = b[0];
	for (int j = 1; j < b.size(); j++) {
		gd = gcd(gd, b[j]);
	}
	if (gd < gm) {
		return 0;
	}
	else if (gd == gm) {
		return 1;
	}else{
		if (gd % gm == 0) {
			int cnt = 2;
			int k = gd / gm;
			for (int i = 2; i < k; i++) {
				if (k % i == 0) {
					cnt += 1;
				}
			}
			return cnt;	
		}
		else {
			return 0;
		}
	}
}