#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_EDGE 50000
#define MAX_NODE 50000
#define INF 0X3f3f3f3f

int d[MAX_NODE];
int f[MAX_EDGE];
typedef struct {
	int v;     // edge (u->v)
	int cap;  // edge capacity (w)
	int nxt;  // the next edge connected by node u.
}EDGE;
int head[MAX_EDGE]; // the first edge connected by node u.
int totaledge; // the total number of edges
EDGE edge[MAX_NODE];
void cleargraph() {
	totaledge = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int cap) {
	edge[totaledge].nxt = head[u];
	edge[totaledge].v = v;
	edge[totaledge].cap = cap;
	head[u] = totaledge;
	totaledge++;
}
bool bfs(int S, int T) {
	memset(d, -1, sizeof(d));
	int u, v;
	queue<int> Q;
	while (!Q.empty())
		Q.pop();
	Q.push(S);
	d[S] = 0;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int e = head[u]; e != -1; e = edge[e].nxt) {
			v = edge[e].v;
			// d[v]=-1,then v is not visited yet
			// and the flow did not reach the capacity
			if ((d[v] == -1) && edge[e].cap > f[e]) {
				d[v] = d[u] + 1;
				Q.push(v);
			}
		}
	}
	return d[T] >= 0;
}

int dinic(int u, int T, int Sum) {
	if (u == T)
		return Sum;
	int v, tp = Sum;
	for (int e = head[u]; e != -1 && Sum; e = edge[e].nxt) {
		v = edge[e].v;
		// find augmenting path by d[]
		if (d[v] == d[u] + 1 && edge[e].cap>f[e]) {
			int canflow = dinic(v, T, min(Sum, edge[e].cap - f[e]));
			f[e] += canflow;
			f[e ^ 1] -= canflow;
			Sum -= canflow;
			// do not break, because may find more than 1 path
		}
	}
	return tp - Sum;
}
int maxFlow(int S, int T) {
	int ans = 0;
	while (bfs(S, T))
		ans += dinic(S, T, INF);
	return ans;
}
int main() {
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) != EOF) {
		int i, j, a, b, c;
		memset(f, 0, sizeof(f));
		cleargraph();
		int start = 0, end = n + m - 1;
		for (int i = n; i <= n + m - 2; i++) {
			add_edge(end, i, 0);
			add_edge(i, end, 1);
		}
		for (int i = 1; i <= n - 1; i++) {
			add_edge(i, start, 0);
			add_edge(start, i, 1);
		}
		for (i = 0; i < k; i++){
			scanf("%d%d", &a, &b);
			if (a!=0 && b!=0) {
				add_edge(a, b + n - 1, 1);
				add_edge(b + n - 1, a, 0);
			}
		}
		printf("%d\n", maxFlow(start, end));
	}

	return 0;
}