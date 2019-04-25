/*
 *
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

int beautifulPairs(vector<int> A, vector<int> B) {
	map<int, int> b;
	int cnt = 0;
	for (auto i : B) {
		b[i] += 1;
	}
	for (auto i : A) {
		if (b[i] > 0) {
			b[i] -= 1;
			cnt += 1;
		}
	}
	return cnt == A.size() ? cnt : cnt + 1;
}

int main() {

	int k = beautifulPairs({ 3,5,7,11,5,8}, { 5,7,11,10,5,8 });
	cout << k << endl;
	return 0;
}