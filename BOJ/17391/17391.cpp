#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
using std::cin; using std::cout;

int arr[301][301];
int visited[301][301];
int n,m;
const int move[2][2] = 
{{0,1},{1,0}};
int solve(int x, int y)
{
	if(x == m && y == n)
		return 0;
	
	int& ret = visited[y][x];
	if(ret != -1) return ret;
	
	ret = 9999;
	int canMove = arr[y][x];
	for(int i = 0; i < 2; ++i)
	{
		int nx = x, ny = y;
		for(int j = 1; j <= canMove; ++j)
		{
			nx += move[i][0]; ny += move[i][1];
			if((nx<1 || nx>m)||(ny<1 || ny>n)) break;
			
			ret = std::min(ret, solve(nx, ny)+1);
		}
	}
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> arr[i][j];
	std::fill(&visited[0][0], &visited[300][300], -1);
	
	cout << solve(1,1) << '\n';
	// for(int i = 1; i <= n; ++i)
	// {
	// 	for(int j = 1; j <= m; ++j)
	// 		cout << visited[i][j];	
	// 	cout << '\n';
	// }
}