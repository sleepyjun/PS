// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int adj[1001][1001];

void solve(int n, int start, int end)
{
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq;
	std::vector<int> dist(n+1,INF);
	dist[start] = 0; pq.push({0,start});
	
	while(!pq.empty())
	{
		int src = pq.top().first;
		int here = pq.top().second; pq.pop();
		if(dist[here] < src) continue;
		for(int i = 1; i <= n; ++i)
		{
			if(i==here) continue;
			if(adj[here][i] != INF)
			{
				int there = i;
				int next = adj[here][i] + src;
				if(dist[there] > next)
				{
					dist[there] = next;
					pq.push({next,there});
				}
			}
		}
	}
	
	cout << dist[end] << '\n';
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&adj[0][0], &adj[1000][1001], INF);
	for(int i = 0; i <= 1000; ++i) adj[i][i] = 0;
	int n, m; cin >> n >> m;
	int s, e;
	for(int i = 0; i < m; ++i)
	{
		int s,e,v; cin >> s >> e >> v;
		adj[s][e] = std::min(adj[s][e], v);
	} cin >> s >> e;
	
	solve(n,s,e);
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;