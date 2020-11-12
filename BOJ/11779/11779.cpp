// https://www.acmicpc.net/problem/11779
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<pii> adj[10001];
int dist[10001], prev[10001];

void dijkstra(int s, int e)
{
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq;
   
    std::fill(dist, dist+10001, INF);
    std::fill(prev, prev+10001, 0);
    pq.push({0,s}); dist[s] = 0;
    
    while(!pq.empty())
    {
        const auto &p = pq.top(); 
        int curr = p.second;
        int currDist = p.first;
        pq.pop();
        if(dist[curr] < currDist) continue;

        for(int i=0; i<adj[curr].size(); ++i)
        {
            int next = adj[curr][i].first;
            int d = adj[curr][i].second + currDist;
            if(d < dist[next])
            {
                dist[next] = d;
                prev[next] = curr;
                pq.push({dist[next],next});
            }
        }
    }
    std::vector<int> res;
    cout << dist[e] << '\n';
    while(e)
    {
        res.push_back(e);
        e = prev[e];
    }
    cout << res.size() << '\n';
    for(int i = res.size()-1; i >= 0; --i)
        cout << res[i] << ' ';
    cout << '\n';
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int s,e,w; cin >> s >> e >> w;
        adj[s].push_back({e,w});
    }
    int s,e;
    cin >> s >> e;
    dijkstra(s,e);
}//g++ -o a -std=c++11 *.cpp