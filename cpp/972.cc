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

class Solution972 {
public:
	void normalize(string& s) {
		if (s.find(".") == string::npos) s += ".";
		string repeated = "0";
		auto ps = s.find("(");
		if (ps != string::npos) {
			repeated = s.substr(ps + 1, s.size() - ps - 2);
			s = s.substr(0, ps);
		}
		while (s.size() < 20) s += repeated;
	}
	bool isRationalEqual(string S, string T) {
		normalize(S), normalize(T);
		bool fill = false;
		for (auto i = 0; i < 20; ++i) {
			if (S[i] == '.' && T[i] == '.') continue;
			if (!fill && S[i] != T[i]) {
				if (abs(S[i] - T[i]) == 1) fill = true;
				else return false;
			}
			else if (fill && abs(S[i] - T[i]) != 9) return false;
		}
		return true;
	}
};
