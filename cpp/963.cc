/*
 * https://leetcode.com/problems/minimum-area-rectangle-ii/
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

class Solution963 {
public:
	double minAreaFreeRect(vector<vector<int>>& points) {
		set<pair<int, int>> pts;
		for (auto & p : points) {
			pts.insert({ p[0], p[1]});
		}

		double MIN = 2e9;
		for (int i = 0; i != points.size(); i++){
			auto p1 = points[i];
			for (int j = 0; j != points.size(); j++) {
				auto & p2 = points[j];
				if (p2[0] == p1[0] && p2[1] == p1[1])
				{
					continue;
				}
				for(int k = j + 1; k < points.size(); k++){
					auto & p3 = points[k];
					if ((p3[0] == p1[0] && p3[1] == p1[1]) || (p3[0] == p2[0] && p3[1] == p2[1]))
					{
						continue;
					}
					long a = (long)(p2[0] - p1[0]) * (long)(p2[0] - p1[0]) + (long)(p2[1] - p1[1]) * (long)(p2[1] - p1[1]);
					long b = (long)(p3[0] - p1[0]) * (long)(p3[0] - p1[0]) + (long)(p3[1] - p1[1]) * (long)(p3[1] - p1[1]);
					long c = (long)(p3[0] - p2[0]) * (long)(p3[0] - p2[0]) + (long)(p3[1] - p2[1]) * (long)(p3[1] - p2[1]);
					if (a + b == c) {
						pair<int, int> p4(p3[0] + p2[0] - p1[0], p3[1] + p2[1] - p1[1]);
						if (pts.find(p4) != pts.end()) {
							MIN = MIN > sqrt(a * b) ? sqrt(a * b) : MIN;
						}
					}
				}
			}
		}
		MIN = (MIN == 2e9) ? 0 : MIN;
		return MIN;
	}
};