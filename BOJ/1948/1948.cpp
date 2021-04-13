// https://www.acmicpc.net/problem/1948
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<pii> adj[10001];
int time[10001];
bool visited[10001][10001];
int s, e, max=-1;

int dfs(int curr)
{
	if(curr == e) return 0;

	int &ret = time[curr];
	if(ret != -1) return ret;
	
	ret = 0;
	for(const auto &n: adj[curr])
	{
		int next = n.first;
		ret = std::max(ret, dfs(next)+n.second);
	}

	return ret;
}
int _dfs(int curr, int cost=0)
{
	int ret = 0;

	if(cost + time[curr] == max) ret += 1;
	else return 0;

	for(const auto &n: adj[curr])
	{
		int next = n.first;
		if(false == visited[curr][next])
		{
			visited[curr][next] = true;
			ret += _dfs(next, cost+n.second);
		}
	}

	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(time, time+10001, -1);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int u,v,w; cin >> u >> v >> w;
		adj[u].push_back({v,w});
	}
	cin >> s >> e;

	max = dfs(s);
	cout << max << '\n';
	time[e] = 0;

	int res = _dfs(s);
	cout << res-1 << '\n';
}//g++ -o a -std=c++11 *.cpp