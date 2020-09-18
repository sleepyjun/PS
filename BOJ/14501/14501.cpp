#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, res = 0; cin >> n;
	std::vector<pii> v;
	int dp[16];
	std::fill(dp, dp+16, 0);
	
	for(int i = 0; i < n; ++i)
	{
		int t,p; cin >> t >> p;
		v.push_back({t,p});
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = i; j < n; ++j)
		{
			int day = v[i].first + j;
			if(day<=n)
			{
				dp[day] = std::max(dp[day], dp[i] + v[i].second);
				res = std::max(res, dp[day]);
			}
		}
	}
	
	cout << res << '\n';
}