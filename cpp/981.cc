/*
 * https://leetcode.com/problems/time-based-key-value-store/
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

class TimeMap {
public:
	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		
		mp[key][timestamp] =  value;
	}

	string get(string key, int timestamp) {
		if (mp.count(key) == 0) return "";
		auto it = mp[key].upper_bound(timestamp);
		if (it == mp[key].begin()) return "";
		else return (--it)->second;
	}
private:
	unordered_map<string, map<int, string> > mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main981() {
	TimeMap tm;
	tm.set("love", "high", 10);
	tm.set("love", "low", 20);

	cout << tm.get("love", 5) << endl;



	return 0;
}