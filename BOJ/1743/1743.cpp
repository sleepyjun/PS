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
int cnt = 0;
int n, m, k;
int dir[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

int dfs(int y, int x)
{
	if(map[y][x] == -1) return 0;
	if(visited[y][x] == true) return 0;
	
	visited[y][x] = true;
	cnt++;
	for(int i = 0; i < 4; ++i)
	{
		int ny = y+dir[i][0];
		int nx = x+dir[i][1];
		dfs(ny,nx);
	}
	
	return cnt;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	cin >> n >> m >> k;
	
	std::fill(&map[0][0], &map[100][101], -1);
	
	while(k--)
	{
		int y,x;
		cin >> y >> x;
		map[y][x] = 1;
	}
	
	int max = -1;
	for(int y = 1; y <= n; ++y)
	{
		for(int x = 1; x <= m; ++x)
		{
			if(map[y][x] != -1 && visited[y][x] != true)
			{
				dfs(y,x);
				max = std::max(max, cnt);
				cnt = 0;
			}
		}
	}
	
	cout << max << '\n';
}