#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define ull unsigned long long
struct BI {
	ull h = 0;
	ull t = 0;
};// t 15자리까지

BI dp[101][101];

void BC(int n, int r)
{
	const ull limit = 10000000000000000L; //10^16
	for(int i = 0; i <= n; ++i)
		for (int j = 0; j <= min(i, r); ++j)
		{
			if (j == 0 || j == i) { dp[i][j].h = 0; dp[i][j].t = 1; }
			else
			{
				dp[i][j].h = dp[i - 1][j - 1].h + dp[i - 1][j].h;
				dp[i][j].t = dp[i - 1][j - 1].t + dp[i - 1][j].t;
				if (dp[i][j].t >= limit)
				{
					dp[i][j].h++;
					dp[i][j].t %= limit;
				}
			}
		}
	if (dp[n][r].h == 0) cout << dp[n][r].t;
	else printf("%llu%016llu", dp[n][r].h, dp[n][r].t);
}
int main()
{
	int n, r;
	cin >> n >> r;
	BC(n, r);
}