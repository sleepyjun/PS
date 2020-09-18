#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int res;
int m,n; 
int arr[501][501];
int dp[501][501];
const int pos[4][2] = {
	{0,-1}, {0,1}, {-1,0}, {1,0}	
};//x,y
int solve(int x, int y)
{
	if(y == m && x == n) 
		return 1;
	if((x<1 || x>n) || (y<1 || y>m)) return 0;
	
	int& ret = dp[y][x];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < 4; ++i)
	{
		int nx = x + pos[i][0];
		int ny = y + pos[i][1];
		if(arr[y][x] > arr[ny][nx])
		{
			ret += solve(nx, ny);
		}
	}
	
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> arr[i][j];
	std::fill(&dp[0][0], &dp[500][500], -1);
	cout << solve(1,1) << '\n';
	
}