// https://www.acmicpc.net/problem/3197
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

int r,c;
char map[1501][1501];
bool visited[1501][1501];

bool safe(const int &y, const int &x)
{
	if((1 <= y && y <= r) && (1 <= x && x <= c))
		return true;
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c;

	std::vector<pii> bird;
	std::queue<pii> q, water;

	for(int y = 1; y <= r; ++y)
	{
		for(int x = 1; x <= c; ++x)
		{
			cin >> map[y][x];
			if(map[y][x] == 'X') continue;

			if(map[y][x] == 'L') bird.push_back({y,x});
			water.push({y,x});
		}
	}

	int res = 0;
	q.push(bird[0]);
	while(1)
	{
		std::queue<pii> next;
		while(!q.empty())
		{
			auto pos = q.front(); q.pop();
			int cy = pos.first;
			int cx = pos.second;
			
			if(pos == bird[1])
			{
				cout << res << '\n';
				return 0;
			}

			for(int i = 0; i < 4; ++i)
			{
				int ny = cy + DIR[i][0];
				int nx = cx + DIR[i][1];

				if(false == safe(ny, nx)) continue;
				if(true == visited[ny][nx]) continue;
				
				visited[ny][nx] = true;
				if(map[ny][nx] == 'X')
				{
					next.push({ny,nx});
					continue;
				}
				q.push({ny,nx});
			}
		}

		q = next;

		int qSize = water.size();
		for(int i = 0; i < qSize; ++i)
		{
			auto pos = water.front(); water.pop();
			int cy = pos.first;
			int cx = pos.second;

			for(int i = 0; i < 4; ++i)
			{
				int ny = cy + DIR[i][0];
				int nx = cx + DIR[i][1];

				if(false == safe(ny,nx)) continue;
				if(map[ny][nx] != 'X') continue;
				map[ny][nx] = '.';
				water.push({ny, nx});
			}
		}
		res++;
	}
}//g++ -o a -std=c++17 *.cpp