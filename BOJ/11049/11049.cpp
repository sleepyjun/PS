#include <iostream>
#include <limits>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int arr[501];
	int dp[501][501];
	for(int i = 0; i < n; ++i)
	{
		dp[i+1][i+1] = 0;
		cin >> arr[i] >> arr[i+1];
	}
	
	for(int dig = 1; dig <= n-1; ++dig)
	{
		for(int i = 1; i <= n-dig; ++i)
		{
			int j = i + dig;
			dp[i][j] = std::numeric_limits<int>::max();
			for(int k = i; k <= j-1; ++k)
				dp[i][j]=std::min(dp[i][j], dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
		}
	}
	
	cout << dp[1][n] << '\n';
}