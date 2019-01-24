/*
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
#include <queue>

using namespace std;

class Solution961 {
public:
	int repeatedNTimes(vector<int>& A) {
		set<int> st;
		for (int i = 0; i != A.size(); i++) {
			if (st.count(A[i])) {
				return A[i];
			}
			st.insert(A[i]);
		}
		return 0;
	}
};