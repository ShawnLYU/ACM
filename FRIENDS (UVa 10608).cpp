#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int set[30010], sum[30010];
int myRank[30010];


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
	int n, numOfCitizens, numOfRoutes;
	cin >> n;

	while (n!=0) {
		n--;
		cin >> numOfCitizens >> numOfRoutes;
		int tmp_i, tmp_j;
		for (int i = 1; i<numOfCitizens + 1; i++) {
			set[i] = i;
			myRank[i] = 0;
		}

		for (int i = 0; i<numOfRoutes; i++) {
			scanf("%d %d", &tmp_i, &tmp_j);
			int setA = myFind(tmp_i);
			int setB = myFind(tmp_j);

			if (setA != setB) {
				merge(tmp_i, tmp_j);
			}
		}
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i<numOfCitizens + 1; i++) {
			sum[myFind(i)]++;
		}

		int cnt = 0;
		for (int i = 1; i<numOfCitizens + 1; i++) {
			cnt = max(cnt, sum[i]);
		}
		cout << cnt << endl;
	}
	return 0;
}