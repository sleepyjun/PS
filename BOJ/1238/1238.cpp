#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using std::cin; using std::cout;
typedef std::pair<int,int> pii;
const int INF = 987654321;
std::vector<std::pair<int, int> > v[1001];
std::vector<std::pair<int, int> > vr[1001];

int n, m, x;

std::vector<int> solve(const std::vector<pii>* src)
{
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq;
	std::vector<int> dist(n+1, INF);
	pq.push({0,x});
	while(!pq.empty())
	{
		int cl = pq.top().second;
		int cw = pq.top().first;
		pq.pop();
		if(cw > dist[cl]) continue;
		for(auto next : src[cl])
		{
			int nl = next.first;
			int nw = next.second + cw;
			if(dist[nl] > nw)
			{
				dist[nl] = nw;
				pq.push({nw,nl});
			}
		}
	}
	
	// for(int i = 1; i <= n; ++i)
	// 	cout << dist[i] << ' ';
	// cout << '\n';
	
	return dist;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> x;
	
	for(int i = 0; i < m; ++i)
	{
		int s, e, w; cin >> s >> e >> w;
		v[s].push_back({e, w});
		vr[e].push_back({s,w});
	}
	
	std::vector<int> A = solve(v);
	std::vector<int> B = solve(vr);
	
	int res = - 1;
	for(int i = 1; i <= n; ++i)
	{
		if(i==x) continue;
		res = std::max(res, A[i]+B[i]);
	}
	cout << res << '\n';
}