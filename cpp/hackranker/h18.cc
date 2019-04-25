/*
 * https://www.hackerrank.com/challenges/the-time-in-words/problem
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

string min2Word(int k) {
	switch (k)
	{
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	case 10:
		return "ten";
	case 11:
		return "eleven";
	case 12:
		return "twelve";
	case 13:
		return "thirteen";
	case 14:
		return "fourteen";
	case 15:
		return "quarter";
	case 16:
		return "sixteen";
	case 17:
		return "seventeen";
	case 18:
		return "eighteen";
	case 19:
		return "nineteen";
	case 20:
		return "twenty";
	case 21:
		return "twenty one";
	case 22:
		return "twenty two";
	case 23:
		return "twenty three";
	case 24:
		return "twenty four";
	case 25:
		return "twenty five";
	case 26:
		return "twenty six";
	case 27:
		return "twenty seven";
	case 28:
		return "twenty eight";
	case 29:
		return "twenty nine";
	case 30:
		return "half";
	default:
		break;
	}
	return "";
}
string hour2word(int h) {
	switch (h)
	{
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	case 10:
		return "ten";
	case 11:
		return "eleven";
	case 12:
		return "twelve";
	default:
		break;
	}
	return "";
}
string timeInWords(int h, int m) {
	if (m == 0) {
		return hour2word(h) + " o' clock";
	}
	string tm = "";
	bool isPast = (m <= 30);
	if (m > 30) {
		m = 60 - m;
		h += 1;
	}
	tm += min2Word(m);
	if (m == 1) {
		tm += " minute ";
	}
	else if (m == 15 || m == 30) {
		tm += " ";
	}
	else {
		tm += " minutes ";
	}
	tm += (isPast ? "past " : "to ");
	tm += hour2word(h);
	return tm;
}

