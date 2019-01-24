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


class Solution {
	vector<int> recursive(int n, int num, int K) {
		vector<int> res;
		if (n == 0) {
			res.push_back(num);
			return res;
		}
		int lastdigit = num % 10;
		int nextdigit = lastdigit + K;
		vector<int> subres;
		if (nextdigit < 10) res = recursive(n - 1, num * 10 + nextdigit, K);
		if (K != 0) {
			nextdigit = lastdigit - K;
			if (nextdigit >= 0) subres = recursive(n - 1, num * 10 + nextdigit, K);
		}
		res.insert(res.end(), subres.begin(), subres.end());
		return res;
	}

public:
	vector<int> numsSameConsecDiff(int N, int K) {
		int startdigit = (N == 1) ? 0 : 1;
		vector<int> res;
		while (startdigit <= 9) {
			vector<int> subres = recursive(N - 1, startdigit, K);
			res.insert(res.end(), subres.begin(), subres.end());
			startdigit++;
		}
		return res;
	}
};