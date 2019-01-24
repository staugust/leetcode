/*
 * https://leetcode.com/problems/simplify-path/
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
#include <sstream>

using namespace std;

class Solution71 {
public:
	string simplifyPath(string path) {
		stringstream ss(path);
		string floder;
		deque<string> q;
		string ans = "/";
		while (getline(ss, floder, '/')) {
			if (floder != "") {
				//cout << "get string: " << floder << endl;
				if (floder == ".")
					continue;
				else if (floder == "..") {
					if (!q.empty())
						q.pop_front();
				}
				else {
					q.push_front(floder);
				}
			}
		}

		while (!q.empty()) {
			if (q.size() != 1)
				ans += q.back() + "/";
			else
				ans += q.back();
			q.pop_back();
		}
		//reverse(ans.begin(), ans.end());
		return ans.size() == 0 ? "/" : ans;
	}
};

