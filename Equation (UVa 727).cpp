#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stack>
using namespace std;

bool isOperator(char symbol)
{
	if ((symbol == '*') || (symbol == '/') || (symbol == '+') || (symbol == '-'))
		return true;
	else
		return false;
}
bool isOperand(char symbol) {
	if ((int)symbol <= 57 && (int)symbol >= 48) {
		return true;
	}
	else {
		return false;
	}
}

int ranking(char symbol) {
	switch (symbol) {
	case '(': return 1;
	case ')': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	}
}

int main() {
	int tot;
	bool isFirstTime = true;
	string tmp;
	cin >> tot;
	getline(cin, tmp);
	getline(cin, tmp);
	for (int i = 0; i<tot; i++) {
		string term;
		string input;
		string output;
		while (getline(cin, term)) {
			if (term.length() != 0) {
				input += term;
			}
			else {
				break;
			}
		}
		stack<char> s;
		for (int j = 0; j<input.length(); j++) {
			if (isOperand(input[j])) {
				output += input[j];
			}
			else if (isOperator(input[j])) {//operator
				while (s.size() != 0 && ranking(input[j]) <= ranking(s.top())) {
					output += s.top();
					s.pop();
				}
				s.push(input[j]);
			}
			else if (input[j] == '(') {
				s.push(input[j]);
			}
			else if (input[j] == ')') {
				while (s.top() != '(') {
					output += s.top();
					s.pop();
				}
				s.pop();
			}
		}
		while (!s.empty()) {
			output += s.top();
			s.pop();
		}
		if(isFirstTime){
			isFirstTime = false;
			cout << output << endl;
		}
		else				
			cout << endl << output << endl;
	}
	return 0;
}