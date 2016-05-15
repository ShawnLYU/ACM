#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define MAXIMUM 126
#define INFINITY 1000000
#define CONFIRMED -1

int Q[MAXIMUM][MAXIMUM];

bool isFinished(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Q[i][j] != CONFIRMED) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int size;
	int count = 0;
	int input[MAXIMUM][MAXIMUM];
	int output[MAXIMUM][MAXIMUM];
	cin >> size;
	while (size != 0) {
		count++;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cin >> input[i][j];
			}
		}

		for (int i = 0; i<size; i++)
			for (int j = 0; j<size; j++)
				Q[i][j] = INFINITY;
		//memset(Q, INFINITY, sizeof(Q));
		Q[0][0] = input[0][0];
		while (!isFinished(size)) {
			int x, y;
			int tmp = INFINITY;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (Q[i][j] != CONFIRMED && Q[i][j] != INFINITY) {
						if (Q[i][j] < tmp) {
							tmp = Q[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
			output[x][y] = tmp;
			Q[x][y] = CONFIRMED;
			//relaxation
			//left
			if (x - 1 >= 0 && Q[x - 1][y] != CONFIRMED) {
				int t = output[x][y] + input[x - 1][y];
				Q[x - 1][y] = t<Q[x - 1][y] ? t : Q[x - 1][y];
			}
			//right
			if (x + 1<size && Q[x + 1][y] != CONFIRMED) {
				int t = output[x][y] + input[x + 1][y];
				Q[x + 1][y] = t<Q[x + 1][y] ? t : Q[x + 1][y];
			}
			//up
			if (y - 1 >= 0 && Q[x][y - 1] != CONFIRMED) {
				int t = output[x][y] + input[x][y - 1];
				Q[x][y - 1] = t<Q[x][y - 1] ? t : Q[x][y - 1];
			}
			//down
			if (y + 1<size && Q[x][y + 1] != CONFIRMED) {
				int t = output[x][y] + input[x][y + 1];
				Q[x][y + 1] = t<Q[x][y + 1] ? t : Q[x][y + 1];
			}
		}

		cout << "Problem " << count << ": " << output[size - 1][size - 1] << endl;


		// for (int i = 0; i < size; i++) {
		// 	for (int j = 0; j < size; j++){
		// 		cout << output[i][j]   ;
		// 	}
		// 	cout << endl;
		// }

		cin >> size;
	}
	return 0;
}