#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];


int func(int n)
{
	if(dp[n] != -1) return dp[n];
	
	int res = arr[n];
	
	for(int i = 1; i <= n/2; ++i)
		res = max(res, func(n-i) + func(i));
	
	dp[n] = res;
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	fill(dp, dp+1001, -1);
	
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];	

	cout << func(n) << '\n';
}