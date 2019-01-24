/* 
 * https://leetcode.com/problems/combination-sum-iii/
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

class Solution216 {
public:
	vector<vector<int>> cm(int k, int n, int h) {
		if (k == 0) {
			return {};
		}
		if (k == 1 ) {
			if ( n < 10 && n > h)
				return { {n} };
			else
				return {};
		}
		vector<vector<int>> vec;
		for (int i = h + 1; i < 9; i++) {
			auto tmp = cm(k - 1, n - i, i);
			for (auto & v : tmp) {
				v.push_back(i);
				vec.push_back(v);
			}
		}
		return vec;
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		return cm(k, n, 0);
	}
};

//int main() {
//	Solution s;
//	auto p = s.combinationSum3(3, 9);
//	for (auto & k : p) {
//		for (auto & i : k) {
//			cout << i << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}
