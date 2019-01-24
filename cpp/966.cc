/*
 * https://leetcode.com/problems/vowel-spellchecker/
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
#include <unordered_set>
using namespace std;


class Solution966 {
public:
	unordered_set<string> perWord;
	unordered_map<string, string> worddeCap;
	unordered_map<string, string> worddeVow;

	vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

		for (string word : wordlist) {
			perWord.insert(word);

			string wordlow = "";
			for (int i = 0; i < word.length(); i++) {
				wordlow += tolower(word[i]);
			}
			if (!worddeCap.count(wordlow))
				worddeCap[wordlow] = word;

			string wordlowDV = devowel(wordlow);
			if (!worddeVow.count(wordlowDV))
				worddeVow[wordlowDV] = word;
		}

		vector<string> ans;
		for (string query : queries) {
			ans.push_back(solve(query));
		}


		return ans;
	}

	string solve(string query) {
		if (perWord.count(query)) {
			return query;
		}
		string querylow = "";
		for (int i = 0; i < query.length(); i++) {
			querylow += tolower(query[i]);
		}
		if (worddeCap.count(querylow)) {
			return worddeCap[querylow];
		}

		string querylowDV = devowel(querylow);
		if (worddeVow.count(querylowDV)) {
			return worddeVow[querylowDV];
		}

		string str = "";
		return str;
	}

	string devowel(string word) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
				word[i] = '*';
			}
		}

		return word;
	}
};