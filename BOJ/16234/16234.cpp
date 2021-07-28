// https://www.acmicpc.net/problem/16234
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
const int DIR[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

int map[52][52];
bool visited[52][52];
int n,l,r;

int bfs(int y, int x)
{
	int sum = map[y][x];
	std::queue<pii> q, res;

	q.push({y,x}); res.push({y,x});
	visited[y][x] = true;
	
	while(!q.empty())
	{
		auto curr = q.front(); q.pop();
		int cy = curr.first;
		int cx = curr.second;

		for(int i = 0; i < 4; ++i)
		{
			int ny = cy+DIR[i][0];
			int nx = cx+DIR[i][1];

			if(map[ny][nx] == -1) continue;
			if(visited[ny][nx]) continue;

			int diff = abs(map[cy][cx] - map[ny][nx]);
			if(l <= diff && diff <= r)
			{
				visited[ny][nx] = true;
				q.push({ny,nx});
				res.push({ny,nx});
				sum += map[ny][nx];
			}
		}
	}
	
	int count = res.size();
	while(!res.empty())
	{
		auto curr = res.front();
		map[curr.first][curr.second] = (sum/count);
		res.pop();
	}
	return count;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&map[0][0], &map[51][52], -1);
	cin >> n >> l >> r;

	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= n; ++x)
			cin >> map[y][x];

	int count = 0;
	while(++count)
	{
		std::fill(&visited[0][0], &visited[51][52], false);
		int max = -1;
		for(int y = 1; y <= n; ++y)
		{
			for(int x = 1; x <= n; ++x)
			{
				if(visited[y][x] == false)
				{
					max = std::max(max, bfs(y,x));
				}
			}
		}
		
		if(max == 1) break;
	}
	cout << count-1 << '\n';
}//g++ -o a -std=c++17 *.cpp