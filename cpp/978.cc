/*
 * https://leetcode.com/problems/longest-turbulent-subarray/
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

class Solution978 {
public:
	int maxTurbulenceSize(vector<int>& A) {
		if (A.size() < 2) {
			return A.size();
		}
		for (int i = 0; i < A.size()  -1 ; i++) {
			A[i] = A[i] - A[i + 1];
		}
		A[A.size() - 1] = -A[A.size() - 2];
		int h = -1;
		int mx = 0;
		for (int i = 1; i < A.size(); i++) {
			if (A[i] == 0 || A[i-1] == 0) {
				mx = mx > (i - h -( A[i-1]== 0 ? 1 : 0 )) ? mx : (i - h - (A[i - 1] == 0 ? 1 : 0));
				h = A[i] != 0 ? i -1 : i;
			}
			else if ((A[i] >0 &&  A[i - 1] > 0) ||(A[i] < 0 && A[i - 1] < 0)) {
				mx = mx > (i - h) ? mx : (i - h);
				h = i-1;
			}
		}
		mx = mx > (A.size()-1 - h) ? mx : (A.size()-1 - h);
		return mx;
	}
};
