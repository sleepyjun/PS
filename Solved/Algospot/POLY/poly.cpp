#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

const int M = 10000000;
int dp[101][101];
 
int poly(int n, int src)
{
	if(n == src) return 1;
	
	int& ret = dp[n][src];
	if(ret != -1) return ret;
	
	ret = 0;
	
	for(int i = 1; i <= n-src; ++i)
	{
		int sum = i+src-1;
		sum *= poly(n-src, i);
		sum %= M;
		ret += sum;
		ret %= M;
	}
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(&dp[0][0], &dp[100][100], -1);
		int n; cin >> n;
		int sum = 0;
		for(int i = 1; i <= n; ++i)
			sum = (sum + poly(n,i)) % M;
		cout << sum << '\n';
	}
}