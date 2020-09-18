#include <cstdio>
#include <algorithm>

int arr[51][51], adjCnt[51];
double dp[51][101];
int n, d, p;
//vilage cnt, pass days, prison
double func(int src, int days)
{
	if(days == 0) return (src == p ? 1.0 : 0.0);
	
	double& ret = dp[src][days];
	if(ret != -1.0) return ret;
	ret = 0.0;
	for(int i = 0; i < n; ++i)
	{
		if(arr[src][i] == 1)
			ret += func(i, days-1) / adjCnt[i];
	}
	return ret;
}
int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		std::fill(adjCnt, adjCnt+51, 0);
		std::fill(&arr[0][0], &arr[50][50], 0);
		std::fill(&dp[0][0], &dp[50][100], -1.0);
		scanf("%d %d %d", &n, &d, &p);
		
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				scanf("%d", &arr[i][j]);
				adjCnt[i] += arr[i][j];
			}
		
		int srcN; scanf("%d", &srcN);
		for(int i = 0; i < srcN; ++i)
		{
			int src;
			scanf("%d",&src);
			printf("%.8lf\n", func(src, d));
		}
	}
}