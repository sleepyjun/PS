// https://www.acmicpc.net/problem/1194
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

char map[52][52];
bool visited[52][52][(1<<6)];
const int DIR[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};

bool tryOpen(int ny, int nx, int status)
{
	bool flag = true;
	for(char i = 'A'; flag && i <= 'F'; ++i)
	{
		if(!(status & (1<<(i-'A'))) && 
		  map[ny][nx] == i)
			flag = false;
	}
	return flag;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	int _x,_y,gx,gy;
	std::fill(&map[0][0], &map[51][52], '#');
	for(int y = 1; y <= n; ++y)
	{
		for(int x = 1; x <= m; ++x)
		{
			cin >> map[y][x];
			if(map[y][x] == '0')
			{
				_y = y;
				_x = x;
			}
			if(map[y][x] == '1')
			{
				gy = y;
				gx = x;
			}
		}
	}
	
	int res = 0;
	bool solve = false;
	std::queue<std::tuple<int,int,int> > q;
	q.push(std::make_tuple(_y,_x,0));
	visited[_y][_x][0] = true;
	while(!q.empty() && !solve)
	{
		int qSize = q.size();
		for(int i = 0; !solve && i < qSize; ++i)
		{
			int cy,cx,status;
			std::tie(cy,cx,status) = q.front();
			q.pop();
			for(int i = 0; i < 4; ++i)
			{
				int ny = cy + DIR[i][0];
				int nx = cx + DIR[i][1];
				int nstatus = status;
				
				if(map[ny][nx] == '#') continue;
				if(true == visited[ny][nx][status]) continue;
				if(false == tryOpen(ny,nx,status)) continue;
				
				if(map[ny][nx] == '1')
				{
					solve = true;
					break;
				}
				
				visited[ny][nx][nstatus] = true;
				for(char i = 'a'; i <= 'f'; ++i)
				{
					if(map[ny][nx] == i)
					{
						nstatus |= (1<<(i-'a'));
						break;
					}
				}
				visited[ny][nx][nstatus] = true;
				
				q.push(std::make_tuple(ny,nx,nstatus));
			}
		}
		
		res++;
	}
	
	if(solve) cout << res;
	else cout << -1;
	cout << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;