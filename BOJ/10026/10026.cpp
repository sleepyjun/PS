#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int n;
char grid[101][101];
bool visited[101][101];
int dir[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};

void dfs(int y, int x, const char ch)
{
	
	if(visited[y][x] == true) return;
	if(x < 0 || x > n-1 || y < 0 || y > n-1) return;
	if(grid[y][x] != ch) return;
	
	visited[y][x] = true;
	for(int i = 0; i < 4; ++i)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		dfs(ny, nx, ch);
	}
	
	return;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&grid[0][0], &grid[100][101], '$');
	std::fill(&visited[0][0], &visited[100][101], false);
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> grid[i][j];
	
	int cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(visited[i][j] != true)
			{
				dfs(i,j,grid[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt << ' ';
	
	cnt = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(grid[i][j] == 'G') grid[i][j] = 'R';
	
	std::fill(&visited[0][0], &visited[100][101], false);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(visited[i][j] != true)
			{
				dfs(i,j,grid[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}