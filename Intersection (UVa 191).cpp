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
int n;
struct P
{
	double x, y;
	bool onLine;
	P() {}
	P(double a, double b) { 
		x = a; 
		y = b;
		onLine = false;
	}
};

bool in(P p, P a, P b)
{
	return (a.x <= p.x) && (a.y >= p.y) && (b.x >= p.x) && (b.y <= p.y);
}
struct Li
{
	double x, y, x2, y2, dx, dy;
	Li() {}
	Li(P a, P b) {
		x = a.x;
		y = a.y; 
		x2 = b.x;
		y2 = b.y;
		dx = b.x - a.x;
		dy = b.y - a.y; 
	}
};


bool test(Li a, Li b)
{
	double tmp1, tmp2, tmp3, tmp4;
	tmp1 = a.dx*(b.y - a.y) - a.dy*(b.x - a.x);
	tmp3 = b.dx*(a.y - b.y) - b.dy*(a.x - b.x);
	tmp2 = a.dx*(b.y2 - a.y) - a.dy*(b.x2 - a.x);
	tmp4 = b.dx*(a.y2 - b.y) - b.dy*(a.x2 - b.x);
	if (tmp1*tmp2 == 0 && tmp3*tmp4 == 0) {
		P A = P(a.x, a.y);
		P B = P(a.x2, a.y2);
		P C = P(b.x, b.y);
		P D = P(b.x2, b.y2);
		P E = P(min(A.x, B.x), max(A.y, B.y));
		P F = P(max(A.x, B.x), min(A.y, B.y));
		if (!in(A, C, D) && !in(B, C, D) && !in(C, E, F) && !in(D, E, F))
			return false;
		else 
			return true;
	}
	return (tmp1*tmp2 < 0) && (tmp3*tmp4 < 0);
}

int main(){
	double x1, y1, x2, y2;
	scanf("%d", &n);
	for (int i = 0; i < n;i++) {
		P  a, b, c, d;
		scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		c = P(min(x1, x2), max(y1, y2));
		d = P(max(x1, x2), min(y1, y2));
		P p1, p2, p3, p4;
		p1 = P(c.x, c.y);
		p2 = P(c.x, d.y);
		p3 = P(d.x, d.y);
		p4 = P(d.x, c.y);
		Li l = Li(a, b);
		Li l1 = Li(p1, p2);
		Li l2 = Li(p2, p3);
		Li l3 = Li(p1, p4);
		Li l4 = Li(p4, p3);
		if (in(a, p1, p3) || in(b, p1, p3) || test(l, l1) || test(l, l2) || test(l, l3) || test(l, l4))
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}
	return 0;
}