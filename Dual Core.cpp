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

typedef struct {
	int v;     // edge (u->v)
	int cap;  // edge capacity (w)
	int nxt;  // the next edge connected by node u.
}EDGE;
int head[MAX_EDGE]; // the first edge connected by node u.
int totaledge; // the total number of edges
EDGE edge[MAX_NODE];
int d[MAX_NODE];
int f[MAX_EDGE];
void cleargraph() {
	totaledge = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int cap) {
	edge[totaledge].v = v;
	edge[totaledge].cap = cap;
	edge[totaledge].nxt = head[u];
	head[u] = totaledge;
	totaledge++;
}
bool bfs(int S, int T) {
	int u, v;
	memset(d, -1, sizeof(d));
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
	if (u == T) return Sum;
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
	int N, M;
	while (scanf("%d%d", &N, &M)!=EOF) {
		int i, j, a, b, c;
		memset(f, 0, sizeof(f));
		cleargraph();
		int start = 2 * N, end = 2 * N + 1;
		for (i = 0; i < N; i++)
		{
			scanf("%d%d", &a, &b);
			add_edge(start, i, a);
			add_edge(i, start, 0);
			add_edge(i, end, b);
			add_edge(end, i, 0);
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			add_edge(a-1, b-1, c);
			add_edge(b-1, a-1, c);
		}
		int flow = maxFlow(start, end);
		printf("%d\n", flow);
	}

	return 0;
}