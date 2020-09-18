#include <iostream>
#include <algorithm>
#include <limits>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[2001];
bool dp[2001][2001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		dp[i][i] = true;
	}
	
	for(int i = 1; i < n; ++i)
	{
		if(arr[i] == arr[i+1])
			dp[i][i+1] = true;
	}
	
	cin >> m;
	
	for(int len = 3; len <= n; ++len)
	{
		for(int i = 1; i <= n-len+1; ++i)
		{
			if(arr[i] == arr[i+len-1] & dp[i+1][i+len-2] == true)
				dp[i][i+len-1] = true;
		}
	}
	while(m--)
	{
		int s, e; cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
}