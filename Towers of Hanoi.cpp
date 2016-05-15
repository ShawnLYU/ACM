#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
static int steps = 0;
void advancedHanoi(int n, char A, char B, char C) {
	if (n == 0) {
		return;
	}
	advancedHanoi(n - 1, A, B, C);
	steps++;
	//printf("%c -> %c\n", A, B);
	advancedHanoi(n - 1, C, B, A);
	steps++;
	//printf("%c -> %c\n", B, C);
	advancedHanoi(n - 1, A, B, C);
}


int main()
{
	int num = 0;
	while (scanf("%d", &num) != EOF) {
		steps = 0;
		advancedHanoi(num, 'A', 'B', 'C');
		cout << steps << endl;
	}
	return 0;
}