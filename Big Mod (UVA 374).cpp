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
using namespace std;
long long B, P, M, ans;
long long bigMod(long long b, long long p){
	if (p == 0){
		return 1;
	}
	else if ((p % 2) == 1){
		long long tmp = bigMod(b, p / 2);
		return ((tmp*tmp*b) % M);
	}
	else{
		long long tmp = bigMod(b, p / 2);
		return ((tmp*tmp) % M);
	}
	
}
int main(){
	while (cin >> B >> P >> M){
		if (P == 0)
			ans = 1;
		else if (P != 0 && B == 0)
			ans = 0;
		else if (M == 1)
			ans = 0;
		else
			ans = bigMod(B, P) % M;
		cout << ans << endl;
	}
	return 0;
}