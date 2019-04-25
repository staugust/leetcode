/*
 * https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem
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

vector<int> breakingRecords(vector<int> scores) {
	int mn = scores[0];
	int mx = scores[0];
	int mnc = 0;
	int mxc = 0;
	for (int i = 1; i < scores.size(); i++) {
		if (scores[i] > mx) {
			mx = scores[i];
			mxc += 1;
		}
		else if (scores[i] < mn) {
			mn = scores[i];
			mnc += 1;
		}
	}
	return { mxc, mnc };
}