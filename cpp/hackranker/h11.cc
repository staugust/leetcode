/*
 * https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
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

int divisibleSumPairs(int n, int k, vector<int> ar) {
	map<int, vector<int>> mp;
	for (auto num : ar) {
		mp[num % k].push_back(num);
	}
	int total = mp[0].size() * (mp[0].size() - 1) / 2;
	for (int i = 1; i < (k+1)/ 2;  i++) {
		total += mp[i].size() * mp[k - i].size();
	}
	if (k % 2 == 0) {
		total += mp[k / 2].size() * (mp[k / 2].size() - 1) / 2;
	}
	return total;
}

//int main() {
//	vector<int> ar = { 1,3,2,6,1,2 };
//	int k = divisibleSumPairs(6, 3, ar);
//	cout << k << endl;
//
//	return 0;
//}