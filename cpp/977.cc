/*
 * https://leetcode.com/problems/squares-of-a-sorted-array/
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

class Solution977 {
public:
	vector<int> sortedSquares(vector<int>& A) {
		if (A.empty()) {
			return {};
		}
		if (A[0] >= 0) {
			vector<int> vec;
			for (auto it : A) {
				vec.push_back(it * it);
			}
			return vec;
		}
		if (A[A.size() - 1] <= 0) {
			vector<int> vec;
			for (auto it = A.rbegin(); it != A.rend(); it++) {
				vec.push_back(*it * *it);
			}
			return vec;
		}

		int t = -1;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] > 0) {
				t = i;
				break;
			}
		}
		vector<int> vec;
		int h = t - 1;
		while (h > -1 || t < A.size()) {
			if (t >= A.size()) {
				vec.push_back(A[h] * A[h]);
				h--;
			}
			else if (h < 0) {
				vec.push_back(A[t] * A[t]);
				t++;
			}
			else {
				if (A[h] + A[t] >= 0) {
					vec.push_back(A[h] * A[h]);
					h--;
				}
				else {
					vec.push_back(A[t] * A[t]);
					t++;
				}
			}
		}
		return vec;
	}
};