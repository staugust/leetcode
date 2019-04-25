/*
 * https://www.hackerrank.com/challenges/insertion-sort/problem
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
#include <iostream>
#include <fstream>

using namespace std;

//using binary index tree to store count of numbers

long int insertionSort(vector<int> arr) {
	long long sum = 0;
	vector<int> vec(10000001, 0);
	for (int i = 0; i < arr.size(); i++) {
		sum += i;
		int idx = arr[i] - 1;
		while (idx) {
			sum -= vec[idx];
			idx -= idx & (-idx);
		}
		idx = arr[i];
		while (idx < 10000001) {
			vec[idx] += 1;
			idx += idx & (-idx);
		}
	}
	return sum;
}
