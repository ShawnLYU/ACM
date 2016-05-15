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
#define MAX_EDGE 500000
#define MAX_NODE 500000
#define INF 0X3f3f3f3f3f3f3f3f
int visited[MAX_NODE];
int sum, maxProfit;
typedef struct {
	int v;     // edge (u->v)
	long long cap;  // edge capacity (w)
	int nxt;  // the next edge connected by node u.
}EDGE;
int head[MAX_EDGE]; // the first edge connected by node u.
int totaledge; // the total number of edges
EDGE edge[MAX_NODE];
int d[MAX_NODE];
int f[MAX_EDGE];

void add_edge(int u, int v, long long cap) {
	edge[totaledge].nxt = head[u];
	edge[totaledge].v = v;
	edge[totaledge].cap = cap;
	head[u] = totaledge;
	totaledge++;
}
void cleargraph() {
	totaledge = 0;
	memset(head, -1, sizeof(head));
}
void dfs(int u) {
	visited[u] = 1;
	int v;
	for (int e = head[u]; e != -1; e = edge[e].nxt) {
		v = edge[e].v;
		if (edge[e].cap - f[e]>0 && !visited[v])
			dfs(v);
	}
}

long long dinic(int u, int T, long long Sum) {
	if (u == T) 
		return Sum;
	int v, tp = Sum;
	for (int e = head[u]; e != -1 && Sum; e = edge[e].nxt) {
		v = edge[e].v;
		// find augmenting path by d[]
		if (d[v] == d[u] + 1 && edge[e].cap>f[e]) {
			long long canflow = dinic(v, T, min(Sum, edge[e].cap - f[e]));
			f[e] += canflow;
			f[e ^ 1] -= canflow;
			Sum -= canflow;
			// do not break, because may find more than 1 path
		}
	}
	return tp - Sum;
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
long long maxFlow(int S, int T) {
	long long ans = 0;
	while (bfs(S, T))
		ans += dinic(S, T, INF);
	return ans;
}
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m)!=EOF) {
		int cnt = 0;
		int i, j, a, b, c;
		sum = 0;
		maxProfit = 0;
		memset(f, 0, sizeof(f));
		
		memset(visited, 0, sizeof(visited));
		cleargraph();
		int start = 2 * n, end = 2 * n + 1;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &c);
			if (c > 0) {
				add_edge(i, start, 0);
				add_edge(start, i, c);
				sum += c;
			}
			else if(c<0){
				add_edge(i, end, -c);
				add_edge(end, i, 0);
			}
			
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);
			add_edge(a - 1, b - 1, INF);
			add_edge(b - 1, a - 1, 0);
		}
		long long flow = maxFlow(start, end);
		maxProfit = sum - flow;
		dfs(start);
		for (int i = 0; i < n; i++)
			if (visited[i] == 1) {
				cnt++;
			}
		printf("%d %ld\n", cnt, maxProfit);
	}

	return 0;
}