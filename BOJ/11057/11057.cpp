#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	int sum = 0;
	cin >> n;
	
	//arr[n][첫 수];
	for(int i = 0; i <= 9; ++i)
		dp[1][i] = 1;
	
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 0; j <= 9; ++j)
		{
			for(int k = j; k <= 9; ++k)
			{
				dp[i][j] = (dp[i][j] + dp[i-1][k]) % 10007;
			}
		}
	}
	
	for(int i = 0; i <= 9; ++i)
	{
		sum = (sum + dp[n][i]) % 10007;
	}
	
	cout << sum << '\n';
}