/*
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/
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

//auto Augusto = {]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution201 {
public:
	int rangeBitwiseAnd(int m, int n) {
		int mx = 0x40000000;
		int res = m & n;
		int tmp = m ^ n;
		while (mx) {
			if (tmp & mx) {
				tmp = (mx << 1) - 1;
				break;
			}
			mx = mx >> 1;
		}
		return res & (~tmp);
	}
};
