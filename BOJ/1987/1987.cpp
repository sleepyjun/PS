// https://www.acmicpc.net/problem/1987
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int r,c;
char board[21][21];
bool visited[26];
const int dir[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
int res = -1;

void func(int y, int x, int cnt)
{
	if(x < 0 || x > c-1 || y < 0 || y > r-1)
	{
		res = std::max(res, cnt);
		return;
	}
	if(visited[board[y][x]-'A'] == true)
	{
		res = std::max(res, cnt);
		return;
	}
	visited[board[y][x]-'A'] = true;
	for(int i = 0; i < 4; ++i)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		
		func(ny,nx,cnt+1);
	}
	visited[board[y][x]-'A'] = false;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c;
	for(int y = 0; y < r; ++y)
		for(int x = 0; x < c; ++x)
			cin >> board[y][x];
	
	func(0,0,0);
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;