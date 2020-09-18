#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	int res = -1;
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	
	for(int i = 1; i <= n; ++i)
	{
		dp[i] = 1;
		for(int j = 1; j < i; ++j)
			if(arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j]+1);
		
		res = max(res, dp[i]);
	}
	
	cout << res << endl;
}