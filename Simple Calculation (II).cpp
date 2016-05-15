#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <math.h> 
using namespace std;
int main() {
	string input;
	bool isFirst = true;
	while (getline(cin, input)) {
		long double sum = 0;
		stringstream myStream(input);
		long double num;
		while (myStream >> num) {
			sum += num;
		}
		//round(sum * 10000.0) / 10000.0
		if (!isFirst) {
			cout << '\n' ;
			printf("%.4Lf", sum);
			cout << '\n';
		}
		else {
			isFirst = false;
			
			printf("%.4Lf", sum);
			cout << '\n';
		}
	}
	//cin >> input;
	return 0;
}