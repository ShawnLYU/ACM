#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;
#define PI acos(-1.0)
#define MAXIMUM 100010
struct Point
{
	double x, y;
	Point() {}
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Point operator - (Point aPoint) {
		return Point(x - aPoint.x, y - aPoint.y);
	}
	bool operator <(const Point &aPoint) const {
		return x != aPoint.x ? (x < aPoint.x) : (y < aPoint.y);
	}
}Points[MAXIMUM];
vector<Point> services;
double cross(Point& o, Point& a, Point& b) {
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
double dot(Point a, Point b) {
	return a.x * b.x + a.y * b.y;
}
int det(Point A, Point B) {
	return A.x*B.y - A.y*B.x;
}
int test(int m, int i) {
	return det(Points[m - 1] - Points[m - 2], services[i] - Points[m - 2]);
}
int main() {
	int p, r;
	while (scanf("%d", &p) != EOF) {
		int cnt = 0;
		services.clear();
		for (int i = 0; i < p; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			services.push_back(Point(x, y));
			//scanf("%lf %lf", &Points[i].x, &Points[i].y);
		}
		sort(services.begin(), services.end());
		for (int i = 0; i<p; i++) {
			while (!(test(cnt, i) > 0) && cnt>1 )
				cnt--;
			Points[cnt++] = services[i];
		}
		int t = cnt;
		for (int i = p - 2; i >= 0; i--) {
			while (!(test(cnt, i) > 0) && cnt>t)
				cnt--;
			Points[cnt++] = services[i];
		}
		scanf("%d", &r);
		for (int i = 0; i < r; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			Point tmp = Point(x, y);
			bool isFinished = false;
			//test whether inside or ourside
			for (int i = 0; i<cnt - 1; i++) {
				if (det(Points[i + 1] - Points[i], tmp - Points[i]) < 0) {
					cout << "outside" << endl;
					isFinished = true;
					break;
				}
			}
			if(!isFinished)
				cout << "inside" << endl;
		}
	}
	return 0;
}