/*
 * https://leetcode.com/problems/palindrome-partitioning/
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

//class Solution {
//public:
//	bool isPalindrome(string suffix) {
//		for (int j = 0; j < (suffix.size() + 1) / 2; j++) {
//			if (suffix{j] != suffix{suffix.size() - 1 - j]) {
//				return false;
//			}
//		}
//		return true;
//	}
//
//	vector<vector<string>> partition(string s) {
//		if (s.size() == 0) {
//			return {};
//		}
//		if (s.size() == 1) {
//			return { {s} };
//		}
//		vector<vector<string>> solutions;
//		if (isPalindrome(s)) {
//			solutions.push_back({ s });
//		}
//		for (int i = 1; i < s.size(); i++) {
//			string suffix = s.substr(s.size() - i, i);
//			if (!isPalindrome(suffix)) {
//				continue;
//			}
//			auto sols = partition(s.substr(0, s.size() - i));
//			for (auto & v : sols) {
//				v.push_back(suffix);
//				solutions.push_back(v);
//			}
//		}
//		return solutions;
//	}
//};
//
//int main() {
//	string s = 'aab';
//	auto res = Solution().partition(s);
//	cout << res.size() << endl;
//	return 0;
//}