/*
 * https://leetcode.com/problems/reverse-words-in-a-string/
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

class Solution151 {
public:
	void reverseWords(string &s) {
		// Reverse words
	   // 1. Reverse string
		reverse(s.begin(), s.end());

		// 2. Reverse words
		int start = 0;
		int end = 0;
		while ((end < s.size()) && ((end = s.find(' ', start)) != std::string::npos))
		{
			reverse(s.begin() + start, s.begin() + end);

			// remvoe multiple spaces
			while (s[end] == ' ')
			{
				++end;
			}
			start = end;
		}

		// 3. Reverse last word
		reverse(s.begin() + start, s.end());


		// 4. Clean up leading spaces
		while (s[0] == ' ')
		{
			s.erase(0, 1);
		}

		// Clean-up trailing spaces
		while (s[s.length() - 1] == ' ')
		{
			s.erase(s.length() - 1, 1);
		}

		// 4. Clean up spaces in between words
		int writeIndex = 0;
		for (auto i = 0; i < s.length();)
		{
			if (s[i] != ' ')
			{
				s[writeIndex++] = s[i++];
			}
			else
			{
				// keep 1 space
				s[writeIndex++] = s[i++];

				while (s[i] == ' ')
				{
					++i;
				}
			}
		}

		while (writeIndex < s.length())
		{
			s[writeIndex++] = '\0';
		}
	}
};
