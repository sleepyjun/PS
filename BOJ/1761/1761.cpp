// https://www.acmicpc.net/problem/1761
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 16;
std::vector<pii> adj[40001];
int parent[40001][MAX];
int depth[40001];
int dist[40001];

void make(int curr)
{
	for(pii next : adj[curr])
	{
		int nextNode = next.first;
		int nextWeight = next.second;
		if(depth[nextNode] == -1)
		{
			parent[nextNode][0] = curr;
			depth[nextNode] = depth[curr]+1;
			dist[nextNode] = dist[curr] + nextWeight;
			make(nextNode);
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 1; i < n; ++i)
	{
		int u,v,w; cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	std::fill(&parent[0][0], &parent[40000][MAX], -1);
	std::fill(depth, depth+40001, -1);
	depth[1] = 0;
	make(1);
	for(int j = 0; j < MAX-1; ++j)
	{
		for(int i = 1; i <= n; ++i)
			if(parent[i][j] != -1)
				parent[i][j+1] = parent[parent[i][j]][j];
	}	

	int m; cin >> m;
	for(int i = 1; i <= m; ++i)
	{
		int u,v; cin >> u >> v;
		int a = u, b = v;
		if(depth[u] < depth[v]) std::swap(u,v);
		int diff = depth[u] - depth[v];

		for(int j = 0; diff; ++j)
		{
			if(diff % 2) u = parent[u][j];
			diff /= 2;
		}
		if(u != v)
		{
			for(int j = MAX-1; j >= 0; --j)
			{
				if(parent[u][j] != -1 && parent[u][j] != parent[v][j])
				{
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}

		int d = dist[a]+dist[b]-dist[u]*2;
		printf("%d\n", d);
	}
}//g++ -o a -std=c++11 *.cpp