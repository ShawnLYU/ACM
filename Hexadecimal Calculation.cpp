#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int expression();
int item();
int num();
int multi();
const char * expressionToParse;

char current()
{
	return *expressionToParse;
}

char next()
{
	return *expressionToParse++;
}
int num()
{
	int result = next() - '0';
	while (current() >= '0' && current() <= '9')
	{
		result = 10 * result + next() - '0';
	}
	return result;
}

int multi()
{
	if (current() >= '0' && current() <= '9')
		return num();
	else if (current() == '(')
	{
		next();
		int result = expression();
		next();
		return result;
	}
	return 0;
}

int item()
{
	int result = multi();
	while (current() == '*')
		if (next() == '*')
			result *= multi();
	return result;
}

int expression()
{
	int result = item();
	while (current() == '+')
		if (next() == '+')
			result += item();
	return result;
}

int main()
{
	string tmp;
	while (cin >> tmp) {
		char inputArray[110];
		string input;
		int pos = 0;
		int length = 0;
		for (int i = 0; i < tmp.length(); i++) {
			if (tmp[i] == '+' || tmp[i] == '*' || tmp[i] == '(' || tmp[i] == ')') {
				if (length != 0) {
					int x;
					string t = tmp.substr(pos, length);
					stringstream ss;
					ss << hex << t;
					ss >> x;
					input += to_string(x);
				}
				pos = i + 1;
				length = 0;

				input += tmp[i];
			}
			else {
				length++;
			}
		}
		if (length != 0) {
			input += tmp.substr(pos, length);
		}
		strcpy(inputArray, input.c_str());
		expressionToParse = inputArray;
		int result = expression();
		cout << hex << uppercase << result << endl;
	}
	return 0;
}