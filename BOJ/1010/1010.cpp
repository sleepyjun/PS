#include<cstdio>
int dp[31][31];

int c(int n, int m)
{
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= m; ++j)
		{
			if(i == j || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
	return dp[n][m];
}
int main()
{
	int t;
	int n,m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n", c(m,n));
	}
}