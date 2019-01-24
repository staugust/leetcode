/*
 * https://leetcode.com/problems/unique-binary-search-trees/
 * https://en.wikipedia.org/wiki/Catalan_number
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
#include <functional>
#include <queue>

using namespace std;

class Solution96 {
public:
	//int numTrees(int n) {
	//	vector<int> cache(n + 1, -1);
	//	cache[0] = cache[1] = 1;

	//	std::function<int(int)> num_tree_recur = [&](int n) {
	//		if (cache[n] == -1) {
	//			cache[n] = 0;
	//			for (int i = 0; i < n; ++i)
	//				cache[n] += (num_tree_recur(i) * num_tree_recur(n - i - 1));
	//		}
	//		return cache[n];
	//	};
	//	return num_tree_recur(n);
	//}
	map<int, long long> mp;
	int cal(int head, int tail) {
		int len = (tail - head);
		if (len <= 0) {
			return 1;
		}else{
			if (mp.find(len) != mp.end()) {
				return mp[len];
			}
			int res = 0;
			for (int i = head; i < tail; i++) {
				res += cal(head, i) * cal(i + 1, tail);
			}
			mp[len] = res;
			return res;
		}
	}
	int numTrees(int n) {
		if (n == 0) {
			return 0;
		}
		return cal(0, n);
	}

};