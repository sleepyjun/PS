#include <cstdio>
#include <algorithm>

double dp[1001][2001];
int n, m;
double func(int day, int meter)
{
	if(day == m+1) return meter >= n ? 1.0 : 0;
	
	double& ret = dp[day][meter];
	if(ret != -1) return ret;
	return ret = func(day+1, meter+2)*0.75 + func(day+1, meter+1)*0.25;
}
int main()
{
	int t; scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d", &n, &m);
		std::fill(&dp[0][0], &dp[1000][2000], -1);
		printf("%.10lf\n", func(1,0));
	}
}