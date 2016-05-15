#include <stdio.h>
#include <iostream>
using namespace std;
int main() {

	int n, m;
	cin >> n >> m;
	while (n != 0 && m != 0) {
		bool isTwo = false;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				int tmp;
				cin >> tmp;
				if (i*j == 0 || i == n - 1 || j == m - 1) {
					if (tmp == 1) {
						isTwo = true;
					}
				}
			}
		}

		if (isTwo)
			cout << 2 << endl;
		else
			cout << 4 << endl;
		cin >> n >> m;
	}
	return 0;
}