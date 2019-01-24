/* 
 * https://leetcode.com/problems/gas-station/
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

class Solution134 {
public:
	bool isValid(vector<int> saver, int k) {
		int gas = saver[k];
		if (gas < 0) {
			return false;
		}
		for (int i = k + 1; i < k + saver.size(); i++) {
			gas += saver[i % saver.size()];
			if (gas < 0) {
				return false;
			}
		}
		return true;
	}


	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int nGas = 0, nTot = 0, ans = 0;

		for (int i = 0; i < n; ++i) {
			nGas += gas[i] - cost[i];  // need to minus cost
			if (nGas < 0) {
				ans = i + 1;
				nTot += nGas;
				nGas = 0;
			}
		}

		return nTot + nGas >= 0 ? ans : -1;
	}
};