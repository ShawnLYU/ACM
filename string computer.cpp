#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXDIGITS 30
#define INFINITY 1000000

char a[MAXDIGITS], b[MAXDIGITS];
int  path[MAXDIGITS][MAXDIGITS];

void output(int input, int target)
{

	if (input == 0 && target == 0)
		return;
	else if (path[input][target] == 0)
		output(input - 1, target - 1);
	else if (path[input][target] == 1)
	{
		output(input - 1, target);
		cout << "D" << a[input];
		printf("%02d", target + 1);
	}
	else if (path[input][target] == 2)
	{
		output(input, target - 1);
		cout << "I" << b[target];
		printf("%02d", target);
	}
	else if (path[input][target] == 3)
	{
		output(input - 1, target - 1);
		cout << "C" << b[target];
		printf("%02d", target);
	}
}

int main()
{
	int length_a, length_b;
	int dist[MAXDIGITS][MAXDIGITS];
	scanf("%s", a + 1);
	while (a[1] != '#')
	{
		scanf("%s", b + 1);
		length_a = strlen(a + 1);
		length_b = strlen(b + 1);
		for (int i = 0; i <= length_a; i++)
			for (int j = 0; j <= length_b; j++) {
				path[i][j] = -1;
				dist[i][j] = INFINITY;
			}

		for (int i = 0; i < length_a + 1; i++) {
			dist[i][0] = i;
			path[i][0] = 1;
		}
		for (int i = 0; i < length_b + 1; i++) {
			dist[0][i] = i;
			path[0][i] = 2;
		}

		for (int i = 1; i < length_a + 1; i++)
			for (int j = 1; j < length_b + 1; j++)
			{
				int tmp[3], method;
				tmp[0] = dist[i - 1][j] + 1;
				tmp[1] = dist[i][j - 1] + 1;
				tmp[2] = dist[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1);
				for (int m = 0; m < 3; m++)
					if (tmp[m]<dist[i][j])
					{
						dist[i][j] = tmp[m];
						method = m + 1;
					}
				if (method == 3 && a[i] == b[j])
					path[i][j] = 0;
				else
					path[i][j] = method;
			}
		output(length_a, length_b);
		puts("E");
		scanf("%s", a + 1);
	}
	return 0;
}