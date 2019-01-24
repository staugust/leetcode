/*
 * https://leetcode.com/problems/course-schedule-ii/
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
#include <unordered_map>

using namespace std;

	class Solution210 {
	public:
		vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
			unordered_map<int, set<int>> st;
			for (auto & p : prerequisites) {
				st[p.first].insert(p.second);
			}
			vector<int> order;
			set<int> processed;
			for (int i = 0; i < numCourses; i++) {
				if (st.count(i) == 0) {
					order.push_back(i);
					processed.insert(i);
				}
			}

			int k = 0;
			do{
				k = 0;
			for (int i = 0; i < numCourses; i++) {
				if (st.count(i)) {
					set<int> ss;
					for (auto & c : st[i]) {
						if (processed.count(c) == 0) {
							ss.insert(c);
						}
					}
					ss.swap(st[i]);
					if (st[i].empty()) {
						processed.insert(i);
						order.push_back(i);
						st.erase(i);
						k++;
					}
				}
			}
			} while (k > 0);
			if (!st.empty()) {
				return {};
			}
			return order;
		}
	};