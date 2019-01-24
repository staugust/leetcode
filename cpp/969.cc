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

class Solution969 {
public:
	int computePos(int it, vector<int> & steps) {
		for (int i = 0; i != steps.size(); i++) {
			int step = steps[i];
			if (it <= step) {
				it = step + 1 - it;
			}
		}
		return it;
	}

	//another solution , this solution assumes that integers in A is [1 , A.size()]
	/*
	  vector<int> vec;
	  for(int mx = A.size(); mx > 0; mx --){
		int j = 0;
		//find max position, move to right position
		for(; A[j] != mx; j++);
		//flip to first
		if( j != 0){
		  vec.push_back(j + 1);
		  //do flip
		  int s = 0, e = j;
		  while(s < e){
		    int tmp = A[s];
		    A[s] = A[e];
			A[e] = tmp;
			s++;
			e--;
		  }
		}

		//flip to right position
		vec.push_back(mx);
		int s = 0, e = mx - 1;
		while(s < e){
			int tmp = A[s];
			A[s] = A[e];
			A[e] = tmp;
			s++;
			e--;
		}
		//do flip 
	  }

	 */
	vector<int> pancakeSort(vector<int>& A) {
		vector<int> steps;
		vector<int> vec(A);
		sort(vec.begin(), vec.end());
		map<int, int> mp;
		for (int i = 0; i != A.size(); i++) {
			mp[A[i]] = i+1;
		}

		for (int j = vec.size() - 1; j > -1; j--) {
			int pos = computePos(mp[vec[j]], steps);
			if (pos == j + 1) {
				continue;
			}
			if( pos != 1){
				steps.push_back(pos);
			}
			steps.push_back(j + 1);
		}
		return steps;
	}
};

