#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;
static int result[8] = { 0 };
static int diff_x[8] = { 0 };
static int diff_y[8] = { 0 };
static int numOfResult = 0;
static int initial = 0;
void printOutResult() {//1 line of result
	numOfResult++;
	if (numOfResult<10) {
		cout << " " << numOfResult << "     ";//5 spaces
	}
	else {
		cout << numOfResult << "     ";//5 spaces
	}
	for (int i = 0; i<8; i++) {
		cout << " " << result[i];
	}
	cout << endl;
}
void eightQueens(int colToBeSet) {
	if (colToBeSet != initial) {
		if (colToBeSet == 8) {
			printOutResult();
		}
		else {
			for (int i = 1; i <= 8; i++) {
				bool valid = true;
				for (int j = 0; j<colToBeSet; j++) {
					if (result[j] == i || diff_x[j] == (colToBeSet - i) || diff_y[j] == (8 - colToBeSet) - i) {
						valid = false;
						break;
					}
				}
				if (result[initial] == i || diff_x[initial] == (colToBeSet - i) || diff_y[initial] == (8 - colToBeSet) - i) {
					valid = false;
				}
				if (valid) {
					int next = colToBeSet + 1;
					result[colToBeSet] = i;
					diff_x[colToBeSet] = colToBeSet - i;
					diff_y[colToBeSet] = (8 - colToBeSet) - i;
					eightQueens(next);
				}
			}
			diff_x[colToBeSet] = 0;
			diff_y[colToBeSet] = 0;
			result[colToBeSet] = 0;
		}
	}
	else {
		int next = colToBeSet + 1;
		eightQueens(next);
	}

}
int main() {
	int tot;
	string tmp;
	cin >> tot;
	getline(cin, tmp);
	getline(cin, tmp);
	bool isFirstTime = true;
	for (int i = 0; i<tot; i++) {
		numOfResult = 0;
		for (int j = 0; j<8; j++) {
			result[j] = 0;
			diff_x[j] = 0;
			diff_y[j] = 0;
		}
		string input;
		int row = 0, col = 0;
		scanf("%d %d", &row, &col);
		if (!isFirstTime) {
			cout << endl;
		}
		cout << "SOLN" << "       " << "COLUMN" << endl;//7 spaces
		cout << " " << "#" << "     ";//5 spaces
		for (int i = 1; i <= 8; i++) {
			cout << " " << i;
		}
		cout << endl<<endl;
		initial = col - 1;
		result[initial] = row;
		diff_x[initial] = col - 1 - row;
		diff_y[initial] = (8 - (col - 1)) - row;
		eightQueens(0);
		if (isFirstTime)
			isFirstTime = false;
		getline(cin, tmp);
	}
	//cin >> tmp;
	return 0;
}