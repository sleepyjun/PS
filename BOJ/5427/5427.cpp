#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int x,y;
char map[1024][1024];
bool visited[1024][1024][2];
//y,x,(user or fire);
int dir[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

void solve()
{
	bool flag = true;
	int time = 0;
	std::queue<pii> user, fire;
	//first == y, second == x
	for(int i = 1; i <= y; ++i)
	{
		for(int j = 1; j <= x; ++j)
		{
			if(map[i][j] == '@')
			{
				user.push({i,j});
				visited[i][j][0] = true;
				if((j == 1 || i == 1 || i == y || j == x))
				{
					time = 1;
					flag = false;
				}
			}
			else if(map[i][j] == '*')
			{
				fire.push({i,j});	
				visited[i][j][1] = true;
			}
		}
	}
	while(flag && !user.empty())
	{
		int uSize = user.size();
		int fSize = fire.size();
		
		for(int i = 0; i < fSize; ++i)
		{
			auto curr = fire.front();
			fire.pop();
			for(int j = 0; j < 4; ++j)
			{
				int ny = curr.first+dir[j][0];
				int nx = curr.second+dir[j][1];
				
				if(map[ny][nx] == '#') continue;
				if(visited[ny][nx][1] == true) continue;
				
				visited[ny][nx][1] = true;
				fire.push({ny,nx});
				
				// cout << "fire pushed " << ny << ' ' << nx << '\n';
			}
		}
		
		for(int i = 0; flag && i < uSize; ++i)
		{
			auto curr = user.front();
			user.pop();
			for(int j = 0; j < 4; ++j)
			{
				int ny = curr.first+dir[j][0];
				int nx = curr.second+dir[j][1];
				
				if(map[ny][nx] == '#') continue;
				if(visited[ny][nx][0] == true) continue;
				if(visited[ny][nx][1] == true) continue;
				
				if((nx == 1 || ny == 1 || ny == y || nx == x) && map[ny][nx] == '.')
				{
					time++;
					flag = false;
					break;
				}
				
				visited[ny][nx][0] = true;
				user.push({ny,nx});
				
				
				// cout << "user pushed " << ny << ' ' << nx << '\n';
			}
		}
		
		time++;
	}
	if(flag)
		cout << "IMPOSSIBLE";
	else
		cout << time;
	cout << '\n';
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(&map[0][0],&map[1023][1001],'#');
		std::fill(&visited[0][0][0],&visited[1023][1023][2],false);
		cin >> x >> y;
		for(int i = 1; i <= y; ++i)
			for(int j = 1; j <= x; ++j)
				cin >> map[i][j];
		
		solve();
	}
}
//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;
