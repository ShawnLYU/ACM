#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
int TRUE = 0;
int visited[35][35][35][35];
int volume[4];

int a, b, c, d, T;
struct state
{
	int cups[4];
	int step;
};
queue<state> states;
void fulfill_empty(state newTmp, int pos, int target) {
	newTmp.cups[pos] = target;
	newTmp.step++;
	if (visited[newTmp.cups[0]][newTmp.cups[1]][newTmp.cups[2]][newTmp.cups[3]] != TRUE){
		visited[newTmp.cups[0]][newTmp.cups[1]][newTmp.cups[2]][newTmp.cups[3]] = TRUE;
		states.push(newTmp);
	}
	
}
void pourToEachOther(state newTmp, int posFrom, int posTo) {
	if (newTmp.cups[posFrom] + newTmp.cups[posTo] <= volume[posTo]) {
		newTmp.cups[posTo] += newTmp.cups[posFrom];
		newTmp.cups[posFrom] = 0;
	}
	else {
		int diff = volume[posTo] - newTmp.cups[posTo];
		newTmp.cups[posTo] += diff;
		newTmp.cups[posFrom] -= diff;
	}
	newTmp.step++;
	if (visited[newTmp.cups[0]][newTmp.cups[1]][newTmp.cups[2]][newTmp.cups[3]] != TRUE){
		visited[newTmp.cups[0]][newTmp.cups[1]][newTmp.cups[2]][newTmp.cups[3]] = TRUE;
		states.push(newTmp);
	}
}
int BFS() {
	while (!states.empty()) {
		state t = states.front();
		states.pop();
			
		if (t.cups[0] == T || t.cups[1] == T || t.cups[2] == T || t.cups[3] == T)
			return t.step;
		//fulfill && empty
		for (int i = 0; i<4; i++) {
			fulfill_empty(t, i, volume[i]);
			fulfill_empty(t, i, 0);
		}
		//pour to each other
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				if (i != j)
					pourToEachOther(t, i, j);
			}
		}

	}
	return -1;
}

int main() {
	int result;
	//string input;
	string tmp;
	while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &T) != EOF) {
		//stringstream myStream(input);
		//myStream >> a >> b >> c >> d >> T;
		getline(cin, tmp);
		TRUE++;
		volume[0] = a;
		volume[1] = b;
		volume[2] = c;
		volume[3] = d;
		while (!states.empty()) states.pop();
		state tmp;
		tmp.cups[0] = 0;
		tmp.cups[1] = 0;
		tmp.cups[2] = 0;
		tmp.cups[3] = 0;
		tmp.step = 0;
		states.push(tmp);
		visited[tmp.cups[0]][tmp.cups[1]][tmp.cups[2]][tmp.cups[3]] = TRUE;
		if (a<T && b<T && c<T && d<T)
			cout << -1 << endl;
		else {
			result = BFS();
			cout << result << endl;
		}
	}
	return 0;
}