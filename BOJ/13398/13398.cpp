// https://www.acmicpc.net/problem/13398
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::min();

int dp[100001][2];
int arr[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	
	std::fill(&dp[0][0], &dp[100000][2], INF);
	int res = dp[1][0] = dp[1][1] = arr[1];
	for(int i = 2; i <= n; ++i)
	{
		dp[i][0] = std::max(dp[i-1][0]+arr[i], arr[i]);
		dp[i][1] = std::max(dp[i-1][1]+arr[i], dp[i-1][0]);

		res = std::max(res, std::max(dp[i][0], dp[i][1]));
	}

	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp