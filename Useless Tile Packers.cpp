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
#define MAXIMUM 110
#define eps 1e-10
int T;
int dcmp(double x){
	if (fabs(x) >= eps)
		return x >= 0 ? 1 : -1;
	else
		return 0;
}
struct Cor{
	double x, y;
	Cor() {}
	Cor(double x, double y) :x(x), y(y) {}
	bool operator<(const Cor& rhs)const {
		return dcmp(x - rhs.x)<0 || (dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y)<0);
	}
	bool operator==(const Cor& rhs)const{
		return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
	}
};
typedef Cor V;
V operator-(Cor p1, Cor p2){
	return V(p1.x - p2.x, p1.y - p2.y);
}
double Cross(V v1, V v2){
	return v1.x*v2.y - v1.y*v2.x;
}
Cor p[MAXIMUM], ch[MAXIMUM];
double PA(Cor *p, int n){
	double area = 0.0;
	for (int i = 1; i<=n - 2; i++)
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	return fabs(area) / 2;
}
bool test(int m, int i) {
	return Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0;
}
int tile(Cor *p, Cor *t){
	sort(p, p + T);
	T = unique(p, p + T) - p;
	int m = 0;
	for (int i = 0; i<=T-1; i++){
		while (m>1 && test(m,i)) 
			m--;
		t[m++] = p[i];
	}
	int k = m;
	for (int i = T - 2; i >= 0; i--){
		while (m>k && test(m, i))
			m--;
		t[m++] = p[i];
	}
	if (T>1) 
		m--;
	return m;
}

int main(){
	int cnt = 0;
	while (scanf("%d", &T) !=EOF && T){
		printf("Tile #%d\n", ++cnt);
		double area1, area2;
		for (int i = 0; i < T; i++) {
			double tmpa, tmpb;
			scanf("%lf%lf", &tmpa, &tmpb);
			p[i].x = tmpa;
			p[i].y = tmpb;
		}
		area1 = PA(p, T);
		int m = tile(p, ch);
		area2 = PA(ch, m);
		printf("Wasted Space = %.2lf %%\n\n", (area2 - area1)*100.0 / area2);
	}
	return 0;
}