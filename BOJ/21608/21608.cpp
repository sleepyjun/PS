// https://www.acmicpc.net/problem/21608
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int SCORE[5] = {0, 1, 10, 100, 1000};
const int DIR[4][2] = {
	{ 0,-1},
	{ 0, 1},
	{-1, 0},
	{ 1, 0}
};
bool love[401][401];
int map[401][401];
int n;

bool safe(int y, int x)
{
	return (1 <= y && y <= n) && (1 <= x && x <= n);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	std::vector<int> student;

	for(int i = 0; i < n*n; ++i)
	{
		int x; cin >> x;
		student.push_back(x);
		for(int j = 0; j < 4; ++j)
		{
			int l; cin >> l;
			love[x][l] = true;
		}
	}

	for(int s: student)
	{
		int sy = -1, sx = -1;
		int w = -1;
		for(int y = 1; y <= n; ++y)
		{
			for(int x = 1; x <= n; ++x)
			{
				int test = 0;

				if(map[y][x] != 0) continue;

				for(int d = 0; d < 4; ++d)
				{
					int ny = y+DIR[d][0];
					int nx = x+DIR[d][1];

					if(false == safe(ny,nx)) continue;
					
					if(map[ny][nx] == 0) test += 1;
					else if(love[s][map[ny][nx]]) test += 5;
				}
				if(w < test)
				{
					sy = y; sx = x;
					w = test;
				}
			}
		}
		map[sy][sx] = s;
	}

	int res = 0;
	for(int y = 1; y <= n; ++y)
	{
		for(int x = 1; x <= n; ++x)
		{
			int curr = map[y][x];
			int count = 0;
			for(int d = 0; d < 4; ++d)
			{
				int ny = y+DIR[d][0];
				int nx = x+DIR[d][1];

				if(false == safe(ny,nx)) continue;
				if(love[curr][map[ny][nx]]) count++;
			}

			res += SCORE[count];
		}
	}

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp