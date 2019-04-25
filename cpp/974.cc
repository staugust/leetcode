/*
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/
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

class Solution974 {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		if (A.empty()) {
			return 0;
		}
		int cnt = 0;
		vector<int> vec;
		int sum = 0;
		for (int i = 0; i < A.size(); i++) {
			sum += A[i];
			sum = sum % K;
			if (sum == 0) {
				cnt++;
			}
			vec.push_back(sum);
		}

		for (int k = 1; k < A.size(); k++) {
			for (int it = k; it < A.size(); it++) {
				vec[it] = (vec[it] - A[k - 1]) % K;
				if (vec[it] == 0) {
					cnt++;
				}
			}
		}
		return cnt;
	}
};

//int main() {
//
//	vector<int> vec = { 4,5,0,-2,-3,1};
//
//	Solution s;
//	int cnt = s.subarraysDivByK(vec, 5);
//	cout << cnt << endl;
//	return 0;
//}