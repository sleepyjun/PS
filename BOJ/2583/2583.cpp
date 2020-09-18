#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

bool board[101][101];
bool visited[101][101];
int cnt = 0;
int m, n, k;

int dir[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

int dfs(int y, int x)
{
	if(y < 0 || y > n-1 || x < 0 || x > m-1) return 0;
	if(board[y][x] == true) return 0;
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
	
	
	cin >> m >> n >> k;
	while(k--)
	{
		int sx,sy,ex,ey;
		cin >> sy >> sx >> ey >> ex;
		
		for(int y = sy; y < ey; ++y)
			for(int x = sx; x < ex; ++x)
				board[y][x] = true;
	}
	
	std::vector<int> v;
	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < m; ++x)
		{
			if(board[y][x] == false && visited[y][x] != true)
			{
				dfs(y,x);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	
	std::sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for(int res : v)
		cout << res << ' ';
	cout << '\n';
}