#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string.h>
using namespace std;
int cost[25];
int dp[1001000] = { 0 };
int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) != EOF) {
		int cnt = 0;
		for (int i = 0; pow(M, i) <= N; i++) {
			cost[i] = pow(M, i);
			cnt++;
		}
		dp[0] = 1;//inital state
		for (int i = 0; i < cnt; i++)
			for (int j = cost[i]; j <= N; j++) {
				dp[j] = dp[j] + dp[j - cost[i]];
				dp[j] = dp[j] % 1000000007;
			}
				
		cout << dp[N] << endl;
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}