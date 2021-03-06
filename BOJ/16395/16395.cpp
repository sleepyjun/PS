#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int dp[31];

int c(int n, int k)
{
	for (int i = 0; i <= n; ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			if (i == j || j == 0) dp[j] = 1;
			else dp[j] = dp[j] + dp[j - 1];
		}
	}
	return dp[k];
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", c(n - 1, k - 1));
}