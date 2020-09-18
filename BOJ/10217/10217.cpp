#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using std::cin; using std::cout;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> T;
const int INF = 987654321;

int dist[102][10002];
// place, cost
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	std::vector<T> v[101];
	//v[start] = {end, cost, time};
	
	while(t--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		for(int i = 0; i < k; ++i)
		{
			int s,e,c,t; 
			cin >> s >> e >> c >> t;
			v[s].push_back(std::make_tuple(e,c,t));
		}
		std::fill(&dist[0][0], &dist[101][10002], INF);
		
		std::priority_queue<T, std::vector<T>, std::greater<T> > pq;
		//time, place, cost;
		dist[1][0] = 0;
		pq.push(std::make_tuple(0,1,0));
		while(!pq.empty())
		{
			int cTime = std::get<0>(pq.top());
			int here = std::get<1>(pq.top());
			int cCost = std::get<2>(pq.top());
			pq.pop();
			
			for(int i = 0; i < v[here].size(); ++i)
			{
				int there = std::get<0>(v[here][i]);
				int nCost = std::get<1>(v[here][i]) + cCost;
				int nTime = std::get<2>(v[here][i]) + cTime;
				
				if(nCost > m) continue;
				if(dist[there][nCost] > nTime)
				{
					dist[there][nCost] = nTime;
					pq.push(std::make_tuple(nTime, there, nCost));
				}
			}
		}
		
		int res = INF+1;
		for(int i = m; i >= 0; --i)
			res = std::min(res, dist[n][i]);
		if(res == INF)
			cout << "Poor KCM";
		else 
			cout << res;
		cout << '\n';
		
		
		
		for(int i = 0; i <= n; ++i)
			v[i].clear();
	}
}