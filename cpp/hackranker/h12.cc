/*
 * https://www.hackerrank.com/challenges/flatland-space-stations/problem
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

int flatlandSpaceStations(int n, vector<int> c) {
	sort(c.begin(), c.end());
	int mx = (c[0] - 1) >(n -1 - c[c.size() -1]) ? (c[0] -1): (n -1 - c[c.size() - 1]);
	for (int i = 1; i < c.size(); i++) {
		mx = mx > (c[i] - c[i - 1]) / 2 ? mx : (c[i] - c[i - 1]) / 2;
	}
	return mx;
}

//int main() {
//	vector<int> c = { 0, 1,2,3,4,5 };
//	int k = flatlandSpaceStations(6, c);
//	cout << k << endl;
//	return 0;
//}