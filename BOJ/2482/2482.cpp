#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();
const int MOD = 1000000003;

ull dp[1001][1001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k; cin >> n >> k;
	
	for(int i = 1; i <= n; ++i)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 2; j <= k; ++j)
		{
			dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
		}
	}
	
	cout << (dp[n-3][k-1] + dp[n-1][k]) % MOD << '\n';
}
//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;