/*
 * https://leetcode.com/problems/string-without-aaa-or-bbb/
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
class Solution984 {
public:
	string strWithout3a3b(int A, int B) {
		string s;

		while (A > 0 || B > 0) {
			if (s.length() >= 2 && s[s.length() - 1] == 'a' && s[s.length() - 2] == 'a') {
				s += "b";
				B--;
			}
			else if (s.length() >= 2 && s[s.length() - 1] == 'b' && s[s.length() - 2] == 'b') {
				s += "a";
				A--;
			}
			else if (A > B) {
				s += "a";
				A--;
			}
			else {
				s += "b";
				B--;
			}
		}

		return s;
	}
};