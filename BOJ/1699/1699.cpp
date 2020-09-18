#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[100001];
int square[317];

int hap(int n)
{
	if(dp[n] != 999999) return dp[n];
	
	int x = sqrt(n);
	
	for(int i = 1; i <= x; ++i)
		dp[n] = min(dp[n], hap(n-i*i) + 1);
	
	return dp[n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill(dp, dp+100001, 999999);
	int n;
	cin >> n;
	for(int i = 1; i <= (int)sqrt(n); ++i)
	{
		square[i] = i*i;
		dp[i*i] = 1;
	}
	
	cout << hap(n) << '\n';
}