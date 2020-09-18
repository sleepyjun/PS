#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string a, b;
	cin >> a >> b;
	
	const int al = a.length();
	const int bl = b.length();
	
	for(int i = 1; i <= al; ++i)
		dp[i][0] = i;
	for(int j = 1; j <= bl; ++j)
		dp[0][j] = j;
	
	for(int i = 1; i <= al; ++i)
	{
		for(int j = 1; j <= bl; ++j)
		{
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min(dp[i-1][j-1],
							   min(dp[i-1][j], dp[i][j-1]))+1;
		}
	}
	
	cout << dp[al][bl] << endl;
}