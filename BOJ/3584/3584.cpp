// https://www.acmicpc.net/problem/3584
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 14;

int parent[10001][MAX];
int depth[10001];
bool isRoot[10001];
std::vector<int> adj[10001];

void make(int curr)
{
	for(int next: adj[curr])
	{
		if(depth[next] == -1)
		{
			parent[next][0] = curr;
			depth[next] = depth[curr]+1;
			make(next);
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(&parent[0][0], &parent[10000][MAX], -1);
		std::fill(isRoot, isRoot+10001, true);
		std::fill(depth, depth+10001, -1);
		for(auto &v: adj) v.clear();
		
		int n; cin >> n;
		for(int i = 0; i < n-1; ++i)
		{
			int p, c; cin >> p >> c;
			adj[p].push_back(c);
			adj[c].push_back(p);
			isRoot[c] = false;
		}
		
		int root;
		for(int i = 1; i <= n; ++i)
			if(isRoot[i] == true) root = i;
		
		depth[root] = 0;
		make(root);
		for(int j = 0; j < MAX-1; ++j)
		{
			for(int i = 0; i <= n; ++i)
			{
				if(parent[i][j] != -1)
					parent[i][j+1] = parent[parent[i][j]][j];
			}
		}
		
		
		int u, v; cin >> u >> v;
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
		
		cout << u << '\n';
	}
}//g++ -o a -std=c++17 *.cpp