//Sphere online judge
//PPATH - Prime Path
// The ministers of the cabinet were quite upset by the message from the Chief of Security stating that they would all have to change the four-digit room numbers on their offices. 
// — It is a matter of security to change such things every now and then, to keep the enemy in the dark.
// — But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know!
// — I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your office door.
// — No, it's not that simple. Suppose that I change the first digit to an 8, then the number will read 8033 which is not a prime!
// — I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds.
// — Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime.

// Now, the minister of finance, who had been eavesdropping, intervened.
// — No unnecessary expenditure, please! I happen to know that the price of a digit is one pound.
// — Hmm, in that case I need a computer program to minimize the cost. You don't know some very cheap software gurus, do you?
// — In fact, I do. You see, there is this programming contest going on...

// Help the prime minister to find the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. Here is a solution in the case above.
// 1033
// 1733     
// 3733     
// 3739     
// 3779
// 8779
// 8179
// The cost of this solution is 6 pounds. Note that the digit 1 which got pasted over in step 2 can not be reused in the last step – a new 1 must be purchased.
// Input

// One line with a positive number: the number of test cases (at most 100). Then for each test case, one line with two numbers separated by a blank. Both numbers are four-digit primes (without leading zeros).

// Output

// One line for each case, either with a number stating the minimal cost or containing the word Impossible.

// Example

// Input:
// 3
// 1033 8179
// 1373 8017
// 1033 1033

// Output:
// 6
// 7
// 0    

#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include <iostream>
using namespace std;

#define MAXIMUM 10001
int origin, target;
int visited[MAXIMUM] = { 0 };
int TRUE = 1;

struct v
{
	int number;
	int dist;
};
queue<v> points;
bool isPrime(int e) {
	if (e == 0 || e == 1) { return false; }
	else if (e == 2 || e == 3) { return true; }
	else {
		for (int i = 2; i<(int)sqrt(e); i++) {
			if (e%i == 0)
				return false;
		}
		return true;
	}

}

int BFS() {
	while (!points.empty()) {
		v tmp = points.front();
		int d = tmp.dist;
		points.pop();
		if (tmp.number == target)
			return d;

		for (int i = 1; i <= 9; i++) {
			int newPoint = i * 1000 + tmp.number % 1000;
			if (isPrime(newPoint) && newPoint != tmp.number && visited[newPoint] != TRUE) {
				v newTmp;
				newTmp.number = newPoint;
				newTmp.dist = d + 1;
				visited[newPoint] = TRUE;
				points.push(newTmp);
			}
		}

		for (int i = 0; i <= 9; i++) {
			int newPoint = tmp.number / 1000 * 1000 + i * 100 + tmp.number % 100;
			if (isPrime(newPoint) && newPoint != tmp.number && visited[newPoint] != TRUE) {
				v newTmp;
				newTmp.number = newPoint;
				newTmp.dist = d + 1;
				visited[newPoint] = TRUE;
				points.push(newTmp);
			}
		}

		for (int i = 0; i <= 9; i++) {
			int newPoint = tmp.number / 100 * 100 + i * 10 + tmp.number % 10;
			if (isPrime(newPoint) && newPoint != tmp.number && visited[newPoint] != TRUE) {
				v newTmp;
				newTmp.number = newPoint;
				newTmp.dist = d + 1;
				visited[newPoint] = TRUE;
				points.push(newTmp);
			}
		}

		for (int i = 1; i <= 9; i += 2) {
			int newPoint = tmp.number / 10 * 10 + i;
			if (isPrime(newPoint) && newPoint != tmp.number && visited[newPoint] != TRUE) {
				v newTmp;
				newTmp.number = newPoint;
				newTmp.dist = d + 1;
				visited[newPoint] = TRUE;
				points.push(newTmp);
			}
		}
	}
	return -1;
}

int main() {
	int tot;
	cin >> tot;
	while (tot--) {
		int result;
		cin >> origin >> target;
		while (!points.empty()) points.pop();
		TRUE++;
		v _origin;
		_origin.number = origin;
		_origin.dist = 0;
		visited[_origin.number] = TRUE;
		points.push(_origin);
		result = BFS();
		if (result == -1)
			cout << "Impossible" << endl;
		else
			cout << result << endl;
	}
	cin>>tot;
	return 0;
}