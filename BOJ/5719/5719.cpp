// https://www.acmicpc.net/problem/5719
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
const int INF = 987654321;

std::vector<pii> adj[501];
std::vector<pii> adjR[501];
int dist[501];
bool visited[501][501];
int n,m;

void solve(int s)
{
	std::priority_queue<pii, std::vector<pii>,
		std::greater<pii> > pq;
	std::fill(dist,dist+n,INF);
	
	pq.push({0,s});
	dist[s] = 0;
	
	while(!pq.empty())
	{
		int cw = pq.top().first;
		int cl = pq.top().second;
		pq.pop();
		
		if(dist[cl] < cw) continue;
		for(pii next : adj[cl])
		{
			int nl = next.first;
			int nw = next.second + cw;
			if(visited[cl][nl]) continue;
			if(dist[nl] > nw)
			{
				dist[nl] = nw;
				pq.push({nw, nl});
			}
		}
	}
}

void deletePath(int s, int d)
{
	if(s==d) return;

	for(pii prev : adjR[d])
	{
		int pre = prev.first;
		if(visited[pre][d] == false && dist[pre] + prev.second == dist[d])
		{
			visited[pre][d] = true;
			deletePath(s, pre);
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		std::fill(&visited[0][0], &visited[500][500], false);
		cin >> n >> m;
		if(n==0 && m==0) break;
		
		int s,d; cin >> s >> d;
		
		for(int i = 0; i < m; ++i)
		{
			int u,v,p; cin >> u >> v >> p;
			adj[u].push_back({v,p});
			adjR[v].push_back({u,p});
		}
		
		solve(s);
		deletePath(s,d);
		solve(s);
		
		if(dist[d] >= INF)
			cout << -1 << '\n';
		else cout << dist[d] << '\n';
		
		for(int i = 0; i < n; ++i)	
		{
			adj[i].clear();
			adjR[i].clear();
		}
	}
}//g++ -o a -std=c++17 *.cpp