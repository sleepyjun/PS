#include <iostream>
#include <algorithm>
#include <vector>

using std::cin; using std::cout;
const int INF = 987654321;
typedef std::pair<int, int> pii;


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	int n,m,w;
	int dist[501];
	std::vector<pii> adj[501];
	while(t--)
	{
		cin >> n >> m >> w;
		std::fill(dist, dist+n+1, INF);
		dist[1] = 0;
		
		for(int i = 0; i < m; ++i)
		{
			int s,e,t; cin >> s >> e >> t;
			
			adj[s].push_back({e,t});
			adj[e].push_back({s,t});
		}
		for(int i = 0; i < w; ++i)
		{
			int s,e,t; cin >> s >> e >> t;
			
			t = -t;
			adj[s].push_back({e,t});
		}
		
		bool flag = false;
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				for(auto &next: adj[j])
				{
					int nv = next.first;
					int w = next.second + dist[j];
					if(dist[j]!=INF && dist[nv] > w)
					{
						dist[nv] = w;
						if(i==n) flag = true;
					}
				}
			}
		}
		
		if(flag == true) cout << "YES";
		else cout << "NO";
		cout << '\n';
		
		for(int i = 1; i <= n; ++i)
			adj[i].clear();
	}
}