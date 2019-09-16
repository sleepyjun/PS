#include <iostream>
#include <algorithm>
using std::cin; using std::cout;
const int M = 1000000007;

int dp[101];
int tiling(int n)
{
	if(n <= 1) return 1;

	int& ret = dp[n];
	if(ret != -1) return ret;
	return ret = (tiling(n-1) + tiling(n-2))%M;
}
int func(int n)
{
	if(n%2 == 1)
		return ((tiling(n) - tiling(n/2) + M)%M);
	int res = tiling(n);
	res = (res - tiling(n/2) + M)%M;
	res = (res - tiling(n/2-1) + M)%M;
	return res;

}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--)
	{
		std::fill(dp, dp+101, -1);
		int n; cin >> n;
		cout << func(n) << '\n';
	}
}
