#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int set[60];
int myRank[60];
int build[60][60];
int myRemove[60][60];
int hasOld[60][60];
struct Edge_Remove
{
	int from, to;
	int cost;
	bool isAccepted = false;
	Edge_Remove() {}
	Edge_Remove(int from, int to, int cost) {
		this->from = from;
		this->to = to;
		this->cost = cost;
	}
	bool operator < (const Edge_Remove& c) const {
		return cost > c.cost;
	}

}edges_remove[60 * 60];

struct Edge_Build
{
	int from, to;
	int cost;
	bool isAccepted = false;
	Edge_Build() {}
	Edge_Build(int from, int to, int cost) {
		this->from = from;
		this->to = to;
		this->cost = cost;
	}
	bool operator < (const Edge_Build& c) const {
		return cost < c.cost;
	}

}edges_build[60 * 60];

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
	int n;
	cin >> n;
	while (n != 0) {
		for (int i = 0; i<n; i++) {
			set[i] = i;
			myRank[i] = 0;
		}
		memset(build, 0, sizeof(build));
		memset(myRemove, 0, sizeof(build));
		memset(hasOld, 0, sizeof(build));
		string line;
		getline(cin, line);
		for (int i = 0; i<n; i++) {
			getline(cin, line);
			for (int j = 0; j<n; j++) {
				if (line[j] == '1') {
					hasOld[i][j] = 1;
				}
			}
		}
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				cin >> build[i][j];
			}
		}
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) 
				scanf("%d", &myRemove[i][j]);
			
		}
		int numOfEdges_build = 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<i; j++) {
				Edge_Build edge_tmp(i, j, build[i][j]);
				edges_build[numOfEdges_build++] = edge_tmp;
			}
		}
		sort(edges_build, edges_build + numOfEdges_build);

		int numOfEdges_remove = 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (hasOld[i][j] != 0) {
					Edge_Remove edge_tmp(i, j, myRemove[i][j]);
					edges_remove[numOfEdges_remove++] = edge_tmp;
				}
			}
		}
		sort(edges_remove, edges_remove + numOfEdges_remove);


		for (int i = 0; i<numOfEdges_remove; i++) {
			int setA = myFind(edges_remove[i].from);
			int setB = myFind(edges_remove[i].to);

			if (setA != setB) {
				edges_remove[i].isAccepted = true;
				merge(setA, setB);
			}
		}
		for (int i = 0; i<numOfEdges_build; i++) {
			int setA = myFind(edges_build[i].from);
			int setB = myFind(edges_build[i].to);

			if (setA != setB) {
				edges_build[i].isAccepted = true;
				merge(setA, setB);
			}
		}


		int sum = 0;
		for (int i = 0; i<numOfEdges_remove; i++) {
			if (!edges_remove[i].isAccepted)
				sum += edges_remove[i].cost;
		}
		for (int i = 0; i<numOfEdges_build; i++) {
			if (edges_build[i].isAccepted) {
				sum += edges_build[i].cost;
			}
		}
		cout << sum << endl;
		cin >> n;
	}
	return 0;
}