#include <iostream>
#include <algorithm>
#include <limits>
#include <stack>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	int max = -1;
	int longIdx;
	
	std::vector<pii> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
		max = std::max(max, v[i].second);
	}
	std::sort(v.begin(), v.end());
	for(int i = 0; i < n; ++i)
		if(v[i].second == max)
		{ longIdx = i; break; }
	
	int res = 0;
	int idx = 0;
	
	for(int i = 1; i <= longIdx; ++i)
	{
		if(v[idx].second <= v[i].second)
		{
			res += (v[i].first - v[idx].first)*v[idx].second;
			idx = i;
		}
	}
	
	idx = n-1;
	for(int i = n-2; i >= longIdx; --i)
	{
		if(v[idx].second <= v[i].second)
		{
			res += (v[idx].first - v[i].first)*v[idx].second;
			idx = i;
		}
	}
	
	cout << res+max << '\n';
}