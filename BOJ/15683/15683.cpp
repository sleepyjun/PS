// https://www.acmicpc.net/problem/15683
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const std::vector<std::vector<int> > DIR[5] = {
	{ {0}, {1}, {2}, {3} },
	{ {0,2}, {1,3} },
	{ {0,1}, {1,2}, {2,3}, {3,0} },
	{ {0,1,3}, {0,1,2}, {1,2,3}, {2,3,0} },
	{ {0,1,2,3} }
};
std::vector<pii> cctv;
int map[10][10];
int n,m,res=INF; 

bool safe(const int &y, const int &x)
{
	return (1 <= y && y <= n) && (1 <= x && x <= m);
}
void look(int y, int x, int l)
{
	switch(l)
	{
	case 0: //east
		while(1)
		{
			x++;
			if(false == safe(y,x)) break;
			if(map[y][x] == 6) break;
			if(map[y][x] == 0) map[y][x] = 7; 
		}
		break;
	case 1: //south
		while(1)
		{
			y++;
			if(false == safe(y,x)) break;
			if(map[y][x] == 6) break;
			if(map[y][x] == 0) map[y][x] = 7; 
		}
		break;
	case 2: //west
		while(1)
		{
			x--;
			if(false == safe(y,x)) break;
			if(map[y][x] == 6) break;
			if(map[y][x] == 0) map[y][x] = 7; 
		}
		break;
	case 3: //north
		while(1)
		{
			y--;
			if(false == safe(y,x)) break;
			if(map[y][x] == 6) break;
			if(map[y][x] == 0) map[y][x] = 7; 
		}
		break;
	}
}
int eval()
{
	int count = 0;
	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= m; ++x)
			if(map[y][x] == 0) count++;
	return count;
}
void dfs(int idx)
{
	if(idx == cctv.size())
	{
		res = std::min(res,eval());
		return;
	}
	const auto& curr = cctv[idx];
	int y = curr.first, x = curr.second;
	int kind = map[y][x]-1;
	int backup[10][10];

	for(const auto& toLook: DIR[kind])
	{
		std::copy(&map[0][0], &map[9][10], &backup[0][0]);
		for(int l: toLook) look(y,x,l);
		dfs(idx+1);
		std::copy(&backup[0][0], &backup[9][10], &map[0][0]);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for(int y = 1; y <= n; ++y)
	{
		for(int x = 1; x <= m; ++x)
		{
			cin >> map[y][x];
			if(1 <= map[y][x] && map[y][x] <= 5)
			{
				cctv.push_back({y,x});
			}
		}
	}

	dfs(0);
	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp