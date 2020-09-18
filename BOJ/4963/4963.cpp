// https://www.acmicpc.net/problem/4963
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

int map[51][51];
bool visited[51][51];
int dir[8][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0},
	{-1,-1},
	{1,1},
	{-1,1},
	{1,-1}
};
int w,h;

int bfs(int y, int x)
{
	if(visited[y][x] == true)
		return 0;
	
	std::queue<pii> q;
	q.push({y,x});
	visited[y][x] = true;
	while(!q.empty())
	{
		pii curr = q.front();
		q.pop();
		for(int i = 0; i < 8; ++i)
		{
			int ny = curr.first + dir[i][0];
			int nx = curr.second + dir[i][1];
			if(ny < 1 || ny > h || nx < 1 || nx > w) continue;
			if(visited[ny][nx] == true) continue;
			if(map[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			q.push({ny,nx});
		}
	}
	return 1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		int res=0; cin >> w >> h;
		if(w==0) return 0;
		for(int y = 1; y <= h; ++y)
			for(int x = 1; x <= w; ++x)
				cin >> map[y][x];
		
		for(int y = 1; y <= h; ++y)
			for(int x = 1; x <= w; ++x)
				if(map[y][x])
					res += bfs(y,x);
		
		cout << res << '\n';
		
		std::fill(&map[0][0], &map[50][51], 0);
		std::fill(&visited[0][0], &visited[50][51], false);
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;