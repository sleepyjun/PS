#include <iostream>
#include <algorithm>
using namespace std;

int arr[2][100001];
int dp[2][100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		// 0 is first line, 1 is second line
		int n;
		int res = 0;
		cin >> n;
		
		for(int i = 0; i < 2; ++i)
			for(int j = 1; j <= n; ++j)
				cin >> arr[i][j];
	
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		
		for(int j = 2; j <= n; ++j)
		{
			for(int i = 0; i < 2; ++i)
			{
				dp[i][j] = arr[i][j]+ max(dp[(i+1)%2][j-1],
							  max(dp[0][j-2], dp[1][j-2]));
				
				res = res < dp[i][j] ? dp[i][j] : res;
			}
		}
		cout << res << '\n';
		
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j <= n; ++j)
			{ dp[i][j] = 0; arr[i][j] = 0; }
	}
}