/*
 * https://leetcode.com/problems/backspace-string-compare/
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

class Solution844 {
public:
	bool backspaceCompare(string S, string T) {
		string s = "";
		string t = "";
		for (auto k : S) {
			if (k == '#') {
				if (!s.empty()) {
					s = s.substr(0, s.size() - 1);
				}
			}
			else {
				s += k;
			}
		}
		for (auto k : T) {
			if (k == '#') {
				if(!t.empty())
					t = t.substr(0, t.size() - 1);
			}
			else {
				t += k;
			}
		}
		return s.compare(t) == 0;
	}
};

/*
int main(int argc, char * argv[]) {
	Solution s;
	std::cout << s.backspaceCompare("ab##",
		"e#f#") << std::endl;
}
*/