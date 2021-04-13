// https://www.acmicpc.net/problem/17472
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

struct edge {
	int u,v,w;
	edge(): u(-1), v(-1), w(999) {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
	const bool operator < (const edge& e)
	{
		return w < e.w;
	}
};
const int DIR[4][2] = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};
int n, m;
int map[11][11];
int adj[7][7];
bool visited[11][11];

bool overRange(int cy, int cx)
{
	return (cy < 1 || cy > n || cx < 1 || cx > m);
}
bool safe(int cy, int cx)
{
	if(true == overRange(cy,cx)) return false;
	if(true == visited[cy][cx]) return false;
	return true;
}
void numbering(int y, int x, int idx)
{
	std::queue<pii> q;
	q.push({y, x});
	visited[y][x] = true;
	while(!q.empty())
	{
		const auto& curr = q.front();
		int cy = curr.first;
		int cx = curr.second;
		map[cy][cx] = idx;
		q.pop();
		for(int i = 0; i < 4; ++i)
		{
			int ny = cy + DIR[i][0];
			int nx = cx + DIR[i][1];
			if(safe(ny,nx))
			{
				if(map[ny][nx] != 0)
				{
					q.push({ny,nx});
					visited[ny][nx] = true;
				}
			}
		}
	}
}
bool bridge(int u, int v, int w)
{
	if(u == v) return true;
	if(u != 0 && w <= 1 && u != v) return true;
	else if(u != 0 && w > 1 && u != v)
	{
		if(u > v) std::swap(u,v);
		adj[u][v] = std::min(adj[u][v], w);
		adj[v][u] = adj[u][v];
		return true;
	}
	return false;
}
void make(int y, int x)
{
	//N
	int cnt = 0;
	int cy=y-1, cx=x;
	while(false == overRange(cy, cx))
	{
		int u = map[cy][cx];
		int v = map[y][x];
		
		if(true == bridge(u,v,cnt)) break;
		cy--; cnt++;
	}
	//E
	cnt = 0;
	cy=y, cx=x+1;
	while(false == overRange(cy, cx))
	{
		int u = map[cy][cx];
		int v = map[y][x];

		if(true == bridge(u,v,cnt)) break;
		cx++; cnt++;
	}
	//S
	cnt = 0;
	cy=y+1, cx=x;
	while(false == overRange(cy, cx))
	{
		int u = map[cy][cx];
		int v = map[y][x];

		if(true == bridge(u,v,cnt)) break;
		cy++; cnt++;
	}
	//W
	cnt = 0;
	cy=y, cx=x-1;
	while(false == overRange(cy, cx))
	{
		int u = map[cy][cx];
		int v = map[y][x];

		if(true == bridge(u,v,cnt)) break;
		cx--; cnt++;
	}
}

int p[7];
int find(int a)
{
	if(p[a] < 0) return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a==b) return false;
	p[b] = a;
	return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= m; ++x)
			cin >> map[y][x];

	int idx = 1;
	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= m; ++x)
			if(map[y][x] != 0 && safe(y,x)) numbering(y,x,idx++);
	idx--;

	std::fill(&adj[0][0], &adj[6][7], 999);
	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= m; ++x)
			if(map[y][x] != 0) make(y,x);

	std::vector<edge> info;
	for(int u = 1; u <= 6; ++u)
		for(int v = u+1; v <= 6; ++v)
			if(adj[u][v] != 999)
				info.push_back(edge(u,v,adj[u][v]));
	
	std::fill(p, p+7, -1);
	
	std::sort(info.begin(), info.end());

	int cnt = 0;
	int res = 0;
	for(int i=0; i < info.size(); i++){
        if(merge(info[i].u, info[i].v)){
			res += info[i].w;
            if(++cnt == idx-1) break;
        }
    }
	
	if(cnt != idx-1) cout << -1 << '\n';
	else cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp