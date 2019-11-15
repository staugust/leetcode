/*
 * https://leetcode.com/problems/occurrences-after-bigram/
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

class Solution1078 {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> res;
		vector<string> vec;
		int idx = text.find_first_not_of(' '); 
		int stop = 0;
		while (idx != -1) {
			stop = text.find_first_of(' ', idx);
			if (stop != -1) {
				vec.push_back(text.substr(idx, stop - idx));
				idx = text.find_first_not_of(' ', stop);
			}
			else {
				vec.push_back(text.substr(idx));
				break;
			}
		}
		for (int it = 0; it < vec.size() -2; it++) {
			if (first.compare(vec[it]) == 0 && second.compare(vec[it + 1]) == 0) {
				res.push_back(vec[it + 2]);
			}
		}
		return res;
	}
};
/*
int main(int argc, char * argv[]) {
	Solution s;
	auto r = s.findOcurrences("alice is a good girl she is a good student", "a", "good");
	for (auto k : r) {
		std::cout << k << std::endl;
	}
	return 0;
}
*/