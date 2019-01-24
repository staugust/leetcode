/*
 * https://leetcode.com/problems/fraction-to-recurring-decimal/
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

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		int f1 = numerator >= 0 ? 1 : -1;
		int f2 = denominator >= 0 ? 1 : -1;
		long long num = abs((long long)numerator);
		long long den = abs((long long)denominator);

		long long q = num / den;
		long long rem = num % den;

		string res;
		if (f1 * f2 < 0 && (!(q == 0 && rem == 0))) {
			res = "-";
		}

		res += to_string(q);
		if (rem == 0) {
			return res;
		}
		res += ".";

		map<long long, int> m;
		int pos = 0;
		string fra_res;
		while (rem != 0) {
			m[rem] = pos;
			pos++;
			q = rem * 10 / den;
			rem = rem * 10 % den;
			fra_res += to_string(q);
			if (m.find(rem) != m.end()) {
				fra_res.insert(m[rem], "(");
				fra_res += ")";
				break;
			}
		}
		res += fra_res;

		return res;
	}
};