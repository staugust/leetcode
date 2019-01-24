/*
 * https://leetcode.com/problems/merge-intervals/
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

 
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

 bool compare56(Interval & v1, Interval & v2) {
	 return v1.start < v2.start;
 }

 class Solution56 {
 public:
	 vector<Interval> merge(vector<Interval>& intervals) {
		 if (intervals.size() < 2) {
			 return intervals;
		 }
		 sort(intervals.begin(), intervals.end(), compare56);
		 int s = intervals[0].start;
		 int e = intervals[0].end;
		 vector<Interval> vec;
		 vec.push_back(intervals[0]);
		 for (int i = 1; i < intervals.size(); i++) {
			 if (vec.back().end >= intervals[i].start) {
				 vec.back().end = max(intervals[i].end, vec.back().end);
			 }
			 else {
				 vec.push_back(intervals[i]);
			 }
		 }
		 return vec;
	 }
 };