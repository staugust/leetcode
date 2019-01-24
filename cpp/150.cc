/*
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
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
#include <stack>
using namespace std;

class Solution150 {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> operands;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] == "+") {
				int op1 = operands.top();
				operands.pop();
				int op2 = operands.top();
				operands.pop();
				operands.push(op1 + op2);
			}else if (tokens[i] == "-") {
				int op2 = operands.top();
				operands.pop();
				int op1 = operands.top();
				operands.pop();
				operands.push(op1 - op2);
			}
			else if (tokens[i] == "*") {
				int op1 = operands.top();
				operands.pop();
				int op2 = operands.top();
				operands.pop();
				operands.push(op1 * op2);
			}
			else if (tokens[i] == "/") {
				int op2 = operands.top();
				operands.pop();
				int op1 = operands.top();
				operands.pop();
				operands.push(op1 / op2);
			}
			else{
				operands.push(stoi(tokens[i]));
			}
		}
		return operands.top();
	}
};

//int main() {
//	vector<string> vec = { "2","1","+","3","*" };
//	Solution s;
//	int r = s.evalRPN(vec);
//	cout << r << endl;
//
//
//	return 0;
//}


