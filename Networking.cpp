#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int set[60];
int myRank[60];

struct Edge
{
	int from, to;
	int length;
	Edge() {}
	Edge(int from, int to, int length) {
		this->from = from;
		this->to = to;
		this->length = length;
	}
	bool operator < (const Edge& c) const {
		return length < c.length;
	}

};

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
	cin >> n;

	while (n != 0) {
		Edge edges[60 * 60];
		cin >> numOfRoutes;
		int tmp_i, tmp_j, tmpEdges = 0;
		for (int i = 1; i<=n; i++) {
			set[i] = i;
			myRank[i] = 1;
		}
		for (int i = 0; i<numOfRoutes; i++) {
			scanf("%d%d%d", &tmp_i, &tmp_j, &tmpEdges);
			Edge edge_tmp(tmp_i, tmp_j, tmpEdges);
			edges[i] = edge_tmp;
		}
		sort(edges, edges + numOfRoutes);
		int cnt = 0;
		for (int i = 0; i<numOfRoutes; i++) {
			int setA = myFind(edges[i].from);
			int setB = myFind(edges[i].to);

			if (setA != setB) {
				cnt += edges[i].length;
				merge(edges[i].from, edges[i].to);
			}
		}

		cout << cnt << endl;

		cin >> n;
	}
	return 0;
}