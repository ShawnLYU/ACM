#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;
#define MAXIMUM 100
int main() {
	string kingdom[MAXIMUM];
	int x = 0;
	int sum = 0;
	bool isFirstLine = true;
	while (getline(cin, kingdom[x])) {
		int length;
		if (kingdom[x].length() != 0) {
			length = kingdom[x].length();
			for (int i = 0; i < length - 1; i++) {
				if (kingdom[x][i] != kingdom[x][i + 1]) {
					sum++;
				}
			}
			if (!isFirstLine) {
				if (x & 1) {//odd
					for (int i = 0; i < length - 1; i++) {
						if (kingdom[x][i] != kingdom[x - 1][i])
							sum++;
						if (kingdom[x][i] != kingdom[x - 1][i + 1])
							sum++;
					}
					if (kingdom[x][length - 1] != kingdom[x - 1][length - 1])
						sum++;
				}
				else {//even
					if (kingdom[x][0] != kingdom[x - 1][0])
						sum++;
					for (int i = 1; i < length; i++) {
						if (kingdom[x][i] != kingdom[x - 1][i])
							sum++;
						if (kingdom[x][i] != kingdom[x - 1][i - 1])
							sum++;
					}
				}
			}
			else {
				isFirstLine = false;
			}
			x++;
		}
		else {
			for (int i = 0; i < x; i++) {
				kingdom[i].clear();
			}
			cout << sum << endl;
			sum = 0;
			x = 0;
			isFirstLine = true;
		}
	}
	return 0;
}