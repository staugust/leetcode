/*
 * https://leetcode.com/problems/maximum-product-subarray/
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

class Solution152 {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		int maxProduct = INT32_MIN, head = 1, i = 0, acc = 1;
		bool incHead = false;

		for (auto n : nums) {
			maxProduct = max(n, maxProduct);
			if (n > 0) {
				if (head > 0) { head *= n; maxProduct = max(head, maxProduct); }
				else { acc *= n; maxProduct = max(acc, maxProduct); }
			}
			else if (n < 0) {
				if (head > 0) { maxProduct = head == 1 ? max(maxProduct, n) : max(head, maxProduct); head *= n; continue; }
				else if (incHead) { acc /= head; acc *= n; maxProduct = max(maxProduct, acc); }
				else { acc *= head * n; maxProduct = max(maxProduct, acc); }
				incHead = !incHead;
			}
			else { head = 1; acc = 1; incHead = false; }
		}
		return maxProduct;
	}
};