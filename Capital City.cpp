#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define MAXIMUM 100
#define INFINITY 100000000

int main() {
	int n, m;
	int dist[MAXIMUM][MAXIMUM];

	while (scanf("%d %d", &n, &m) != EOF) {//n:num of cities
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = INFINITY;

		for (int i = 1; i <= n; i++)
			dist[i][i] = 0;
		for (int i = 0; i<m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			dist[u][v] = w;
			dist[v][u] = w;
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (dist[i][k] != INFINITY  && dist[k][j] != INFINITY && dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];

		int capital, min = INFINITY;
		for (int i = 1; i <= n; i++) {
			int tmp = 0;
			for (int j = 1; j <= n; j++)
				tmp += dist[i][j];
			if (tmp<min) {
				capital = i;
				min = tmp;
			}
		}

		cout << capital << endl;
	}
	return 0;
}