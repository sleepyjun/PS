// https://www.acmicpc.net/problem/16194
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int dp[1001];
int arr[1001];

int func(int n)
{
	int &ret = dp[n];
	if(ret != -1) return ret;

	ret = arr[n];
	for(int i = 1; i <= n/2; ++i)
		ret = std::min(ret, func(n-i)+func(i));

	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(dp, dp+1001, -1);

	int n; cin >> n;
	for(int i = 1; i <= n; ++i) cin >> arr[i];
	cout << func(n) << '\n';
}//g++ -o a -std=c++17 *.cpp