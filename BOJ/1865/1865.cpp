// https://www.acmicpc.net/problem/1865
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = 30000000;

int dist[501];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::vector<pii> adj[501];
		int n,m,w; cin >> n >> m >> w;
		std::fill(dist,dist+501,INF);
		dist[1] = 0;

		for(int i = 0; i < m; ++i)
		//input edge info
		{
			int s,e,t; cin >> s >> e >> t;
			adj[s].push_back({e,t});
			adj[e].push_back({s,t});
		}
		for(int i = 0; i < w; ++i)
		//input wormhole info
		{
			int s,e,t; cin >> s >> e >> t;
			adj[s].push_back({e,-t});
		}
		bool flag = false;
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				for(const auto &p : adj[j])
				{
					int next = p.first;
					int d = p.second+dist[j];
					if(dist[next] > d)
					{
						dist[next] = d;
						if(i == n) flag = true;
					}
				}
			}
		}
		if(true == flag) cout << "YES\n";
		else cout << "NO\n";
	}
}//g++ -o a -std=c++11 *.cpp