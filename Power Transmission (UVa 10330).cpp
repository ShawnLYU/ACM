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
#define MAXI 50000
#define INF 0X3f3f3f3f

typedef struct {
	int v;     // edge (u->v)
	int cap;  // edge capacity (w)
	int nxt;  // the next edge connected by node u.
}EDGE;
int head[MAXI]; // the first edge connected by node u.
int totaledge; // the total number of edges
EDGE edge[MAXI];
int d[MAXI];
int f[MAXI];
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
	int N;
	while (scanf("%d", &N) != EOF)
	{
		memset(f, 0, sizeof(f));
		cleargraph();
		int tmp;
		for (int i = 0; i<N; i++)
		{
			cin >> tmp;
			add_edge(i, i + N, tmp);
			add_edge(i + N, i, 0);
		}
		int M;
		cin >> M;
		for (int i = 0; i<M; i++)
		{
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			add_edge(v - 1, u + N - 1, 0);
			add_edge(u + N - 1, v - 1, c);
		}

		int B, D;
		cin >> B >> D;
		for (int i = 0; i<B; i++) {
			int flowin;
			cin >> flowin;
			add_edge(flowin - 1, 2 * N, 0);
			add_edge(2 * N, flowin - 1, INF);
		}
		for (int i = 0; i<D; i++) {
			int flowout;
			cin >> flowout;
			add_edge(2 * N + 1, flowout + N - 1, 0);
			add_edge(flowout + N - 1, 2 * N + 1, INF);
		}

		int result;
		result = maxFlow(2 * N, 2 * N + 1);

		cout << result << endl;

	}

	return 0;
}