/*
 * https://www.hackerrank.com/challenges/halloween-sale/problem
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

int howManyGames(int p, int d, int m, int s) {
	// Return the number of games you can buy
	int cnt = 0;
	while (s >= p) {
		s -= p;
		cnt += 1;
		p = p - d > m ? p - d : m;
	}
	return cnt;
}