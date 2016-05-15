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
#include <cmath>
#include <cstdio>
using namespace std;

long long diffmn, b, diffxy, k, s;

long long exgcd(long long diffmn, long long b, long long &x0, long long &y0) {
	long long r, tmp;
	if (b == 0) {
		x0 = 1;
		y0 = 0;
		return diffmn;
	}
	else {
		r = exgcd(b, diffmn%b, x0, y0);
		tmp = x0;
		x0 = y0;
		y0 = tmp - (diffmn / b)*y0;
		return r;
	}
	
}
int main() {
	long long x, y, m, n, l;
	while (scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l) != EOF) {
		diffmn = n - m;
		diffxy = x - y;
		long long ta, tb;
		long long r = exgcd(diffmn, l, ta, tb);
		if (diffxy%r != 0) 
			cout << "Impossible" << endl;
		else {
			diffmn /= r;
			diffxy /= r;
			l /= r;
			exgcd(diffmn, l, s, k);
			s *=diffxy;
			k *=diffxy;
			s = s - s / l * l;
			if (s < 0) {
				if (l <= 0)
					s -= l;
				else
					s += l;
			}
			cout << s << endl;;
		}
		

	}
}