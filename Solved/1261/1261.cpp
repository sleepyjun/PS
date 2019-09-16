#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using std::cin; using std::cout;

typedef std::pair<int, std::pair<int, int> > wxy;

const int INF = 3333333;
const int move[4][2] = {
	{1,0},{0,1},{-1,0},{0,-1}
};

int laby[110][110];
int dist[110][110];
int m, n; 

int solve()
{
	std::fill(&dist[0][0], &dist[109][109], INF);
	std::priority_queue<wxy, std::vector<wxy>, std::greater<wxy> > pq;
	
	dist[1][1] = 0;
	pq.push({0, {1, 1}});
	
	while(!pq.empty())
	{
		int cw = pq.top().first;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();
		if(dist[cy][cx] < cw) continue;
		
		for(int i = 0; i < 4; ++i)
		{
			int nx = cx+move[i][0];
			int ny = cy+move[i][1];
			if(nx < 1 || nx > m || ny < 1 || ny > n)
				continue;
			int nw = cw+laby[ny][nx];
			if(dist[ny][nx] > nw)
			{
				dist[ny][nx] = nw;
				pq.push({nw,{nx,ny}});
			}
		}
	}
	
	return dist[n][m];
}
int main()
{
	scanf("%d %d", &m, &n);
	//가로 세로
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%1d", &laby[i][j]);
	
	printf("%d\n",solve());
}