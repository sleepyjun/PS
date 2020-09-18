#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 99999999;
int coin[101];
int dp[101][10001];
int n, k;

int func(int _n, int _k)
{
	if(dp[_n][_k] != -1) return dp[_n][_k];
	if(n == _n) return (_k == 0 ? 0 : INF);
	
	int res = func(_n+1, _k);
	if(_k >= coin[_n]) res = min(res, func(_n, _k-coin[_n])+1);
	dp[_n][_k] = res;
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> n >> k;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= k; ++j)
			dp[i][j] = -1;
	
	for(int i = 0 ; i < n; ++i)
		cin >> coin[i];
	
	int res = func(0,k);
	
	if(res == INF) cout << "-1\n";
	else cout << res << '\n';
}