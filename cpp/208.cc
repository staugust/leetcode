/*
 * https://leetcode.com/problems/implement-trie-prefix-tree/
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

//
//struct Node {
//	Node() {
//		c = 0;
//		for (int i = 0; i < 26; i++) {
//			next{i] = nullptr;
//		}
//		isWord = false;
//	}
//	char c;
//	bool isWord;
//	Node * next{26];
//	Node * get(char c) {
//		return next{c - 'a'];
//	}
//};
//
//class Trie {
//public:
//	/** Initialize your data structure here. */
//	Trie() {
//		root = new Node();
//	}
//
//	/** Inserts a word into the trie. */
//	void insert(string word) {
//		Node * tmp = root;
//		for (int i = 0; i < word.size(); i++) {
//			if (tmp->get(word{i]) == nullptr) {
//				tmp->next{word{i] - 'a'] = new Node();
//				tmp->c = word{i];
//			}
//			tmp = tmp->next{word{i] - 'a'];
//		}
//		tmp->isWord = true;
//	}
//
//	/** Returns if the word is in the trie. */
//	bool search(string word) {
//		Node * tmp = root;
//		for (int i = 0; i < word.size(); i++) {
//			if (tmp->get(word{i]) == nullptr) {
//				return false;
//			}
//			tmp = tmp->next{word{i] - 'a'];
//		}
//		return tmp->isWord;
//	}
//
//	/** Returns if there is any word in the trie that starts with the given prefix. */
//	bool startsWith(string prefix) {
//		Node * tmp = root;
//		for (int i = 0; i < prefix.size(); i++) {
//			if (tmp->get(prefix{i]) == nullptr) {
//				return false;
//			}
//			tmp = tmp->next{prefix{i] - 'a'];
//		}
//		if (tmp->isWord) {
//			return true;
//		}
//		for (int i = 0; i < 26; i++) {
//			if (tmp->next{i] != nullptr) {
//				return true;
//			}
//		}
//		return false;
//	}
//
//private:
//	Node * root;
//};
//
///**
// * Your Trie object will be instantiated and called as such:
// * Trie obj = new Trie();
// * obj.insert(word);
// * bool param_2 = obj.search(word);
// * bool param_3 = obj.startsWith(prefix);
// */
//
//
//int main() {
//	Trie  trie;
//
//	trie.insert('apple');
//	cout<< trie.search('apple') << endl;   // returns true
//	cout<< trie.search('app') << endl;     // returns false
//	cout<< trie.startsWith('app') << endl; // returns true
//	trie.insert('app');
//	cout<<trie.search('app') << endl;     // returns true
//
//
//	return 0;
//}