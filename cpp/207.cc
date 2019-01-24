/*
 * https://leetcode.com/problems/course-schedule/
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

class Solution207 {
	bool visit(vector<uint8_t>& visited, vector<vector<int>>& graph, int node) {
		if (visited[node] == 2) return true;
		if (visited[node] == 1) return false;

		visited[node] = 1;
		for (auto next : graph[node]) {
			if (!visit(visited, graph, next)) return false;
		}
		visited[node] = 2;
		return true;
	}

public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> graph(numCourses);
		for (auto& p : prerequisites) graph[p.first].push_back(p.second);

		vector<uint8_t> visited(numCourses);
		for (int i = 0; i < numCourses; ++i) {
			if (!visit(visited, graph, i)) return false;
		}
		return true;
	}
};