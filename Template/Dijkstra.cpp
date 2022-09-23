//? 다익스트라
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> pii;
const int MAX = 1001;
const int INF = 999999;
std::vector<pii> adj[MAX];
int dist[MAX], prev[MAX];

int func(int start, int end) {
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq;    
    std::fill(dist,dist+MAX,INF);
    std::fill(prev,prev+MAX,-1);
    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty())
    {
        const auto &p = pq.top();
        int cost = p.first;
        int curr = p.second;
        pq.pop();
        if(dist[curr] < cost) continue;
        for(auto q : adj[curr]) {
            int next = q.first;
            int d = q.second + cost;
            if(d < dist[next])
            {
                dist[next] = d;
                prev[next] = curr;
                pq.push({dist[next], next});
            }
        }
    }

    return dist[end];
}

void track(int node, int step)
{
    if(prev[node] == -1) {
        std::cout << step << '\n';
        std::cout << node << ' ';
        return;
    }
    track(prev[node], step+1);
    std::cout << node << ' ';
}

int main()
{
    return 0;
}