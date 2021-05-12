// https://www.acmicpc.net/problem/15988
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MOD = 1e9+9;
int dp[1000001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for(int i = 4; i <= 1000000; ++i)
	{
		dp[i] = (dp[i] + dp[i-3]) % MOD;
		dp[i] = (dp[i] + dp[i-2]) % MOD;
		dp[i] = (dp[i] + dp[i-1]) % MOD;
	}
	int t; cin >> t;
	while(t--)
	{
		int x; cin >> x;
		cout << dp[x] << '\n';
	}
}//g++ -o a -std=c++17 *.cpp