/*
 * https://leetcode.com/problems/restore-ip-addresses/
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


class Solution93 {
public:
	bool isValid(const string & s) {
		if (s.size() < 1 || s.size() > 3) 	return false;
		if (s[0] == '0' && s.length() >= 2) return false;
		if (s.length() < 3) return true;
		return (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0') < 256;
	}


	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		int d1 = 1, d2 = d1 + 1, d3 = d2 + 1, d4 = d3 + 1;
		for (; d1 < s.size() && d1 < 4; d1++) {
			string s1 = s.substr(0, d1);
			if (!isValid(s1)) {
				continue;
			}
			for (d2 = d1 + 1; d2 < s.size() && d2 < d1 + 4; d2++) {
				string s2 = s.substr(d1, d2 - d1);
				if (!isValid(s2)) {
					continue;
				}
				for (d3 = d2 + 1; d3 < s.size() && d3 < d2 + 4; d3++) {
					string s3 = s.substr(d2, d3 - d2);
					if (!isValid(s3)) {
						continue;
					}
					string s4 = s.substr(d3, s.size() - d3);
					if (isValid(s4)) {
						res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
					}
				}
			}
		}
		return res;
	}
};
