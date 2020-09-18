// https://www.acmicpc.net/problem/14868
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

using std::make_tuple;
const int DIST[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};
int visited[2001][2001]; // idx'll be 1-2000
int arr[100001];
int find(int n)
{
	if(arr[n] < 0) return n;
	return arr[n] = find(arr[n]);
}
void merge(int p, int c)
{
	p = find(p);
	c = find(c);
	if(p == c) return;
	arr[p] += arr[c];
	arr[c] = p;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k; cin >> n >> k;
	std::fill(arr, arr+k+1, -1);
	//init order must y x!
	int cnt=1;
	std::queue<std::tuple<int,int,int> > q;
	for(int i = 0; i < k; ++i)
	{
		int x,y; cin >> x >> y;
		q.push(make_tuple(y,x,cnt));
		visited[y][x] = cnt;
		for(int j = 0; j < 4; ++j)
		{
			int ny = y + DIST[j][0];
			int nx = x + DIST[j][1];
			if(ny < 1 || ny > n || nx < 1 || nx > n) continue;
			if(visited[ny][nx] != 0 && visited[ny][nx] != cnt)
				merge(cnt, visited[ny][nx]);
		}
		cnt++;
	}
	//bfs
	int res=0;
	cnt=k;
	while(!q.empty())
	{
		int qSize = q.size();
		if(abs(arr[find(1)]) == cnt) break;
		for(int i = 0; i < qSize; ++i)
		{
			auto curr = q.front(); q.pop();
			int cy = std::get<0>(curr);
			int cx = std::get<1>(curr);
			int cg = std::get<2>(curr);
			for(int j = 0; j < 4; ++j)
			{
				int ny = cy + DIST[j][0];
				int nx = cx + DIST[j][1];
				if(ny < 1 || ny > n || nx < 1 || nx > n) continue;
				if(visited[ny][nx] == 0)
				{
					visited[ny][nx] = cg;
					arr[find(cg)]--;
					cnt++;
					q.push(make_tuple(ny,nx,cg));
					for(int h = 0; h < 4; ++h)
					{
						int nny = ny + DIST[h][0];
						int nnx = nx + DIST[h][1];
						if(nny < 1 || nny > n || nnx < 1 || nnx > n) continue;
						if(visited[nny][nnx] != 0 && visited[nny][nnx] != cg)
							merge(cg, visited[nny][nnx]);
					}
				}
			}
		}
		res++;
	}
	
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;