#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

using std::cin; using std::cout;
typedef std::pair<long long, long long> pii;
const long long INF = std::numeric_limits<long long>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	long long n,s,e,m;
	long long earn[101];
	std::vector<pii> adj[101];
	cin >> n >> s >> e >> m;
	
	for(int i = 0; i < m; ++i)
	{
		int s,e,c;
		cin >> s >> e >> c;
		adj[s].push_back({e,c});
	}
	for(int i = 0; i < n; ++i)
		cin >> earn[i];
	
	long long dist[101];
	std::queue<int> cycle;
	bool flag = false;
	bool visited[101] = {false,};
	std::fill(dist, dist+101, INF);
	dist[s] = -earn[s];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(auto& node : adj[j])
			{
				long long next = node.first;
				long long cost = node.second + dist[j] - earn[next];
				if(dist[next] > cost && dist[j] != INF)
				{
					dist[next] = cost;
					if(i == n-1)
						cycle.push(j);
				}
			}
		}
	}
	
	while(!cycle.empty())
	{
		int here = cycle.front();
		cycle.pop();
		if(visited[here] == true) continue;
		if(here == e)
		{
			flag = true;
			break;
		}
		visited[here] = true;
		for(auto& node : adj[here])
			cycle.push(node.first);
		
	}

	if(flag == true)
		cout << "Gee";
	else if(dist[e] == INF)
		cout << "gg";
	else
		cout << -dist[e];
	cout << '\n';
}