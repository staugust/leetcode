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

vector<int> closestNumbers(vector<int> arr) {
	int diff = 0x3f3f3f3f;
	std::sort(arr.begin(), arr.end());
	std::vector<int> res;
	for (int i = 1; i < arr.size(); i++) {
		diff = diff < arr[i] - arr[i - 1] ? diff : arr[i] - arr[i - 1];
	}
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] - arr[i - 1] == diff) {
			res.push_back(arr[i - 1]);
			res.push_back(arr[i]);
		}
	}
	return res;
}

string gameOfThrones(string s) {
	vector<int> vec(26, 0);
	for (auto c : s) {
		vec[c - 'a'] += 1;
	}
	int odd = 0;
	for (auto k : vec) {
		odd += (k % 2);
	}
	if (odd == 0 || odd == 1)
	{
		return "YES";
	}
	return "NO";
}

string twoStrings(string s1, string s2) {
	vector<int> vec(26, 0);
	for (auto c : s1) {
		vec[c - 'a'] = 1;
	}
	for (auto c : s2) {
		if (vec[c - 'a'] == 1) {
			return "YES";
		}
	}
	return "NO";
}

int stringConstruction(string s) {
	vector<int> vec(26, 0);
	int cnt = 0;
	for (auto c : s) {
		if (vec[c - 'a'] == 0) {
			cnt += 1;
			vec[c - 'a'] = 1;
		}
	}
	return cnt;
}

vector<int> icecreamParlor(int m, vector<int> arr) {
	map<int, pair<int, int> > mp;
	for (int i = 0; i < arr.size() ; i++) {
		for (int j = i+1; j < arr.size(); j++) {
			if ((arr[i] + arr[j]) == m) {
				return { i + 1, j + 1 };
			}
		}
	}

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] * 2 == m) {
			return { i + 1, i + 1 };
		}
	}
	return { 0, 0 };
}

string balancedSums(vector<int> arr) {
	int right = 0;
	for (auto k : arr) {
		right += k;
	}
	int left = 0;
	for (int i = 0; i < arr.size(); i++) {
		if ( left == (right - arr[i])) {
			return "YES";
		}
		left += arr[i];
		right -= arr[i];
	}
	return "NO";
}

int minimumAbsoluteDifference(vector<int> arr) {
	sort(arr.begin(), arr.end());
	int mn = 0x3f3f3f3f;
	for (int i = 1; i < arr.size(); i++) {
		mn = mn < (arr[i] - arr[i - 1]) ? mn : arr[i] - arr[i - 1];
	}
	return mn;
}

long marcsCakewalk(vector<int> calorie) {
	sort(calorie.begin(), calorie.end());
	long cnt = 0;
	long base = 1;
	for (auto i = calorie.rbegin(); i != calorie.rend(); i++) {
		cnt += base * *i;
		base *= 2;
	}
	return cnt;
}

string gridChallenge(vector<string> grid) {
	for (int i = 0; i < grid.size(); i++) {
		sort(grid[i].begin(), grid[i].end());
	}
	int m = grid.size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m -1; j++) {
			if (grid[j + 1][i] < grid[j][i]) {
				return "NO";
			}
		}

	}
	return "YES";
}

int luckBalance(int k, vector<vector<int>> contests) {
	vector<int> imp;
	int luck = 0;
	for (auto & v : contests) {
		if (v[1] == 1) {
			imp.push_back(v[0]);
		}
		else {
			luck += v[0];
		}
	}
	if (imp.size() <= k) {
		for (int i = 0; i < imp.size(); i++) {
			luck += imp[i];
		}
	}
	else {
		sort(imp.begin(), imp.end());
		int t = imp.size() - k;
		for (int i = 0; i < t; i++) {
			luck -= imp[i];
		}
		for (int i = t; i < imp.size(); i++) {
			luck += imp[i];
		}
	}
	return luck;
}

vector<int> maximumPerimeterTriangle(vector<int> sticks) {
	sort(sticks.begin(), sticks.end());
	int k = sticks.size() - 1;
	for (; k - 1 > 0; k--) {
		if (sticks[k] < (sticks[k - 1] + sticks[k - 2])) {
			return { sticks[k - 2] , sticks[k - 1] , sticks[k] };
		}
	}
	return { -1 };
}




int main_h30() {

	string s = "abcdefghijklmn";
	reverse(s.begin(), s.end());
	std::cout << s << std::endl;

	auto k =  closestNumbers({ -5, 15, 25, 71, 63
		}) ;
	for (auto i : k) {
		std::cout << i << std::endl;
	}
	return 0;
}