#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define MAXIMUM 110
#define lake 8
#define dry 9
#define visit 3
#define notvisited 4
int visited[MAXIMUM][MAXIMUM];
int farm[MAXIMUM][MAXIMUM];
int row, col, K;
int DFS(int r, int c){
	int num = 1;
	visited[r][c] = visit;
	if (r - 1 >= 1 && farm[r - 1][c] == lake && visited[r - 1][c] == notvisited){
		num += DFS(r - 1, c);
	}
	if (r + 1 <= row && farm[r + 1][c] == lake && visited[r + 1][c] == notvisited){
		num += DFS(r + 1, c);
	}
	if (c - 1 >= 1 && farm[r][c - 1] == lake && visited[r][c - 1] == notvisited){
		num += DFS(r, c - 1);
	}
	if (c + 1 <= col && farm[r][c + 1] == lake && visited[r][c + 1] == notvisited){
		num += DFS(r, c + 1);
	}
	return num;

}

int main(){

	while(scanf("%d %d %d",&row,&col,&K)!=EOF){
		for (int i = 1; i <= row; i++){
			for (int j = 1; j <= col; j++){
				visited[i][j] = notvisited;
				farm[i][j] = dry;
			}

		}
		for (int i = 0; i<K; i++){
			int r, c;
			scanf("%d %d", &r, &c);//1 based
			farm[r][c] = lake;
		}
		int max = 0;
		for (int i = 1; i <= row; i++){
			for (int j = 1; j <= col; j++){
				if (farm[i][j] == lake && visited[i][j] == notvisited){
					int tmp = DFS(i, j);
					if (tmp>max){
						max = tmp;
					}
				}
			}

		}

		cout << max << endl;
	}
	
	//cin >> max;
	return 0;
}