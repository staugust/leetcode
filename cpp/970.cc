/*
 * https://leetcode.com/problems/powerful-integers/
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

class Solution970 {
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		set<int> st;
		if (bound < 2) {
			return vector<int>();
		}

		if (1 == y && x == 1) {
			vector<int> v = { 2 };
			return v;
		}
		if (x == 1 || y == 1) {
			x = (x == 1) ? y : x;
			vector<int> v;
			for (int i = 0; pow(x, i) < bound; i++) {
				v.push_back(pow(x, i) + 1);
			}
			return v;
		}else{
			for (int i = 0; pow(x, i) < bound; i++) {
				for (int j = 0; pow(y, j) < bound; j++) {
					int sum = (int)(pow(x, i) + pow(y, j));
					if (sum <= bound) {
						st.insert(sum);
					}
				}
			}
			vector<int> vec(st.size());
			int i = 0;
			for (auto & b : st) {
				vec[i++] = b;
			}
			return vec;
		}
	}
};

