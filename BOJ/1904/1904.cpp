#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

const int MOD = 15746;
int dp[1000001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	dp[0] = 0; dp[1] = 1; dp[2] = 2;
	for(int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i-1]+ dp[i-2])%MOD;
	}
	
	cout << dp[n] << '\n';
}