#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
#define MAXIMUM 1000000
int input[MAXIMUM];
int dp[MAXIMUM];

int main() {

	int n;
	while (cin >> n) {
		int maxLen = 1;
		for (int i = 0; i<n; i++)
			cin >> input[i];

		int start, end, middle;
		dp[0] = -1;
		dp[1] = input[0];
		for (int i = 1; i<n; i++) {
			start = 0;
			end = maxLen;
			while (start <= end) {
				middle = (start + end) / 2;
				if (dp[middle] <= input[i])
					start = middle + 1;
				else
					end = middle - 1;
			}
			dp[start] = input[i];
			if (start > maxLen)
				maxLen++;
		}

		cout << maxLen << endl;

	}
	return 0;
}