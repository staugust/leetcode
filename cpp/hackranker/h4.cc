/* 
 * https://www.hackerrank.com/challenges/magic-square-forming/problem
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

const vector<vector<int>> vec = {
	{8,1,6,7,2,9,4,3},
	{6,7,2,9,4,3,8,1},
	{2,9,4,3,8,1, 6,7 },
	{4,3,8,1,6,7,2,9 },
	{ 8, 3,4,9,2,7,6,1},
	{ 4, 9,2,7,6,1,8,3 },
	{ 2, 7,6,1,8,3,4,9 },
	{ 6,1,8 ,3,4,9,2,7,},
};



int formingMagicSquare(vector<vector<int>> s) {
	vector<int> tmp = {
		s[0][0], s[0][1], s[0][2], s[1][2], s[2][2], s[2][1], s[2][0], s[1][0]
	};
	int mn = 100;
	for (auto & v : vec) {
		int k = 0;
		for (int i = 0; i < v.size(); i++) {
			k += abs(v[i] - tmp[i]);
		}
		mn = mn > k ? k : mn;
	}
	return mn + abs(5 - s[1][1]);
}