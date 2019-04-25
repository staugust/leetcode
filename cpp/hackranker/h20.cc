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

 // Complete the strangeCounter function below.
long strangeCounter(long t) {
	int it = 3;
	while (t > it) {
		t = t - it;
		it *= 2;
	}
	return it + 1 - t;
}