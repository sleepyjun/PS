// https://www.acmicpc.net/problem/14503
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int ry,rx,point,res,n,m;
int map[52][52]; 
int visited[52][52];
//idx will be start 0
int dir[4][2] = {
	{0,-1},
	{1,0},
	{0,1},
	{-1,0}
};
void rotate(int& x) { x = (x==3) ? 0 : x+1; }
void func()
{
	while(1)
	{
		if(visited[ry][rx] == false)
		{
			visited[ry][rx] = true;
			res++;
		}
		// 1
		bool flag = true;
		for(int i = 0; flag && i < 4; ++i)
		{
			int ny = ry + dir[point][0];
			int nx = rx + dir[point][1];
			rotate(point);
			if(map[ny][nx] == 0 && visited[ny][nx] == false)
			{
				ry = ny;
				rx = nx;
				flag = false;
			}
		}
		if(flag)
		{
			int temp = (point==3 ? 0 : point+1);
			int ny = ry + dir[temp][0];
			int nx = rx + dir[temp][1];
			if(map[ny][nx] == 1)
				return;
			ry = ny;
			rx = nx;
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	cin >> ry >> rx >> point;
	for(int y = 0; y < n; ++y)
		for(int x = 0; x < m; ++x)
			cin >> map[y][x];
	if(point == 3) point = 1;
	else if(point == 1) point = 3;
	func();
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;