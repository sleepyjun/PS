#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 9999999;
int n;

int W[17][17] = { 0, };
int dp[17][(1 << 16)] = { 0, };
//도시넘버링: 0~16개 까지

int TSP(int cur, int visit)
{
	if (visit == (1 << n) - 1) return W[cur][0] == 0 ? MAX : W[cur][0];
	if (dp[cur][visit] != 0) return dp[cur][visit];
	
	dp[cur][visit] = MAX;
	for (int i = 0; i < n; ++i)
	{
		if ((visit & (1 << i)) != 0) continue;
		if (W[cur][i] == 0) continue;

		dp[cur][visit] = min(dp[cur][visit], TSP(i, (visit | (1 << i))) + W[cur][i]);
	}

	return dp[cur][visit];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &W[i][j]);

	printf("%d", TSP(0, 1));
	return 0;
}
