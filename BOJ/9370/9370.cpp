#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <limits>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();
std::vector<pii> adj[2001];
std::vector<int> maybe;

void solve(int n, int start)
{
	std::priority_queue<pii, 
		std::vector<pii>, std::greater<pii> > pq;
	std::vector<int> dist(n+1, INF);
	
	pq.push({0,start});
	while(!pq.empty())
	{
		int cw = pq.top().first;
		int cl = pq.top().second;
		pq.pop();
		
		if(cw > dist[cl]) continue;
		
		for(pii next : adj[cl])
		{
			int nl = next.first;
			int nw = next.second + cw;
			if(nw < dist[nl])
			{
				dist[nl] = nw;
				pq.push({nw,nl});
			}
		}
	}
	
	std::vector<int> res;
	for(int i : maybe)
		if(dist[i] % 2 != 0)
			res.push_back(i);
	
	std::sort(res.begin(), res.end());
	for(int i : res)
		cout << i << ' ';
	cout << '\n';
	
	return;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n,m,t; cin >> n >> m >> t;
		int s,g,h; cin >> s >> g >> h;
		
		for(int i = 0; i < m; ++i)
		{
			int a,b,d; cin >> a >> b >> d;
			d *= 2;
			if((a==g && b==h) || 
			   (a==h && b==g))
				d -= 1;
			adj[a].push_back({b,d});
			adj[b].push_back({a,d});
		}
		
		for(int i = 0; i < t; ++i)
		{
			int x; cin >> x;
			maybe.push_back(x);
		}
		
		solve(n,s);
		
		for(int i = 0; i <= n; ++i)
			adj[i].clear();
		maybe.clear();
	}
}