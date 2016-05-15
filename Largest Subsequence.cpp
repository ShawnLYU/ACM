#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input, tmp;
		cin >> input;
		tmp = input;
		for (int j = input.length() - 2; j > -1; j--) 
			if ((int)tmp[j] < (int)tmp[j + 1])
				tmp[j] = tmp[j + 1];
		for (int j = 0; j < input.length(); j++)
			if (tmp[j] == input[j])
				cout << input[j];
		cout << endl;
	}
	cin >> n;
	return 0;
}