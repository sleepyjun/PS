#include <iostream>
#include <algorithm>

int arr[500];
int dp[500];
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	int t; std::cin >> t;
	while(t--)
	{
		int n; std::cin >> n;
		std::fill(arr, arr+500, 0);
		std::fill(dp, dp+500, 0);
		for(int i = 0; i < n; ++i)
			std::cin>> arr[i];
		
		int res = -1;
		for(int i = 0; i < n; ++i)
		{
			dp[i] = 1;
			for(int j = 0; j < i; ++j)
			{
				if(arr[j] < arr[i])
				{
					dp[i] = std::max(dp[i], dp[j]+1);
				}
			}
			res = std::max(res, dp[i]);
		}
		
		std::cout << res << std::endl;
	}
}