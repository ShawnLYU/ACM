#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
#define N 50000010

bool primes[N];

void preparePrimes()
{
	memset(primes, true, sizeof(primes));
	primes[0] = false;
	primes[1] = false;
	for (int i = 2; i < 10000; i++) {
		if (primes[i]) {
			for (int j = i * i; j < N; j += i) {
				if(j<N)
					primes[j] = false;
			}
		}
	}
}

bool isprime(long n)
{
	long i, j;
	if (n<4) return true;
	if ((n & 1) == 0) return false; //even
	j = (long)sqrt((double)n);
	for (i = 3; i <= j; i += 2)
		if (n%i == 0) return 0;
	return true;

}
int main()
{
	int input;
	preparePrimes();
	while (scanf("%d", &input) != EOF) {
		bool flag = true;
		if ((input % 2) == 1) {
			if (input > 2 && isprime(input - 2)) {
				printf("%d is the sum of %d and %d.\n", input, 2, input - 2);
			}
			else {
				printf("%d is not the sum of two primes!\n", input);
			}
		}
		else {
			for (int i = input / 2; i >= 1; i--) {
				if (primes[i] && primes[input - i] && (i != input - i)) {
					printf("%d is the sum of %d and %d.\n", input, i, input - i);
					flag = false;
					break;
				}
			}
			if (flag) {
				printf("%d is not the sum of two primes!\n", input);
			}
		}
	}
	return 0;
}