#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int set[510], sum[510];
int myRank[510];

struct Edge
{
	int from, to;
	long length;
	Edge() {}
	Edge(int from, int to, long length) {
		this->from = from;
		this->to = to;
		this->length = length;
	}
	bool operator < (const Edge& c) const {
		return length > c.length;
	}

}edges[1000100];

int myFind(int x) {
	if (x != set[x]) {
		set[x] = myFind(set[x]);
		return set[x];
	}
	else
		return set[x];
}

void link(int x, int y) {
	if (myRank[x] > myRank[y]) {
		set[y] = x;
	}
	else {
		set[x] = y;
		if (myRank[x] == myRank[y])
			myRank[y]++;
	}
}
void merge(int x, int y) {
	link(myFind(x), myFind(y));
}


int main() {
	int n, numOfRoutes;
	cin >> n >> numOfRoutes;

	while (n != 0) {
		int tmp_i, tmp_j;
		long len;
		for (int i = 1; i<n + 1; i++) {
			set[i] = i;
			myRank[i] = 0;
		}

		for (int i = 0; i<numOfRoutes; i++) {
			scanf("%d %d %ld", &tmp_i, &tmp_j, &len);

			Edge edge_tmp(tmp_i, tmp_j, len);
			edges[i] = edge_tmp;
		}
		sort(edges, edges + numOfRoutes);
		memset(sum, 0, sizeof(sum));
		long longest = 0;
		longest = edges[0].length;
		for (int i = 0; i<numOfRoutes; i++) {
			if (edges[i].length<longest)
				break;

			int setA = myFind(edges[i].from);
			int setB = myFind(edges[i].to);

			if (setA != setB) {
				merge(edges[i].from, edges[i].to);
			}
		}



		for (int i = 1; i<n + 1; i++) {
			sum[myFind(i)]++;
		}

		int cnt = 0;
		for (int i = 1; i<n + 1; i++) {
			cnt = max(cnt, sum[i]);
		}
		cout << cnt << endl;
		cin >> n >> numOfRoutes;
	}
	return 0;
}