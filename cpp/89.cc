/*
 * https://leetcode.com/problems/gray-code/
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

class Solution89 {
public:
	vector<int> grayCode(int n) {
		vector<int> vec;
		if (n == 0) {
			return {0};
		}
		else if (n == 1) {
			return { 0,1 };
		}
		else {
			vec.push_back(0);
			vec.push_back(1);
			for(int i = 2; i <=n; i++){
				int val = pow(2, i - 1);
				int sz = vec.size() - 1;
				for (sz; sz > -1; sz--) {
					vec.push_back(vec[sz] + val);
				}
			}
			return vec;
		}
	}
};
