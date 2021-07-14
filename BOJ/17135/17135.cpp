// https://www.acmicpc.net/problem/17135
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

const int DIR[3][2] = {
	{0,-1},
	{-1,0},
	{0,1}
};

int n,m,d,score;
int map[16][16];
int src[16][16];
bool visited[16][16];

bool safe(const int& y, const int& x)
{
	return (1 <= y && y <= n) && (1 <= x && x <= m);
}
void go()
{
	for(int i = n; i >= 1; --i)
		std::copy(&map[i-1][1], &map[i-1][m+1], &map[i][1]);
}
void go(const std::vector<int> &v)
{
	int limit;
	bool marking[16][16];
	for(int i = 0; i < v.size(); ++i)
	{
		if(v[i] == 1) continue;
		std::fill(&marking[0][0], &marking[15][16], false);
		limit = d;
		bool find = false;
	
		std::queue<pii> q;
		q.push({n+1, i+1});
		while(limit--)
		{
			int qSize = q.size();
			while(qSize--)
			{
				auto curr = q.front(); q.pop();
				int cy = curr.first;
				int cx = curr.second;
				for(int j = 0; j < 3; ++j)
				{
					int ny = cy + DIR[j][0];
					int nx = cx + DIR[j][1];

					if(false == safe(ny, nx)) continue;
					if(true == marking[ny][nx]) continue;
					
					if(map[ny][nx] == 1)
					{
						find = true;
						if(false == visited[ny][nx])
						{
							score++;
							visited[ny][nx] = true;
						}
						break;
					}
					marking[ny][nx] = true;
					q.push({ny,nx});
				}
				if(true == find) break;
			}	
			if(true == find) break;
		}
	}

	for(int y = 0; y < 16; ++y)
	{
		for(int x = 0; x < 16; ++x)
		{
			if(true == visited[y][x])
			{
				map[y][x] = 0;
				visited[y][x] = false;
			}
		}
	}
	go();
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> d;

	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= m; ++x)
			cin >> src[y][x];
	
	std::vector<int> v(m,1);
	for(int i = 0; i < 3; ++i) v[i] = 0;

	int res = -1;
	do {
		score = 0;
		std::copy(&src[0][0], &src[15][16], &map[0][0]);
		std::fill(&visited[0][0], &visited[15][16], false);
		for(int i = 0; i < n; ++i)
			go(v);
		res = std::max(res, score);
	} while(std::next_permutation(v.begin(), v.end()));

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp