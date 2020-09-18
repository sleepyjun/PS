#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

char map[51][51];
int r,c;
const int dist[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

bool visited[51][51][2];
//0 water, 1 user
bool move(int y, int x)
{
	return (y >= 1 && y <= r) && (x >= 1 && x <= c);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c;
	std::queue<pii> water, user;
	pii end;
	for(int y = 1; y <= r; ++y)
	{
		for(int x = 1; x <= c; ++x)
		{
			cin >> map[y][x];
			if(map[y][x] == '*')
				water.push({y,x});
			else if(map[y][x] == 'S')
				user.push({y,x});
			else if(map[y][x] == 'D')
				end = {y,x};
		}
	}
	bool flag = true;
	int res = 0;
	while(flag && !user.empty())
	{
		int wSize = water.size();
		int uSize = user.size();
		
		for(int i = 0; i < wSize; ++i)
		{
			auto curr = water.front();
			water.pop();
			for(int j = 0; j < 4; ++j)
			{
				int ny = curr.first + dist[j][0];
				int nx = curr.second + dist[j][1];
				if(move(ny,nx) == false) continue;
				if(map[ny][nx] == 'X' || map[ny][nx] == 'D') continue;
				if(visited[ny][nx][0] == true) continue;
				visited[ny][nx][0] = true;
				water.push({ny, nx});
			}
		}
		for(int i = 0; flag && i < uSize; ++i)
		{
			auto curr = user.front();
			user.pop();
			for(int j = 0; j < 4; ++j)
			{
				int ny = curr.first + dist[j][0];
				int nx = curr.second + dist[j][1];
				if(move(ny,nx) == false) continue;
				if(map[ny][nx] == 'X') continue;
				if(visited[ny][nx][0] == true) continue;
				if(visited[ny][nx][1] == true) continue;
				if(ny == end.first && nx == end.second)
				{
					flag = false;
					break;
				}
				visited[ny][nx][1] = true;
				user.push({ny, nx});
			}
		}
		res++;
	}
	if(flag)
		cout << "KAKTUS";
	else
		cout << res;
	cout << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;