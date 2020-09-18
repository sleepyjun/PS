#include <iostream>
#include <algorithm>
#include <limits>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();;

pii info[101];
int dp[10001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	int sum = 0;
	for(int i = 0; i < n; ++i)
		cin >> info[i].first;
	for(int i = 0; i < n; ++i)
	{
		cin >> info[i].second;
		sum += info[i].second;
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = sum; j >= info[i].second; --j)
		{
			dp[j] = std::max(dp[j], dp[j-info[i].second]+info[i].first);
		}
	}
	
	int res;
	
	for(int i = 0; i <= sum; ++i)
		if(dp[i] >= m)
		{
			res = i;
			break;
		}
	
	cout << res << '\n';
}