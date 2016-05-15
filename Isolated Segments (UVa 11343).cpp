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
#include <cstdio>  
#include <cstring> 
#include <cmath>  
using namespace std;
struct Point {
	double x, y;
};
struct Seg {
	Point from, to;
}segs[1010];
bool abetween(double a, double b, double c) {
	return c >= a && c <= b;
}
bool same(Seg a, Point c) {
	double min_x, max_x, min_y, max_y;
	min_y = min(a.from.y, a.to.y);
	max_y = max(a.from.y, a.to.y);
	min_x = min(a.from.x, a.to.x);
	max_x = max(a.from.x, a.to.x);
	double tmpa, tmpb;
	tmpa = (a.from.y - a.to.y)*(c.x - a.from.x);
	tmpb = (a.from.x - a.to.x)*(c.y - a.from.y);
	if (abetween(min_x, max_x, c.x) && abetween(min_y, max_y, c.y) && (tmpa == tmpb))
		return true;
	return false;
}
double test(Point &o, Point &a, Point &b) {
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
bool intersection(Seg a, Seg b) {
	if (test(a.from, a.to, b.from)*test(a.from, a.to, b.to) < 0 && test(a.to, a.from, b.from)*test(a.to, a.from, b.to) < 0 && test(b.from, b.to, a.from)*test(b.from, b.to, a.to) < 0 && test(b.to, b.from, a.from)*test(b.to, b.from, a.to) < 0)
		return true;
	if (same(a, b.from) || same(a, b.to) || same(b, a.from) || same(b, a.to))
		return true;
	return false;
}
int main() {
	int N, M;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &M);
		for (int i = 0; i < M;i++)
			scanf("%lf%lf%lf%lf", &segs[i].from.x, &segs[i].from.y, &segs[i].to.x, &segs[i].to.y);
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			bool isIso = true;
			for (int j = 0; j < M; j++) {
				if (i == j)
					continue;
				if (intersection(segs[i], segs[j])) {
					isIso = false;
					break;
				}
			}
			if (isIso)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}