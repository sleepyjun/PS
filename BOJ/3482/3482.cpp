// https://www.acmicpc.net/problem/3482
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIST[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};
char map[1002][1002];
bool visited[1002][1002];
int res, temp;
int rX, rY;

void dfs(int x, int y)
{
	visited[y][x] = true;
	for(int i = 0; i < 4; ++i)
	{
		int nx = x+DIST[i][0];
		int ny = y+DIST[i][1];
		if(map[ny][nx] == '#') continue;
		if(visited[ny][nx]) continue;
		temp++;
		if(res < temp)
		{
			res = temp;
			rX = nx;
			rY = ny;
		}
		dfs(nx,ny);
		temp--;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		temp = 0; res = 0;
		std::fill(&map[0][0], &map[1001][1002], '#');
		std::fill(&visited[0][0], &visited[1001][1002], false);
		int x,y; cin >> x >> y;
		int sX,sY;
		for(int i = 1; i <= y; ++i)
		{
			for(int j = 1; j <= x; ++j)
			{
				cin >> map[i][j];
				if(map[i][j] == '.')
				{
					sX = j;
					sY = i;
				}
			}
		}
		rX=sX; rY=sY;
		dfs(sX,sY);
		std::fill(&visited[0][0], &visited[1001][1002], false);
		temp = 0;
		dfs(rX,rY);
		cout << "Maximum rope length is " << res << ".\n";
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;