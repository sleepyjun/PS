#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <limits>
#include <vector>
using std::cin; using std::cout;

typedef unsigned long long ull;
const ull MAX = std::numeric_limits<ull>::max();
std::vector<std::pair<int, int> > v[100001];
bool visible[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
	{
		int vis; cin >> vis;
		visible[i] = (vis == 1);
	}
	for(int i = 0; i < m; ++i)
	{
		int a,b,t; cin >> a >> b >> t;

		v[a].push_back({b, t});
		v[b].push_back({a, t});
	}
	
	std::vector<ull> dist(n, MAX);
	dist[0] = 0;
	std::priority_queue<std::pair<ull, ull>, std::vector<std::pair<ull, ull> >, std::greater<std::pair<ull, ull> > > pq;
	pq.push({0, 0});
	
	while(!pq.empty())
	{
		ull cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(dist[here] < cost) continue;
		
		for(int i = 0; i < v[here].size(); ++i)
		{
			int there = v[here][i].first;
			ull nextDist = cost + v[here][i].second;
			
			if(there != n-1 && visible[there] == true) continue;
			if(dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push({nextDist, there});
			}
		}
	}
	
	if(dist[n-1] == MAX) cout << -1 << '\n';
	else cout << dist[n-1] << '\n';
}