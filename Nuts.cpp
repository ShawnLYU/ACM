#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;
int main() {
	string input;
	int k, a, b, v, n, num;
	while (getline(cin, input)) {
		n = 0;
		num = 0;
		stringstream myStream(input);
		myStream >> k >> a >> b >> v;
		if (k >= (b + 1)) {
			while ((b + 1 + num)*v<a)
				num++;
			num += 1;
		}
		else {
			n = b / (k - 1);
			int tmp = n*k*v;
			if (tmp >= a) {
				while (num*k*v<a)
					num++;
			}
			else {
				int divisorsUsed = n*(k - 1);
				while (((b - divisorsUsed) + 1 + num)*v<(a - tmp))
					num++;
				num += (n + 1);
			}
		}

		cout << num << endl;

	}
	return 0;
}