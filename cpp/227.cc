/*
 * https://leetcode.com/problems/basic-calculator-ii/
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

class Solution227 {
public:
	int findNextNumber(const string& s, size_t& i) {
		int result = 0;
		for (; i < s.length(); ++i) {
			auto c = s[i];
			if (c == ' ') {
				continue;
			}
			int digit = s[i] - '0';
			if (digit < 0 || digit > 9) {
				while (s[i] == ' ') {
					++i;
				}
				return result;
			}
			result = result * 10 + digit;
		}
		return result;
	}

	int calculate(string s) {
		size_t i = 0;
		int prevNumber = findNextNumber(s, i);
		int result = 0;
		while (i < s.length()) {
			char op = s[i];
			++i;
			int nextNumber = findNextNumber(s, i);
			if (op == '+') {
				result += prevNumber;
				prevNumber = nextNumber;
			}
			else if (op == '-') {
				result += prevNumber;
				prevNumber = -1 * nextNumber;
			}
			else if (op == '*') {
				prevNumber *= nextNumber;
			}
			else if (op == '/') {
				prevNumber /= nextNumber;
			}
		}

		result += prevNumber;
		return result;
	}
};