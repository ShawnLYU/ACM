#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define MAXLENGTH 1100

int map[MAXLENGTH][MAXLENGTH];

void findLength(char *input, char *target, int lena, int lenb)
{
	for (int i = 0; i <= lena; i++)
		for (int j = 0; j <= lenb; j++)
		{
			if (i*j == 0)
				map[i][j] = 0;
			else if (input[i - 1] == target[j - 1])
				map[i][j] = map[i - 1][j - 1] + 1;
			else
				map[i][j] = max(map[i - 1][j], map[i][j - 1]);
		}
}

int main()
{
	char input[MAXLENGTH];
	char target[MAXLENGTH];
	string line1, line2;
	while (getline(cin, line1)) {
		getline(cin, line2);
		if (line1.length() == 0 || line2.length() == 0) {
			cout << 0 << endl;
			continue;
		}
		strcpy(input, line1.c_str());
		strcpy(target, line2.c_str());
		findLength(input, target, strlen(input), strlen(target));
		cout << map[strlen(input)][strlen(target)] << endl;
	}
	return 0;
}