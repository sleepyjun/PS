#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int dp[501];
int arr[501];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(arr, arr+501, -1);
	int n; cin >> n;
	int res = -1;
	for(int i = 1; i <= n; ++i)
	{
		int x,y; cin >> x >> y;
		arr[x] = y;
	}
	
	for(int i = 1; i <= 500; ++i)
	{
		if(arr[i] == -1) continue;
		dp[i] = 1;
		for(int j = 1; j < i; ++j)
		{
			if(arr[j] == -1) continue;
			if(arr[i] > arr[j])
			{
				dp[i] = std::max(dp[i], dp[j]+1);
			}
		}
		res = std::max(res, dp[i]);
	}
	cout << n-res << '\n';
}