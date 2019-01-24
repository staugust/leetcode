/*
 * https://leetcode.com/problems/combination-sum-ii/
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
#include <stack>

using namespace std;

class Solution40 {
public:
	int findNext(vector<int> & candidates, int it) {
		for (int i = it + 1; i < candidates.size(); i++) {
			if (candidates[i] > candidates[it]) {
				return i;
			}
		}
		return -1;
	}


	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty()) {
			return vector<vector<int>>{};
		}
		stack<int> stk;
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int> cur;
		int sum = candidates[0];
		stk.push(0);
		cur.push_back(candidates[0]);
		while (!stk.empty()) {
			if (sum < target) {
				int last = stk.top();
				int next = last+1;
				if (next < candidates.size()) {
					sum += candidates[next];
					cur.push_back(candidates[next]);
					stk.push(next);
				}
				else {
					for (int i = 0; i < 2 && !stk.empty(); i++) {
						last = stk.top();
						stk.pop();
						sum -= cur.back();
						cur.pop_back();
					}
					int next = findNext(candidates, last);
					while (next == -1 && !stk.empty()) {
						last = stk.top();
						stk.pop();
						cur.pop_back();
						sum -= candidates[last];
						next = findNext(candidates, last);
					}
					if (next != -1) {
						sum += candidates[next];
						cur.push_back(candidates[next]);
						stk.push(next);
					}
				}
			}
			else if (sum == target) {
				res.push_back(vector<int>(cur));
				int last = stk.top();
				stk.pop();
				cur.pop_back();
				sum -= candidates[last];
				int next = findNext(candidates, last);
				while (next == -1 && !stk.empty()) {
					last = stk.top();
					stk.pop();
					cur.pop_back();
					sum -= candidates[last];
					next = findNext(candidates, last);
				}
				if(next != -1){
					sum += candidates[next];
					cur.push_back(candidates[next]);
					stk.push(next);
				}
			}
			else {
				int last = stk.top();
				stk.pop();
				cur.pop_back();
				sum -= candidates[last];
				if(!stk.empty()){
					last = stk.top();
					stk.pop();
					cur.pop_back();
					sum -= candidates[last];
					int next = findNext(candidates, last);
					while (next == -1 && !stk.empty()) {
						last = stk.top();
						stk.pop();
						cur.pop_back();
						sum -= candidates[last];
						next = findNext(candidates, last);
					}
					if (next != -1) {
						sum += candidates[next];
						cur.push_back(candidates[next]);
						stk.push(next);
					}
				}
				else {
					break;
				}
			}
		}
		return res;
	}
};
