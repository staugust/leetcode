/*
 * https://leetcode.com/problems/combinations/
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

class Solution77 {
public:
	vector<vector<int> > combine(int n, int k) {
		// dfs method
		if (k == 0 || n == 0 || n < k)
			return result;
		v.resize(k);
		combinecore(1, n, k);
		return result;
	}

	void combinecore(int startnum, int n, int k) {
		int i = startnum;
		while (i <= (n - k + 1)) {
			v[v.size() - k] = i;
			i++;
			if (k > 1)
				combinecore(i, n, k - 1);
			else
				result.push_back(v);
		}
	}
private:
	vector<int> v;
	vector<vector<int> > result;
};