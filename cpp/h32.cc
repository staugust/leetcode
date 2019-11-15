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

int beautifulPairs(vector<int> A, vector<int> B) {
	map<int, int> b;
	int cnt = 0;
	for (auto i : B) {
		b[i] += 1;
	}
	for (auto i : A) {
		if (b[i] > 0) {
			b[i] -= 1;
			cnt += 1;
		}
	}
	return cnt == A.size() ? cnt : cnt + 1;
}

void decentNumber(int n) {
	char * arr = (char *)calloc(n + 1, 1);
	int k = n / 3;
	int v = n % 3;
	switch (v) {
	case 0:
		for (int i = 0; i < n; i++) {
			arr[i] = '5';
		}
		printf("%s\n", arr);
		break;
	case 1:
		if (k > 2) {
			for (int i = 0; i <3 *( k - 3); i++) {
				arr[i] = '5';
			}
			for (int i = 3 * (k - 3); i < n; i++) {
				arr[i] = '3';
			}
			printf("%s\n", arr);
		}
		else {
			printf("-1\n");
		}
		break;
	case 2:
		if (k > 0) {
			for (int i = 0; i < 3 * (k - 1); i++) {
				arr[i] = '5';
			}
			for (int i = 3 * (k - 1); i < n; i++) {
				arr[i] = '3';
			}
			printf("%s\n", arr);
		}
		else {
			printf("-1\n");
		}
		break;
	}
}

int toys(vector<int> w) {
	if (w.size() < 2) {
		return w.size();
	}
	sort(w.begin(), w.end());
	int mx = w[0] + 4;
	int cnt = 1;
	for (int i = 1; i < w.size(); i++) {
		if (w[i] > mx) {
			mx = w[i] + 4;
			cnt += 1;
		}
	}
	return cnt;
}

vector<int> largestPermutation(int k, vector<int> arr) {
	vector<int> order(arr);
	sort(order.begin(), order.end(), [](int k1, int k2) {
		return k1 > k2;
	});
	map<int, int > mp;
	for (int i = 0; i < arr.size(); i++) {
		mp[arr[i]] = i;
	}
	int idx = 0;
	while (k > 0) {
		for (; idx < arr.size(); idx++) {
			if (arr[idx] >= order[idx]) {
				continue;
			}
			else {
				break;
			}
		}
		if (idx != arr.size()) {
			int tmp = arr[idx];
			arr[idx] = order[idx];
			arr[mp[order[idx]]] = tmp;
			k--;
			mp[tmp] = mp[order[idx]];
			mp[order[idx]] = idx;
		}
		else {
			break;
		}
	}
	
	return arr;
}

int main_h32() {

	largestPermutation(5, { 5,7,11,10,5,8 });

	int k = beautifulPairs({ 3,5,7,11,5,8}, { 5,7,11,10,5,8 });
	cout << k << endl;
	return 0;
}