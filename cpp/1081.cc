/*
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
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
#include <stack>

using namespace std;

class Solution1081 {
public:
	string smallestSubsequence(string text) {
		string str = "";
		map<char, int> mp;
		for (auto k : text) {
			mp[k] += 1;
		}
		for(auto k:text){
			mp[k] -= 1;
			if (str.size() == 0) {
				str += k;
				continue;
			}
			if (str.find(k) != -1) {
				continue;
			}
			string newStr = "";
			for (int it = str.size() -1; it > -1; it--) {
				// should check more carefully 
				if (str[it] < k || mp[str[it]] <= 0) {
					newStr = str.substr(0, it + 1);
					break;
				}
			}
			newStr += k;
			str.swap(newStr);
		}
		return str;
	}
};
/*
int main(int argc, char * argv[]) {
	Solution s;
	auto str = s.smallestSubsequence("cdadabcc");
	std::cout << str << std::endl;

	return 0;
}
*/