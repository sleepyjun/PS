// https://www.acmicpc.net/problem/17626
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	int dp[50001];
	int power[225];
	for(int i = 0; i < 225; ++i) power[i] = i*i;
	dp[0]=0;
	dp[1]=1;
	for(int i = 2; i <= n; ++i)
	{
		int cnt = INF;
		for(int j = 1; power[j] <= i; ++j)
			cnt = std::min(cnt, dp[i-power[j]]);
		dp[i] = cnt+1;
	}
	cout << dp[n] << '\n';
}//g++ -o a -std=c++11 *.cpp