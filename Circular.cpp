#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define N 1000000

bool isprime(int n)
{
	long i, j;
	if ((n & 1) == 0) 
		return false; //even
	j = (long)sqrt((double)n);
	for (i = 3; i <= j; i += 2)
		if (n%i == 0) 
			return false;
	return true;
}

bool isCircular(int n){
	int len = (int)log10(n) + 1;
	for (int i = 0; i < len; i++){
		n = n % (int)pow(10, len - 1) * 10 + n / (int)pow(10, len - 1);
		if (!isprime(n))
			return false;
	}
	return true;
}

int main(){
	map<int, bool> judgePrime;
	int start, end;
	vector<int> allPrimes;
	vector<int> allCirculars;

	for (int i = 101; i < N; i++){
		if (isprime(i)){
			allPrimes.push_back(i);
			judgePrime[i] = true;
		}
	}

	for (int i = 0; i < allPrimes.size(); i++){
		if (isCircular(allPrimes[i]))
			allCirculars.push_back(allPrimes[i]);
	}
	cin >> start;
	while (start!=-1){
		cin >> end;
		int ans = 0;
		for (int i = 0; i < allCirculars.size(); i++){
			if (allCirculars[i] > end)
				break;
			if (allCirculars[i] < start)
				continue;
			ans++;
		}
		if (ans == 0)
			cout << "No Circular Primes." << endl;
		else if (ans == 1)
			cout << "1 Circular Prime." << endl;
		else
			printf("%d Circular Primes.\n", ans);

		cin >> start;
	}
	return 0;
}