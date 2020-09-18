// https://www.acmicpc.net/problem/1189
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int r,c,k;
char board[5][5];
bool visited[5][5];
int res = 0;
const int dir[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

void func(int y, int x, int cnt = 1) 
{
	if(y == 0 && x == c-1)
	{
		if(cnt == k)
			res++;
		return;
	}
	for(int i = 0; i < 4; ++i)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if(ny < 0 || ny > r-1 || nx < 0 || nx > c-1) continue;
		if(visited[ny][nx] == true) continue;
		if(board[ny][nx] == 'T') continue;
		visited[ny][nx] = true;
		func(ny,nx,cnt+1);
		visited[ny][nx] = false;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c >> k;
	for(int y = 0; y < r; ++y)
		for(int x = 0; x < c; ++x)
			cin >> board[y][x];
	visited[r-1][0] = true;
	func(r-1,0);
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;