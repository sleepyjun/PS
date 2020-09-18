// https://www.acmicpc.net/problem/1102
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int costs[18][18];
int dp[1<<18];
int n;
int res = INF;

int func(int src, int count)
{
	if(count <= 0) return 0;
	
	int& ret = dp[src];
	
	if(ret != INF) return ret;
	
	for(int i = 0; i < n; ++i)
	{
		if(src & (1<<i)) //i번째 on
		{
			for(int j = 0; j < n; ++j)
			{
				if(i == j || (src&(1<<j))) continue;
				ret = std::min(ret, func( (src|(1<<j)), count-1) + costs[i][j]);
			}
		}
	}
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int src=0,least; cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> costs[i][j];
	std::fill(dp,(dp+(1<<16)),INF);
	
	std::string str; cin >> str;
	int cnt = 0;
	for(int i = 0; i < str.length(); ++i)
	{
		if(str[i] == 'Y')
		{
			cnt++;
			src |= (1<<i);
		}
	}
	cin >> least;
	
	int res = func(src, least-cnt);
	cout << (res == INF ? -1 : res) << '\n';
}