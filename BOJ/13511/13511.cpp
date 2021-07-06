// https://www.acmicpc.net/problem/13511
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 17;
int parent[100001][MAX];
int depth[100001];
std::vector<pii> adj[100001];
long long cost[100001];

void make(int curr, long long w = 0)
{
	cost[curr] = w;
	for(const auto& next: adj[curr])
	{
		int nNode = next.first;
		int nCost = next.second;
		if(depth[nNode] == -1)
		{
			parent[nNode][0] = curr;
			depth[nNode] = depth[curr] + 1;
			make(nNode, w+nCost);
		}
	}
}

int getLCA(int u, int v)
{
	if(depth[u] < depth[v]) std::swap(u,v);
	int diff = depth[u] - depth[v];
	
	for(int i = 0; diff; ++i)
	{
		if(diff % 2) u = parent[u][i];
		diff /= 2;
	}
	
	if(u != v)
	{
		for(int i = MAX-1; i >= 0; --i)
		{
			if(parent[u][i] != -1 && parent[u][i] != parent[v][i])
			{
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	
	return u;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&parent[0][0], &parent[100000][MAX], -1);
	std::fill(depth, depth+100001, -1);
	int n; cin >> n;
	
	for(int i = 0; i < n-1; ++i)
	{
		int u,v,w; cin >> u >> v >> w;
		
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	depth[1] = 0;
	make(1);
	
	for(int j = 0; j < MAX-1; ++j)
		for(int i = 1; i <= n; ++i)
			if(parent[i][j] != -1)
				parent[i][j+1] = parent[parent[i][j]][j];
	
	int t; cin >> t;
	while(t--)
	{
		int q; cin >> q;
		int u,v; cin >> u >> v;
		int lca = getLCA(u,v);
		
		if(q == 1)
		{
			cout << cost[u] + cost[v] - cost[lca]*2 << '\n';
		}
		else if(q == 2)
		{
			int x; cin >> x; x--;
			if(depth[u] - depth[lca] >= x)
			//subtree left or middle
			{
				int diff = x;
				for(int i = 0; diff; ++i)
				{
					if(diff % 2) u = parent[u][i];
					diff /= 2;
				}
				
				cout << u << '\n';
			}
			else
			//subtree right
			{
				int diff = x - (depth[u] - depth[lca]);
				diff = (depth[v] - depth[lca]) - diff;
				for(int i = 0; diff; ++i)
				{
					if(diff % 2) v = parent[v][i];
					diff /= 2;
				}
				
				cout << v << '\n';
			}
		}
	}
}//g++ -o a -std=c++17 *.cpp