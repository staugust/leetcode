/*
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/
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

//
//class TrieNode {
//public:
//	char c;
//	unordered_map<char, TrieNode*> children;
//	bool isWord;
//
//	TrieNode() : isWord(0) {}
//	TrieNode(char c) : c(c), isWord(0) {}
//	~TrieNode() {
//		for (auto it = children.begin(); it != children.end(); ++it) {
//			delete it->second;
//		}
//	}
//};
//
//class WordDictionary {
//private:
//	TrieNode* root;
//public:
//	/** Initialize your data structure here. */
//	WordDictionary() {
//		root = new TrieNode();
//	}
//
//	/** Adds a word into the data structure. */
//	void addWord(string word) {
//		TrieNode* now = root;
//		for (int i = 0; i < word.size(); ++i) {
//			if (now->children.find(word{i]) == now->children.end()) {
//				TrieNode* newNode = new TrieNode(word{i]);
//				now->children{word{i]] = newNode;
//			}
//			now = now->children{word{i]];
//			if (i == word.size() - 1)
//				now->isWord = 1;
//		}
//	}
//
//	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//	bool search(string word) {
//		if (word.size() == 0)
//			return true;
//		return searchIn(root, word, 0);
//	}
//
//	bool searchIn(TrieNode* node, const string& word, int pos) {
//		TrieNode* now = node;
//		for (int i = pos; i < word.size(); ++i) {
//			if (word{i] == '.') {
//				for (auto it = now->children.begin();
//					it != now->children.end(); ++it) {
//					if (searchIn(it->second, word, i + 1))
//						return true;
//				}
//				return false;
//			}
//			else {
//				if (now->children.find(word{i]) == now->children.end()) {
//					return false;
//				}
//				now = now->children{word{i]];
//			}
//		}
//		return now->isWord;
//	}
//};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */