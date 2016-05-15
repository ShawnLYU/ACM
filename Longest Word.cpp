#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string tmp, longest;
	cin >> tmp;
	while (tmp != "E-N-D") {
		int length = tmp.length();
		for (int i = 0; i < length; i++) {
			if ((!isalpha(tmp[i])) && (tmp[i] != '-')) {
				tmp.erase(i, 1);
				i--;
				length--;
			}
			else if ((isalpha(tmp[i])) && (isupper(tmp[i]))) {
				tmp[i] = tmp[i] - ('A' - 'a');
			}
		}
		if (tmp.length() > longest.length())
			longest = tmp;
		cin >> tmp;
	}
	cout << longest << endl;
	return 0;
}