/*
 * https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
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


int designerPdfViewer(vector<int> h, string word) {
	int he = 0;
	for (int i = 0; i < word.size(); i++) {
		he = he > h[word[i] - 'a'] ? he : h[word[i] - 'a'];
	}
	return he * word.size();
}