/*
 * https://www.hackerrank.com/challenges/electronics-shop/problem
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

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
	/*
	 * Write your code here.
	 */
	sort(keyboards.begin(), keyboards.end());
	sort(drives.begin(), drives.end());
	set<int> ds;
	for (auto d : drives) {
		ds.insert(d);
	}

	int ms = 0;
	for (int i = 0; i < keyboards.size(); i++) {
		int rm = b - keyboards[i];
		if (rm <= 0) {
			break;
		}
		while (rm > 0) {
			if (ds.find(rm) != ds.end()) {
				ms = ms > rm + keyboards[i] ? ms : rm + keyboards[i];
				break;
			}
			else {
				rm -= 1;
			}
		}
	}
	return ms;
}