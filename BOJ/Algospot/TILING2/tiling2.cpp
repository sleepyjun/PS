#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

const int M = 1000000007;
int dp[101];
int run(int n)
{
	if(n <= 1) return 1;
	
	int& ret = dp[n];
	if(ret != -1) return ret;
	
	return ret = ((run(n-1)%M)+(run(n-2)%M)) % M;
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
		
		cout << run(n) << '\n';
	}
}