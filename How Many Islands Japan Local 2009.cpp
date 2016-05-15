#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int TRUE = 0;
int h, w;
int map[51][51];
int visited[51][51];
bool DFS(int row, int column) {
	if (map[row][column] == 1 && visited[row][column] != TRUE) {
		visited[row][column] = TRUE;
		// cout << endl << "row: " << row << "column: " << column << endl;
		if (row - 1 >= 0 && column - 1 >= 0 && visited[row - 1][column - 1] != TRUE)
			DFS(row - 1, column - 1);
		if (row - 1 >= 0 && visited[row - 1][column] != TRUE)
			DFS(row - 1, column);
		if (row - 1 >= 0 && column + 1<w && visited[row - 1][column + 1] != TRUE)
			DFS(row - 1, column + 1);
		if (column - 1 >= 0 && visited[row][column - 1] != TRUE)
			DFS(row, column - 1);
		if (column + 1<w && visited[row][column + 1] != TRUE)
			DFS(row, column + 1);
		if (row + 1<h && column - 1 >= 0 && visited[row + 1][column - 1] != TRUE)
			DFS(row + 1, column - 1);
		if (row + 1<h && visited[row + 1][column] != TRUE)
			DFS(row + 1, column);
		if (row + 1<h && column + 1<w && visited[row + 1][column + 1] != TRUE)
			DFS(row + 1, column + 1);
		return true;
	}
	else {
		return false;
	}

}

int main() {
	int count;
	scanf("%d %d", &w, &h);
	while ( w != 0 || h != 0 ) {
		TRUE++;
		count = 0;
		string input;
		string tmp;
		getline(cin, tmp);
		for (int i = 0; i<h; i++) {
			getline(cin, input);
			stringstream myStream(input);
			for (int j = 0; j<w; j++) {
				int tmp;
				myStream >> tmp;
				map[i][j] = tmp;
			}
		}
		for (int i = 0; i<h; i++) {
			for (int j = 0; j<w; j++) {
				if (DFS(i, j)) {
					count++;
				}
			}
		}
		cout << count << endl;
		scanf("%d %d", &w, &h);
	}
	return 0;
}