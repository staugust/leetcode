/*
 * https://leetcode.com/problems/repeated-dna-sequences/
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
#include <unordered_map>
using namespace std;


class Solution187 {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int>m;
		vector<string> v;
		if (s.size() < 11) {
			return v;
		}
		string t = s.substr(0, 10);
		m[t]++;
		for (int i = 1; i < s.size() - 9; i++) {
			t.erase(t.begin());
			t.push_back(s[i + 9]);
			if (m[t] == 1) {
				v.push_back(t);
			}
			m[t]++;
		}
		return v;
	}
};