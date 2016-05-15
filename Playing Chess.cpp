#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
int TRUE = 0;
int visited[8][8];
char map[8][8];
struct chess
{
	int row, col;
	int step;
};
queue<chess> chesses;
int BFS() {
	while (!chesses.empty()) {
		int row_tmp, col_tmp, step_tmp;
		chess tmp = chesses.front();
		chesses.pop();
		row_tmp = tmp.row;
		col_tmp = tmp.col;
		step_tmp = tmp.step;
		if (map[row_tmp][col_tmp] == '@')
			return tmp.step;
		if (row_tmp - 2 >= 0 && col_tmp - 1 >= 0 && visited[row_tmp - 2][col_tmp - 1] != TRUE && map[row_tmp - 2][col_tmp - 1] != '*') {
			chess newTmp;
			newTmp.row = row_tmp - 2;
			newTmp.col = col_tmp - 1;
			newTmp.step = step_tmp + 1;
			chesses.push(newTmp);
			visited[newTmp.row][newTmp.col] = TRUE;
		}

		if (row_tmp - 1 >= 0 && col_tmp - 2 >= 0 && visited[row_tmp - 1][col_tmp - 2] != TRUE && map[row_tmp - 1][col_tmp - 2] != '*') {
			chess newTmp;
			newTmp.row = row_tmp - 1;
			newTmp.col = col_tmp - 2;
			newTmp.step = step_tmp + 1;
			chesses.push(newTmp);
			visited[newTmp.row][newTmp.col] = TRUE;
		}

		if (row_tmp + 1<8 && col_tmp - 2 >= 0 && visited[row_tmp + 1][col_tmp - 2] != TRUE && map[row_tmp + 1][col_tmp - 2] != '*') {
			chess newTmp;
			newTmp.row = row_tmp + 1;
			newTmp.col = col_tmp - 2;
			newTmp.step = step_tmp + 1;
			chesses.push(newTmp);
			visited[newTmp.row][newTmp.col] = TRUE;
		}

		if (row_tmp + 2<8 && col_tmp - 1 >= 0 && visited[row_tmp + 2][col_tmp - 1] != TRUE && map[row_tmp + 2][col_tmp - 1] != '*') {
			chess newTmp;
			newTmp.row = row_tmp + 2;
			newTmp.col = col_tmp - 1;
			newTmp.step = step_tmp + 1;
			chesses.push(newTmp);
			visited[newTmp.row][newTmp.col] = TRUE;
		}

		if (row_tmp + 2<8 && col_tmp + 1<8 && visited[row_tmp + 2][col_tmp + 1] != TRUE && map[row_tmp + 2][col_tmp + 1] != '*') {
			chess newTmp;
			newTmp.row = row_tmp + 2;
			newTmp.col = col_tmp + 1;
			newTmp.step = step_tmp + 1;
			chesses.push(newTmp);
			visited[newTmp.row][newTmp.col] = TRUE;
		}

		if (row_tmp + 1<8 && col_tmp + 2<8 && visited[row_tmp + 1][col_tmp + 2] != TRUE && map[row_tmp + 1][col_tmp + 2] != '*') {
			chess newTmp;
			newTmp.row = row_tmp + 1;
			newTmp.col = col_tmp + 2;
			newTmp.step = step_tmp + 1;
			chesses.push(newTmp);
			visited[newTmp.row][newTmp.col] = TRUE;
		}

		if (row_tmp - 1 >= 0 && col_tmp + 2<8 && visited[row_tmp - 1][col_tmp + 2] != TRUE && map[row_tmp - 1][col_tmp + 2] != '*') {
			chess newTmp;
			newTmp.row = row_tmp - 1;
			newTmp.col = col_tmp + 2;
			newTmp.step = step_tmp + 1;
			chesses.push(newTmp);
			visited[newTmp.row][newTmp.col] = TRUE;
		}

		if (row_tmp - 2 >= 0 && col_tmp + 1<8 && visited[row_tmp - 2][col_tmp + 1] != TRUE && map[row_tmp - 2][col_tmp + 1] != '*') {
			chess newTmp;
			newTmp.row = row_tmp - 2;
			newTmp.col = col_tmp + 1;
			newTmp.step = step_tmp + 1;
			chesses.push(newTmp);
			visited[newTmp.row][newTmp.col] = TRUE;
		}

	}
	return -1;
}

int main() {
	int count;
	cin >> count;
	for (int m = 0; m<count; m++) {
		TRUE++;
		chess origin;
		while (!chesses.empty()) chesses.pop();
		for (int i = 0; i<8; i++) {
			for (int j = 0; j<8; j++) {
				char tmp;
				cin >> tmp;
				if (tmp == '#') {
					origin.row = i;
					origin.col = j;
				}
				map[i][j] = tmp;
			}
		}
		origin.step = 0;
		chesses.push(origin);
		visited[origin.row][origin.col] = TRUE;
		int result = BFS();
		if (result == -1) {
			cout << "Case " << m + 1 << ": IMPOSSIBLE" << endl;
		}
		else {
			cout << "Case " << m + 1 << ": " << result << endl;
		}
	}
	return 0;
}