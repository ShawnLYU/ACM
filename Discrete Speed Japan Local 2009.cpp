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
#include <cfloat>
#include <limits>
#include <queue>
using namespace std;

#define MAXIMUM 40
int TRUE = 5;
const double INF = DBL_MAX * 0.5;
double dist[MAXIMUM][MAXIMUM];
double speedLimit[MAXIMUM][MAXIMUM];
int vie[MAXIMUM][MAXIMUM][MAXIMUM];
double myTime[MAXIMUM][MAXIMUM][MAXIMUM];

int n, m;
int start, goal;
struct State
{
	int u, v, c;
	double time;
	State() {}
	State(int u, int v, int c){
		this->u = u;
		this->v = v;
		this->c = c;
		time = 0;
	}
	friend bool operator< (State s1, State s2){
		return s1.time > s2.time;
	}
};
priority_queue<State> myQueue;
int main() {
	while (1){
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;
		TRUE++;
		double result = INF;
		scanf("%d %d", &start, &goal);
		memset(dist, 0, sizeof(dist));
		memset(speedLimit, 0, sizeof(speedLimit));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int v = 0; v <= 30; v++) {
					myTime[i][j][v] = INF;
				}

		for (int t = 0; t < m; t++) {
			int x, y, d, c;
			scanf("%d %d %d %d", &x, &y, &d, &c);
			dist[x][y] = d;
			dist[y][x] = d;
			speedLimit[x][y] = c;
			speedLimit[y][x] = c;
		}
		while (!myQueue.empty()) { myQueue.pop(); }
		myQueue.push(State(-1, start, 0));
		while (!myQueue.empty()){
			State currentState = myQueue.top();
			myQueue.pop();
			for (int i = 1; i <= n; i++){
				if (i != currentState.u && dist[currentState.v][i] != 0)
					for (int acceleration = 1; acceleration >= -1; --acceleration){
						State nextState(currentState.v, i, currentState.c + acceleration);
						if (nextState.c > 0 && !(nextState.c > speedLimit[nextState.u][nextState.v])){
							nextState.time = currentState.time + (double)dist[nextState.u][nextState.v] / nextState.c;
							if (myTime[nextState.u][nextState.v][nextState.c] > nextState.time){
								myTime[nextState.u][nextState.v][nextState.c] = nextState.time;
								myQueue.push(nextState);
							}
						}
					}
			}
		}
		for (int i = 1; i <= n; i++)
			result = min(result,myTime[i][goal][1]);
		if (result != INF)
			printf("%.5lf\n", result);
		else
			printf("unreachable\n");
			
	}

	return 0;
}