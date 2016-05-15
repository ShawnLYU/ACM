#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include <string.h>
using namespace std;
#define MAXDIGITS 255
#define MAXLINES 1000
#define p(y) printf("%s\n",y)
int isPrime(int num) {
	if (num == 1) return 0; //1
	if (num == 2) return 1; //2
	if ((num & 1) == 0) return 0; //even
	for (int i = 3; i < (sqrt((double)num) + 1); i += 2)
		if (num % i == 0) return 0;
	return 1;
}
int main() {
	string tmp;
	long result[MAXLINES];
	int length = 0;
	int z = 0;
	cin >> tmp;
	while (tmp!="0") {
		length = tmp.length();
		long maxPrime = 0;

		for (int i = 1; (i <= 5) && (i<= length); i++) {//i digits maxmum digits: 5
			for (int j = 0; j <= (length - i); j++) {
				string num = tmp.substr(j, i);
				long number = stol(num);
				//printf("%ld\n", number);
				if (isPrime(number) && number>maxPrime) {
					maxPrime = number;
				}
				//printf("%ld\n", maxPrime);
			}
		}
		result[z++] = maxPrime;
		//printf("%ld\n", maxPrime);
		cin >> tmp;
	}
	for (int i = 0; i < z; i++)
		cout << result[i]<<endl;
	//cin >> tmp;
	return 0;
}