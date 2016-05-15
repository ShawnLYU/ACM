#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int tot;
	string tmp;
	cin >> tot;
	getline(cin, tmp);
	for (int i = 0; i<tot; i++) {
		int num = 0;
		cin >> num;
		if (num == 1)
			cout << 0 << endl;
		else
			cout << num - 2 << endl;
	}
	return 0;
}