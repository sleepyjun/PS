#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int map[101][101];
bool visited[101][101];
int n;
int dir[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};

void dfs(const int y, const int x, const int limit)
{
	if(x < 0 || x > n-1 || y < 0 || y > n-1) return;
	if(map[y][x] <= limit) return;
	if(visited[y][x] == true) return;
	visited[y][x] = true;
	
	for(int i = 0; i < 4; ++i)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		dfs(ny, nx, limit);
	}
	
	return;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&map[0][0], &map[100][101], INF);
	cin >> n;
	int max = -1;
	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x)
		{
			cin >> map[y][x];
			max = std::max(max, map[y][x]);
		}
	}
	
	int res = -1;
	for(int i = 0; i < max; ++i)
	{
		int cnt = 0;
		std::fill(&visited[0][0], &visited[100][101], false);
		for(int y = 0; y < n; ++y)
		{
			for(int x = 0; x < n; ++x)
			{
				if(map[y][x] > i && visited[y][x] == false)
				{
					dfs(y,x,i);
					cnt++;
				}
			}
		}
		res = std::max(res, cnt);
	}
	
	cout << res << '\n';
}