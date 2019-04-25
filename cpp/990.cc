/*
 * https://leetcode.com/problems/satisfiability-of-equality-equations/
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
#include <map>
#include <queue>

using namespace std;

class Solution990 {
public:
	bool equationsPossible(vector<string>& equations) {
		int arr[26] = { 0 };
		for (int i = 0; i != 26; i++) {
			arr[i] = i;
		}
		for (auto & str : equations) {
			if (str[1] == '=') {
				auto k = arr[str[3] - 'a'];
				arr[str[3] - 'a'] = arr[str[0] - 'a'];
				for (int i = 0; i < 26; i++) {
					if (arr[i] == k) {
						arr[i] = arr[str[0] - 'a'];
					}
				}
			}
		}
		for (auto &str : equations) {
			if (str[1] == '!') {
				if (arr[str[0] - 'a'] == arr[str[3] - 'a']) {
					return false;
				}
			}
		}
		return true;
	}
};

int main990() {
	string str = "ax==cb";
	int idx = str.find_first_of('=');
	auto v1 = str.substr(0, idx);
	auto v2 = str.substr(idx + 2, str.size() - idx);
	cout << v1 << endl;
	cout << v2 << endl;
	return 0;
}