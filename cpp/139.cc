/*
 * https://leetcode.com/problems/word-break/
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
#include <unordered_set>

using namespace std;

class Solution139 {
public:
	bool canBreak(string s, int h,const  unordered_set<string> & wd, map<int, bool> & st) {
		if (st.count(h)) {
			return st[h];
		}
		if (h == s.size()) {
			st[h] = true;
			return true;
		}
		for (int i = h +1; i <= s.size(); i++) {
			if (wd.count(s.substr(h, i - h)) && canBreak(s, i, wd, st)) {
				return true;
			}
		}
		st[h] = false;
		return false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wd;
		for (auto & str : wordDict) {
			wd.insert(str);
		}
		map<int, bool> st;
		return canBreak(s, 0, wd,st);
	}
};



/*
class Solution139_2 {
public:
	bool wordBreakHelper(const string& s, vector<string>& wordDict, int start, int* arr) {
		if (start == s.length()) {
			return true;
		}
		if (arr{start] == 0) {
			return false;
		}
		if (arr{start] == 1) {
			return true;
		}

		for (const auto& word : wordDict) {
			if (s.length() - (start) < word.length()) {
				continue;
			}
			bool words_match = true;
			for (int i = 0; i < word.length(); i++) {
				if (word{i] != s{start + i]) {
					words_match = false;
					break;
				}
			}
			if (words_match && wordBreakHelper(s, wordDict, start + word.length(), arr)) {
				arr{start] = 1;
				return true;
			}
		}
		arr{start] = 0;
		return false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		if (s.empty()) {
			return true;
		}
		int arr{s.length()] = {};
		std::fill_n(arr, s.length(), -1);

		return wordBreakHelper(s, wordDict, 0, arr);
	}
};

*/
//
//
//int main() {
//	Solution s;
//	string str = 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab';
//	cout << str.substr(150, 1) << endl;
//	vector<string> wordDict = { 'a', 'aa', 'aaa', 'aaaa', 'aaaaa', 'aaaaaa', 'aaaaaaa', 'aaaaaaaa', 'aaaaaaaaa', 'aaaaaaaaaa' };
//	cout << s.wordBreak(str, wordDict) << endl;
//
//	return 0;
//}