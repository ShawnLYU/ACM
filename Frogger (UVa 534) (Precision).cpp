#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int set[200];
int myRank[200];
struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
}points[200];

struct Edge
{
	int from, to;
	double length;
	Edge() {}
	Edge(int from, int to) {
		this->from = from;
		this->to = to;
	}

}edges[200 * 200];

double dist(Point a, Point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int myFind(int x) {
	if (x != set[x]){
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
	int n, rounds = 0;
	cin >> n;
	while (n != 0) {
		int tmp_i, tmp_j, countOnEdges = 0;
		rounds++;
		for (int i = 0; i<n; i++) {
			scanf("%d %d", &tmp_i, &tmp_j);
			Point p_tmp(tmp_i, tmp_j);
			points[i] = p_tmp;
			set[i] = i;
			myRank[i] = 1;
			for (int j = 0; j<i; j++) {
				Edge edge_tmp(i, j);
				edge_tmp.length = dist(points[i], points[j]);
				edges[countOnEdges++] = edge_tmp;
			}
		}
		qsort(edges, countOnEdges, sizeof *edges, [](const void* a, const void* b)
		{
			Edge *A = (Edge*)a;
			Edge *B = (Edge*)b;
			int a_length = A->length;
			int b_length = B->length;
			return  a_length - b_length;
		});

		for (int i = 0; i<countOnEdges; i++) {
			int setA = myFind(edges[i].from);
			int setB = myFind(edges[i].to);

			if (setA != setB)
				merge(edges[i].from, edges[i].to);
			if (myFind(0) == myFind(1)) {
				printf("Scenario #%d\n", rounds);
				printf("Frog Distance = %.3lf\n\n", edges[i].length);
				break;
			}
		}
		cin >> n;
	}
	return 0;
}