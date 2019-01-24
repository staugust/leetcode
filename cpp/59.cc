/*
 * https://leetcode.com/problems/spiral-matrix-ii/
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
#include <vector>
using namespace std;


class Solution59 {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n);
		for (auto & v : ans) {
			v.resize(n);
		}
		int nn = n * n;
		int index = 1;
		int left = 0, top = 0, right = n - 1, bottom = n - 1;
		while (index <= nn)
		{
			for (int i = left; i <= right; i++)
			{
				ans[top][i] = index; index++;
			}
			for (int i = top + 1; i <= bottom; i++)
			{
				ans[i][right] = index; index++;
			}
			for (int i = right - 1; i >= left; i--)
			{
				ans[bottom][i] = index; index++;
			}
			for (int i = bottom - 1; i > top; i--)
			{
				ans[i][left] = index; index++;
			}
			top++; left++; right--; bottom--;

		}
		return ans;
	}
};

int main59() {
	Solution59 s;
	s.generateMatrix(3);

	return 0;
}