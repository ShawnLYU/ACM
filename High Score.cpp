#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int min(int a, int b) {
	return a < b ? a : b;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		int needs[1010];
		int count_tmp = 0, count;
		char input[1010];
		scanf("%s", input);
		int steps = 0, len = strlen(input), tmp_lastl, tmp_lastr;
		for (int j = 0; j<len; j++) {
			steps += min(input[j] - 'A', 'Z' - input[j] + 1);
			if (min(input[j] - 'A', 'Z' - input[j] + 1) != 0) {
				needs[count_tmp] = j;
				count_tmp++;
			}
		}
		count = count_tmp;
		if (steps == 0 || count == 0) {
			printf("%d\n", steps);
			continue;
		}
		if (count == 1) {
			printf("%d\n", min(needs[0], len - needs[0]) + steps);
			continue;
		}
		if (needs[0] == 0) {
			tmp_lastr = len - needs[1];
			for (int j = 1; j<count - 1; j++)
				tmp_lastr = min(needs[j] * 2 + len - needs[j + 1], tmp_lastr);
			tmp_lastl = needs[count - 1];
			for (int j = 1; j<count - 1; j++)
				tmp_lastl = min((len - needs[j + 1]) * 2 + needs[j], tmp_lastl);
		}
		else {
			tmp_lastr = len - needs[0];
			for (int j = 0; j<count - 1; j++)
				tmp_lastr = min(needs[j] * 2 + len - needs[j + 1], tmp_lastr);
			tmp_lastl = needs[count - 1];
			for (int j = 0; j<count - 1; j++)
				tmp_lastl = min((len - needs[j + 1]) * 2 + needs[j], tmp_lastl);
		}


		printf("%d\n", min(tmp_lastr, tmp_lastl) + steps);
		
	}
	return 0;
}