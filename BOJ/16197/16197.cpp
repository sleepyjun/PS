// https://www.acmicpc.net/problem/16197
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
int n, m;
char map[21][21];

bool range(int y, int x)
{
	if(1 <= y && y <= n && 1 <= x && x <= m) return true;
	else return false;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::queue<pii> q;
	 cin >> n >> m;
	for(int y = 1; y <= n; ++y)
	{
		for(int x = 1; x <= m; ++x)
		{
			cin >> map[y][x];
			if(map[y][x] == 'o') q.push({y,x});
		}
	}

	int cnt = 1;
	while(!q.empty())
	{
		if(cnt > 10)
		{
			break;
		}
		int qSize = q.size();
		for(int i = 0; i < qSize; i+=2)
		{
			pii coin1 = q.front(); q.pop();
			pii coin2 = q.front(); q.pop();

			int cy1 = coin1.first, cx1 = coin1.second; 
			int cy2 = coin2.first, cx2 = coin2.second;

			for(int j = 0; j < 4; ++j)
			{
				int ny1 = cy1+DIR[j][0], nx1 = cx1+DIR[j][1];
				int ny2 = cy2+DIR[j][0], nx2 = cx2+DIR[j][1];
				
				if(range(ny1, nx1) == false && range(ny2, nx2) == false) continue;
				else if((range(ny1, nx1) == false && range(ny2, nx2) == true) ||
					(range(ny1, nx1) == true && range(ny2, nx2) == false))
				{
					cout << cnt << '\n';
					return 0;
				}

				if(map[ny1][nx1] == '#') 
				{
					ny1 = cy1; 
					nx1 = cx1;
				}
				if(map[ny2][nx2] == '#')
				{
					ny2 = cy2;
					nx2 = cx2;
				}
				
				q.push({ny1, nx1});
				q.push({ny2, nx2});
			}
		}
		cnt++;
	}
	cout << -1 << '\n';
}//g++ -o a -std=c++17 *.cpp