// https://www.acmicpc.net/problem/11404
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const long long INF = std::numeric_limits<long long>::max();

ull dp[101][101];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&dp[0][0], &dp[100][101], INF);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		dp[i][i] = 0;
	for(int i = 0; i < m; ++i)
	{
		int a,b,c; cin >> a >> b >> c;
		if(dp[a][b] > c)
			dp[a][b] = c;
	}
	
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(dp[i][j] > dp[i][k]+dp[k][j])
					dp[i][j] = dp[i][k]+dp[k][j];
			}
		}
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			cout << (dp[i][j] == INF ? 0 : dp[i][j]) << ' ';
		cout << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;