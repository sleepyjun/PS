// https://www.acmicpc.net/problem/2213
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int weight[10001];
std::vector<int> adj[10001];
int dp[10001][2];

std::vector<int> path;
bool visited[10001];

int func(int curr, int prev, bool select)
{
	int &ret = dp[curr][select];
	if(ret != -1) return ret;

	if(true == select)
	{
		ret = weight[curr];
		for(int next: adj[curr])
		{
			if(next != prev)
				ret += func(next, curr, false);
		}
	}
	else
	{
		ret = 0;
		for(int next: adj[curr])
		{
			if(next != prev)
				ret += std::max(func(next, curr, true),	func(next, curr, false));
		}
	}

	return ret;
}

void find(int curr, int prev)
{
	if(dp[curr][true] > dp[curr][false] && visited[prev] == false)
	{
		path.push_back(curr);
		visited[curr] = true;
	}
	for(int next: adj[curr])
	{
		if(next != prev)
			find(next,curr);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> weight[i];
	for(int i = 1; i < n; ++i)
	{
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	std::fill(&dp[0][0], &dp[10000][2], -1);

	int res = std::max(func(1,-1,true), func(1,-1,false));

	cout << res << '\n';

	find(1,0);
	std::sort(path.begin(), path.end());
	for(int n: path)
		cout << n << ' ';
	cout << '\n';
}//g++ -o a -std=c++11 *.cpp