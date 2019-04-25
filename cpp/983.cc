/*
 * https://leetcode.com/problems/minimum-cost-for-tickets/
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
//auto Augusto = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution983 {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		map<int, int> dp = { {-30,0} };
		auto cost = [&](int d) {return prev(dp.upper_bound(d))->second; };
		for (int d : days)
			dp[d] = min({ costs[0] + cost(d - 1), costs[1] + cost(d - 7), costs[2] + cost(d - 30) });
		return dp.rbegin()->second;
	}
};