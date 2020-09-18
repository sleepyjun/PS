#include <iostream>
#include <algorithm>
#include <vector>

using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;
std::vector<pii> adj[501];
long long dist[501];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	std::fill(dist+1, dist+n+1, INF);
	dist[1] = 0;
	bool flag = false;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			for(auto &next: adj[j])
			{
				int nv = next.first;
				long long w = next.second + dist[j];
				if(dist[j]!=INF && dist[nv] > w)
				{
					dist[nv] = w;
					if(i==n) flag = true;
				}
			}
		}
	}
	
	if(flag == true) cout << -1 <<'\n';
	else
		for(int i = 2; i <= n; ++i)
			cout << (dist[i] != INF ? dist[i] : -1) << '\n';
}